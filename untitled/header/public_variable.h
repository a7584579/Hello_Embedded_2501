#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <stdlib.h>
#include <QThread>
#include "Sensor_Module.h"

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

class Sensor_Thread_Class : public QThread
{
public:
    Sensor_Thread_Class(QObject* parent = nullptr)
        : QThread(parent), sensorModule(new Sensor_Module())
    {
        sensorModule->moveToThread(this);
    }

    ~Sensor_Thread_Class()
    {
        quit();
        wait();
        delete sensorModule;
    }

    uint8_t HeartbeatValueHandle()
    {
        return sensorModule->HeartbeatValueHandle();
    }

    uint8_t SPO2_ValueHandle()
    {
        return sensorModule->SPO2_ValueHandle();
    }
	uint8_t SelfCheckHandle()
    {
        return sensorModule->SelfCheckHandle();
    }

protected:
    void run() override
    {
        exec();
    }

private:
    Sensor_Module* sensorModule;
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

class Core_Thread_Class: public QThread
{
public:
    Core_Thread_Class()
    {
        ;
    }

    ~Core_Thread_Class()
    {
        ;
    }

    void Core_Thread_Run();

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