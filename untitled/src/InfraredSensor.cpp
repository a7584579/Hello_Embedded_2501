#include "header/InfraredSensor.h"
#include <unistd.h>
#include <iostream>

InfraredSensor::InfraredSensor(QObject *parent)
    : QObject(parent), chip(nullptr), line(nullptr), notifier(nullptr), gpio_fd(-1) {
    chip = gpiod_chip_open_by_name("gpiochip0");
    if (!chip) {
        std::cerr << "Failed to open gpiochip0" << std::endl;
        return;
    }

    line = gpiod_chip_get_line(chip, 17);  // GPIO17
    if (!line) {
        std::cerr << "Failed to get GPIO line" << std::endl;
        gpiod_chip_close(chip);
        return;
    }

    if (gpiod_line_request_falling_edge_events(line, "infrared") != 0) {
        std::cerr << "Failed to request edge events" << std::endl;
        gpiod_chip_close(chip);
        return;
    }

    gpio_fd = gpiod_line_event_get_fd(line);
    notifier = new QSocketNotifier(gpio_fd, QSocketNotifier::Read, this);
    connect(notifier, &QSocketNotifier::activated, this, &InfraredSensor::onGpioEdge);
}

InfraredSensor::~InfraredSensor() {
    if (notifier) delete notifier;
    if (line) gpiod_line_release(line);
    if (chip) gpiod_chip_close(chip);
}

void InfraredSensor::startWatching() {
    if (notifier) notifier->setEnabled(true);
}

void InfraredSensor::onGpioEdge() {
    struct gpiod_line_event event;
    if (gpiod_line_event_read(line, &event) == 0) {
        std::cout << "[IR Sensor] Motion detected!" << std::endl;
        emit humanDetected();
    }
}
