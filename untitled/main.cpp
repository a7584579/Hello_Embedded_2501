/*
该文件为测试文件
#include <QCoreApplication>
#include "actuator_module_handle.h"

int main(int argc, char *argv[]) {

    
    
    // 初始化 Qt 核心应用，使用 QCoreApplication
    QCoreApplication app(argc, argv);

    // 定义四个水泵运行时间毫秒和音频文件路
    std::array<int, 4> pumpDurations = {1000, 2000, 3000, 4000};  // 每个水泵开启时间
    QString audioFile = "/home/pi/audio.mp4";  // 要播放音频的 MP4 文件路径

    // 创建执行器控制对象
    Actuator_Module_Handle actuator;
    // 启动水泵线程和音频线程
    actuator.startPumpThread(pumpDurations);
    actuator.startSpeakerThread(audioFile);

    // 等待两个线程都执行完毕
    if (actuator.pumpThread) {
        actuator.pumpThread->wait();  // 等待水泵线程结束
    }
    if (actuator.speakerThread) {
        actuator.speakerThread->wait();  // 等待音频线程结束
    }

    // 所有线程完成后退出
    return 0;
}*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

