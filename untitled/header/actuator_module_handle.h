#ifndef ACTUATOR_MODULE_HANDLE_H
#define ACTUATOR_MODULE_HANDLE_H

#include <QObject>
#include <QThread>





class Actuator_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Actuator_Module_Handle(QObject *parent = nullptr);

signals:
};

#endif // ACTUATOR_MODULE_HANDLE_H
