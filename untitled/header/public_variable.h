#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <stdlib.h>
#include <QThread>


//Macro defination
#define INDEX_OF_READYPAGE                      0
#define INDEX_OF_PROCESSINGPAGE1_EMOTION        1
#define INDEX_OF_PROCESSINGPAGE2_PHYSICS        2
#define INDEX_OF_PROCESSINGPAGE3_FORMULA        3
#define INDEX_OF_PROCESSINGPAGE4_MAKING         4
#define INDEX_OF_MAINTAINPAGE                   5

enum CoffeeMachine_State
{
    coffeeMachine_State_Startup,
    coffeeMachine_State_SelfCheck,
    coffeeMachine_State_Ready,
    coffeeMachine_State_Sleep,
    coffeeMachine_State_Processing,
    coffeeMachine_State_making,
};

class Audio_Thread_Class: public QThread
{
public:
    Audio_Thread_Class()
    {
        ;
    }

    ~Audio_Thread_Class()
    {
        ;
    }

    void Audio_Thread_Run();

private:

};

class Actuator_Thread_Class: public QThread
{
public:
    Actuator_Thread_Class()
    {
        ;
    }

    ~Actuator_Thread_Class()
    {
        ;
    }

    void Actuator_Thread_Run();

private:

};

class Sensor_Thread_Class: public QThread
{
public:
    Sensor_Thread_Class()
    {
        ;
    }

    ~Sensor_Thread_Class()
    {
        ;
    }

    void Sensor_Thread_Run();

private:

};

class Camera_Thread_Class: public QThread
{
public:
    Camera_Thread_Class()
    {
        ;
    }

    ~Camera_Thread_Class()
    {
        ;
    }

    void Camera_Thread_Run();

private:

};

class Public_Varaible
{

public:

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
