#include "mainwindow.h"

#include <QApplication>
#include <stdio.h>
#include <sys/epoll.h>
#include <functional>
#include <chrono>
#include <set>
#include <memory>
#include <iostream>


#include <gpiod.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <cstring>

#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

#include <QTimer>//due to the reanson(c++ doesn't implement timer)
#include <QThread>
uint8_t stateMachineState;
uint8_t MachinePage;
int fd[2];


int main(int argc, char *argv[])
{
    int QT_Runing_Indicator=0;

    int ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error\n");
        return -1;
    }

    pid_t id=fork();
    if(id==0)
    {
        int i=0;

        QApplication a(argc, argv);
        MainWindow w;

        w.setupSensorMonitor(fd[0]);
        
        w.show();
        a.exec();

    }
    else if(id>0)
    {
        std::thread gpioThread(gpio_monitor, fd[1]);
        gpioThread.detach();

    }
    else
    {
        perror("fork error\n");
        return -1;
    }
    return 0;
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