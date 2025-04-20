#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <stdlib.h>
#include <QThread>
#include "camera_module_handle.h"
#include "actuator_module_handle.h"
#include "audio_module_handle.h"

//Macro defination
#define INDEX_OF_READYPAGE                      0
#define INDEX_OF_PROCESSINGPAGE1_EMOTION        1
#define INDEX_OF_PROCESSINGPAGE2_PHYSICS        2
#define INDEX_OF_PROCESSINGPAGE3_FORMULA        3
#define INDEX_OF_PROCESSINGPAGE4_MAKING         4
#define INDEX_OF_MAINTAINPAGE                   5

#define INDEX_OF_INITPAGE                       6
#define INDEX_OF_ERRORINFOPAGE                  7

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
    Camera_Module_Handle* Camera_Module_Instant=nullptr;
    Actuator_Module_Handle* Actuator_Module_Instant=nullptr;
    Audio_Module_Handle* Audio_Module_Instant=nullptr;


    Public_Varaible()
    {
        stateMachineState=coffeeMachine_State_Startup;
    }

    uint8_t CurrentMachineState()
    {
        return stateMachineState;
    }



private:
    uint8_t stateMachineState;
};


#endif // PUBLIC_VARIABLE_H
