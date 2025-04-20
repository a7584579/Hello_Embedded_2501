#ifndef CORE_MODULE_HANDLE_H
#define CORE_MODULE_HANDLE_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Core_Module_Handle : public QThread
{
    Q_OBJECT
public:

    explicit Core_Module_Handle()
    {
        ;
    }

    ~Core_Module_Handle()
    {
        ;
    }

signals:


public slots:
    void Core_Module_Run();
};

#endif // CORE_MODULE_HANDLE_H
