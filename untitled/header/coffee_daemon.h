#ifndef COFFEE_DAEMON_H
#define COFFEE_DAEMON_H

#include <QObject>
#include <QThread>
#include "logger.h"
#include "header/InfraredSensor.h"
#include "actuator_module_handle.h"
#include "audio_module_handle.h"
#include "camera_module_handle.h"
#include "core_module_handle.h"
#include "sensor_module.h"

class CoffeeDaemon : public QObject
{
    Q_OBJECT

public:
    explicit CoffeeDaemon(QObject* parent = nullptr);
    ~CoffeeDaemon();

    void startDaemon();
    void stopDaemon();

signals:
    void stopRequested();

private slots:
    void run();
    void onDaemonThreadFinished();

private:
    void initializeModules();
    void setupSignals();

    QThread* daemonThread;
    bool isRunning;
};

#endif // COFFEE_DAEMON_H
