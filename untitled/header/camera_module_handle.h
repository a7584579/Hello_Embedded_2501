#ifndef CAMERA_MODULE_HANDLE_H
#define CAMERA_MODULE_HANDLE_H

#include <QObject>

class Camera_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Camera_Module_Handle(QObject *parent = nullptr);

signals:
};

#endif // CAMERA_MODULE_HANDLE_H
