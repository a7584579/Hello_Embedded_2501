#include "actuator_module_handle.h"

//copy from public_variable
#define PUMP1_FOR_LIQUIDCOFFEE_GPIONUM      25
#define PUMP2_FOR_MILK_GPIONUM              24
#define PUMP3_FOR_LIQUIDSUGAR_GPIONUM       23

#define GPIO_LIB_SOLVED

static int IO_NeedtoAct=0;
static bool IO_NeedtoState=0;

Actuator_Module_Handle::Actuator_Module_Handle(QObject *parent)
    : QObject{parent}
{
#ifdef GPIO_LIB_SOLVED
    IO_NeedtoAct=PUMP3_FOR_LIQUIDSUGAR_GPIONUM;IO_Write_Action();
    IO_NeedtoAct=PUMP2_FOR_MILK_GPIONUM;IO_Write_Action();
    IO_NeedtoAct=PUMP1_FOR_LIQUIDCOFFEE_GPIONUM;IO_Write_Action();
#endif
}

void Actuator_Module_Handle::IO_Output(bool IO_State,unsigned char IO_Num)
{
    #ifdef GPIO_LIB_SOLVED
    if(IO_Thread_Mutex.try_lock())
    {
        switch(IO_Num)
        {
        case PUMP1_FOR_LIQUIDCOFFEE_GPIONUM:
        {
            IO_NeedtoAct=PUMP1_FOR_LIQUIDCOFFEE_GPIONUM;
            IO_NeedtoState=IO_State;
            break;
        }

        case PUMP2_FOR_MILK_GPIONUM:
        {
            IO_NeedtoAct=PUMP2_FOR_MILK_GPIONUM;
            IO_NeedtoState=IO_State;
            break;
        }
        case PUMP3_FOR_LIQUIDSUGAR_GPIONUM:
        {
            IO_NeedtoAct=PUMP3_FOR_LIQUIDSUGAR_GPIONUM;
            IO_NeedtoState=IO_State;
            break;
        }
        default:IO_Thread_Mutex.unlock();break;
        }
        IO_Write_Action();
    }
    else
    {
        qDebug("IO Thread not ready");
    }
    #endif
}

void Actuator_Module_Handle::IO_Write_Action()
{
    #ifdef GPIO_LIB_SOLVED
    int IO_Num=IO_NeedtoAct;
    struct gpiod_line * line=nullptr;
    struct gpiod_chip *chip=gpiod_chip_open_by_number(0);

    if(nullptr==chip)
    {
        emit IO_Action_Failed();
        goto end;
    }

    line=gpiod_chip_get_line(chip,IO_Num);
    if(nullptr==line)
    {
        gpiod_chip_close(chip);
        emit IO_Action_Failed();
        goto end;
    }

    if(0!=gpiod_line_request_output(line,"Coffee",IO_NeedtoState))
    {
        gpiod_chip_close(chip);
        gpiod_line_release(line);
        emit IO_Action_Failed();
        goto end;
    }

    gpiod_line_set_value(line,IO_NeedtoState);

    gpiod_line_release(line);
    gpiod_chip_close(chip);
    if(!IO_Thread_Mutex.try_lock())
    {
        IO_Thread_Mutex.unlock();
    }
    else
    {
        IO_Thread_Mutex.unlock();
    }

end:
    return ;
    #endif
}


void Actuator_Module_Handle::Actuator_Module_Start_Slot()
{
    emit Module_Ready();
}


