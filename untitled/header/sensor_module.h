#ifndef SENSOR_MODULE_H
#define SENSOR_MODULE_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Sensor_Module : public QObject
{
    Q_OBJECT
public:
    explicit Sensor_Module(QObject *parent = nullptr);

    uint8_t HeartbeatValueHandle();
    uint8_t SP2O_ValueHandle();
    uint8_t SelfCheckHandle();
signals:
};

#endif // SENSOR_MODULE_H
