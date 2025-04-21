#include "sensor_module.h"

Sensor_Module::Sensor_Module(QObject *parent)
    : QObject{parent}
{}


void Sensor_Module::Sensor_Module_Start_Slot()
{
    emit Module_Ready();
}
