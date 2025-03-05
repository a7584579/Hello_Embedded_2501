#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <stdlib.h>
#include <QThread>
#include "sensor_module.h"

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
    Sensor_Thread_Class(QObject* parent = nullptr): QThread(parent), sensorModule(new Sensor_Module())
    {
        //review comment
        //added by cx250305
        /*
         * To coder
         * added by cx250305
         *
         * QThread:no need for initialise QThread
         *
         * why choose to inherit Sensor_Module and use point
         *
         * */

        sensorModule->moveToThread(this);
        //To tester and codeviewer need to confirm Sensor_Thread_Class->start() works normally
        //added by cx250305
        /*
         * added by cx250305
         * Warning: This function is not thread-safe;
         * the current thread must be same as the current thread affinity.
         * In other words, this function can only "push" an object from the current thread to another thread,
         * it cannot "pull" an object from any arbitrary thread to the current thread.
         * There is one exception to this rule however:
         * objects with no thread affinity can be "pulled" to the current thread
         * */
    }

    ~Sensor_Thread_Class()
    {
        quit();
        /*
         *added by cx250305
         *Tells the thread's event loop to exit with return code 0 (success).
         *Equivalent to calling QThread::exit(0).This function does nothing if the thread
         *does not have an event loop
         *
         *
         *
         */

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
    //
    {
        exec();
        /*
         * exec()
         *
         * This function is meant to be called from within run().
         * It is necessary to call this function to start event handling.
         *
         * Note: This can only be called within the thread itself, i.e. when it is the current thread.
         */
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
