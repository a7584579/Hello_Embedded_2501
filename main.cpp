#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "sensor_module.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create an instance of the Sensor Module
    Sensor_Module sensor;

    // Define a timer to query the heart rate and blood oxygen once per second
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&sensor]() {
        uint8_t heartRate = sensor.HeartbeatValueHandle();
        uint8_t spo2 = sensor.SPO2_ValueHandle();
        uint8_t selfCheck = sensor.SelfCheckHandle();

        qDebug() << "Heart Rate:" << heartRate
                 << "SpO2:" << spo2
                 << "Self Check Result:" << (selfCheck == 0x00 ? "Success" : "Failed");
    });

    // Start the timer and trigger it once every 1000ms (1 second)
    timer.start(1000);

    // Run the Qt event loop
    return a.exec();
}
