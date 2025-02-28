#include "audio_module_handle.h"
#include <QCoreApplication>
//test program
/*
Audio_Module_Handle::Audio_Module_Handle(QObject *parent)
    : QObject{parent}
{}
 */

 int main(int argc, char *argv[])
 {
    QCoreApplication a(argc, argv);

    Actuator_Module_Handle actuators;

    int bumpDurations[4] = {1000, 2000, 1500, 3000}; // test data

    // bump thread start
    actuators.startBumpThread(bumpDurations);

    // audio thread start
    actuators.startSpeakerThread("/path/to/test/music.mp4");

    // waiting for all tasks to complete
    QThread::waiting();

    // exit
    qDebug() << "All tasks completed. Exiting...";
    return a.exec();
 }