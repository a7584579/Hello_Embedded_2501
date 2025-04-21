#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <stdlib.h>
#include <QThread>
#include "camera_module_handle.h"
#include "actuator_module_handle.h"
#include "audio_module_handle.h"
#include "sensor_module.h"
#include <QMutex>

//Macro defination
#define INDEX_OF_READYPAGE                      0
#define INDEX_OF_PROCESSINGPAGE1_EMOTION        1
#define INDEX_OF_PROCESSINGPAGE2_PHYSICS        2
#define INDEX_OF_PROCESSINGPAGE3_FORMULA        3
#define INDEX_OF_PROCESSINGPAGE4_MAKING         4
#define INDEX_OF_MAINTAINPAGE                   5

#define INDEX_OF_INITPAGE                       6
#define INDEX_OF_ERRORINFOPAGE                  7

#define PUMP1_FOR_LIQUIDCOFFEE_GPIONUM      25
#define PUMP2_FOR_MILK_GPIONUM              24
#define PUMP3_FOR_LIQUIDSUGAR_GPIONUM       23
//#define PUMP4_FOR_RESERVE_GPIONUM    22


//Do not read this File,this file is for Camera thread only!!
#define REALTIME_PIC_PATH "/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/RealtimeVideo.png"
//Use this one instead
#define PUB_REALTIME_PIC_PATH "/home/cx/Desktop/LocalWorkSpace/embedded-courses/untitled/Pub_RealtimeVideo.png"

extern QMutex Access_for_Camera_Pic;//public mutex,based in camera_module
extern uint8_t stateMachineState;

extern void Public_Varaible_Init();
extern uint8_t CurrentMachineState();
extern void ChangeCurrentMachineState(int state);
extern uint8_t MachinePage;

extern int fd[2];//process comm
//write(fd[1],(void*)child.data(),child.length());
//read(fd[0],msg,sizeof(msg));

enum CoffeeMachine_State
{
    coffeeMachine_State_Startup,
    coffeeMachine_State_SelfCheck,
    coffeeMachine_State_Ready,
    coffeeMachine_State_Sleep,
    coffeeMachine_State_Processing,
    coffeeMachine_State_making,
};


class Public_Varaible
{

public:

    QThread Actuator_Module_Thread;
    QThread Camera_Module_Thread;

    QThread Audio_Module_Thread;
    QThread Sensor_Module_Thread;

    Camera_Module_Handle* Camera_Module_Instant=nullptr;
    Actuator_Module_Handle* Actuator_Module_Instant=nullptr;
    Audio_Module_Handle* Audio_Module_Instant=nullptr;
    Sensor_Module* Sensor_Module_Instant=nullptr;



private:
};




#endif // PUBLIC_VARIABLE_H
