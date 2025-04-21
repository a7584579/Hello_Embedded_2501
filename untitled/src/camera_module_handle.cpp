#include "camera_module_handle.h"
#include "../quickopencv.h"
#include "public_variable.h"
#include <cstring>
#include <QFile>
#include <QMutex>

static int Init_Flag=0;
QMutex Access_for_Camera_Pic;

Camera_Module_Handle::Camera_Module_Handle(QObject *parent)
    : QObject{parent}
{
    opencv_Instant=new quickopenCV();
    Frame_Fresh_Timer=nullptr;
}


void Camera_Module_Handle::Camera_Frame_Fresh()
{
    //Frame_Fresh_Timer->stop();

    std::string path=REALTIME_PIC_PATH;
    opencv_Instant->picture_capture(path);

    if(Access_for_Camera_Pic.tryLock(5))
    {
        QFile Pub_File(PUB_REALTIME_PIC_PATH);
        if(Pub_File.exists())
        {
            Pub_File.remove();
        }
        if(!QFile::copy(REALTIME_PIC_PATH,PUB_REALTIME_PIC_PATH))
        {
            std::cout<<"copy failed";
        }
        Access_for_Camera_Pic.unlock();
        emit PicRead();
    }

    Frame_Fresh_Timer->start();
}


void Camera_Module_Handle::Camera_Fresh_Start_Slot()
{
    if(Init_Flag!=0)
    {
        return;//already being initialised
    }
    Frame_Fresh_Timer=new QTimer(this);
    Init_Flag=1;
    Frame_Fresh_Timer->setTimerType(Qt::CoarseTimer);
    Frame_Fresh_Timer->setInterval(20);
    connect(Frame_Fresh_Timer,SIGNAL(timeout()),this,SLOT(Camera_Frame_Fresh()));

    Frame_Fresh_Timer->setSingleShot(true);

    opencv_Instant->camera_preparation();

    Frame_Fresh_Timer->start();
    emit Module_Ready();
}

