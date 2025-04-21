#ifndef INFRARED_SENSOR_H
#define INFRARED_SENSOR_H

#include <QObject>
#include <QSocketNotifier>
#include <gpiod.h>

class InfraredSensor : public QObject {
    Q_OBJECT

public:
    explicit InfraredSensor(QObject *parent = nullptr);
    ~InfraredSensor();
    void startWatching();

signals:
    void humanDetected();  // Trigger to detect signals from the human body

private slots:
    void onGpioEdge();

private:
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    QSocketNotifier* notifier;
    int gpio_fd;
};

#endif // INFRARED_SENSOR_H
