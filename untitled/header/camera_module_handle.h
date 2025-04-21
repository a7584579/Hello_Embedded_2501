#ifndef CAMERA_MODULE_HANDLE_H
#define CAMERA_MODULE_HANDLE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include "../quickopencv.h"


class Camera_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Camera_Module_Handle(QObject *parent = nullptr);

private:
    QTimer* Frame_Fresh_Timer;
    class quickopenCV* opencv_Instant;

public slots:
    void Camera_Fresh_Start_Slot();

private slots:
    void Camera_Frame_Fresh();

signals:
    void Module_Ready();
    void PicRead();
    void MoodStable(char);
};

#endif // CAMERA_MODULE_HANDLE_H
