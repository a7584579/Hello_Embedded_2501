#include <QCoreApplication>
#include <csignal>
#include <iostream>

#include "logger.h"
#include "infrared_sensor.h"
#include "actuator_module_handle.h"
#include "audio_module_handle.h"
#include "camera_module_handle.h"
#include "core_module_handle.h"
#include "sensor_module.h"

QCoreApplication* app_ptr = nullptr;

void signalHandler(int sig) {
    Logger::log("Signal received, shutting down", WARNING);
    if (app_ptr) app_ptr->quit();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    app_ptr = &app;

    Logger::init(true);
    Logger::log("Coffee Daemon starting", INFO);

    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);


    auto actuator = new Actuator_Module_Handle();
    auto audio = new Audio_Module_Handle();
    auto camera = new Camera_Module_Handle();
    auto core = new Core_Module_Handle();
    auto sensor = new Sensor_Module();
    auto irSensor = new InfraredSensor();// Initialization Module

    actuator->Actuator_Module_Start_Slot();
    audio->Audio_Module_Start_Slot();
    camera->Camera_Fresh_Start_Slot();
    core->Core_Module_Run();
    sensor->Sensor_Module_Start_Slot();
    irSensor->startWatching();// start module

    QObject::connect(irSensor, &InfraredSensor::humanDetected, [&]() {
        Logger::log("Human proximity is detected, triggering the recognition process", INFO);

        audio->say("Welcome! Please look at the camera.");

    });

    int result = app.exec();
    Logger::log("Coffee Daemon exiting", INFO);
    Logger::shutdown();
    return result;
}
