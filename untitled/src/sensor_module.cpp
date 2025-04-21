#include "sensor_module.h"


#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <sys/ioctl.h>


Sensor_Module::Sensor_Module(QObject *parent)
    : QObject{parent}
{}


void Sensor_Module::Sensor_Module_Start_Slot()
{
    emit Module_Ready();
}
