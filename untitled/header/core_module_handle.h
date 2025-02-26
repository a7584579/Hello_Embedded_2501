#ifndef CORE_MODULE_HANDLE_H
#define CORE_MODULE_HANDLE_H

#include <QObject>

class Core_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Core_Module_Handle(QObject *parent = nullptr);

signals:
};

#endif // CORE_MODULE_HANDLE_H
