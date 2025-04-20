#include <csignal>
#include <iostream>
#include "daemon_utils.h"
#include "gpio_watcher.h"
#include "sensor_manager.h"
#include "face_recognition.h"
#include "pump_controller.h"
#include "speaker.h"
#include "touchscreen_ui.h"
#include "logger.h"

bool running = true;

void signalHandler(int sig) {
    running = false;
}

int main() {
    Logger::init(true);

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    Logger::log("Coffee daemon started.", INFO);


    SensorManager sensors;
    FaceRecognition faceRec;
    Speaker speaker;
    PumpController pump;
    TouchScreenUI ui;


    GPIOWatcher irSensor("gpiochip0", 17);


    irSensor.setCallback([&]() {
        Logger::log("Infrared sensor triggers event to start face recognition.", INFO);

        std::string user = faceRec.identify();
        if (!user.empty()) {
            Logger::log("Face recognition successful. Welcome." + user, INFO);
            speaker.say("Hello " + user + ", preparing your coffee.");

            if (sensors.checkVitals(user)) {
                Logger::log(user + "Heart rate and oximetry are normal.", INFO);
                ui.showMenu(user);
                pump.start(user);
                speaker.say("Enjoy your coffee." + user);
                Logger::log(user + "Coffee is ready.", INFO);
            } else {
                speaker.say("Vitals abnormal. Coffee cancelled.");
                Logger::log(user + "Abnormal heart rate or blood oxygen, cancel coffee brewing.", ERROR);
            }
        } else {
            speaker.say("Face not recognized.");
            Logger::log("Face recognition failed and the user was not recognized.", ERROR);
        }
    });

    irSensor.start();


    while (running) {
        pause();
    }

    Logger::log("Coffee daemon exiting", INFO);
    Logger::shutdown();
    return 0;
}

