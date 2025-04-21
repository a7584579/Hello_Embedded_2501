#ifndef ACTUATOR_MODULE_HANDLE_H
#define ACTUATOR_MODULE_HANDLE_H

#include <QObject>
#include <QThread>

#include <gpiod.h>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>



class Actuator_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Actuator_Module_Handle(QObject *parent = nullptr);


private:
    QMutex IO_Thread_Mutex;
    void IO_Write_Action();


public slots:
    void IO_Output(bool IO_State,unsigned char IO_Num);
    void Actuator_Module_Start_Slot();

signals:
    void IO_Action_Failed();
    void Module_Ready();
};

#endif // ACTUATOR_MODULE_HANDLE_H
