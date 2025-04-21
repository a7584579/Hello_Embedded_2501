#include "mainwindow.h"

#include <QApplication>


uint8_t stateMachineState;
uint8_t MachinePage;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}



void Public_Varaible_Init()
{
    stateMachineState=coffeeMachine_State_Startup;
}

uint8_t CurrentMachineState()
{
    return stateMachineState;
}

void ChangeCurrentMachineState(int state)
{
    stateMachineState=state;
}
