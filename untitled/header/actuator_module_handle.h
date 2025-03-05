#ifndef ACTUATOR_MODULE_HANDLE_H
#define ACTUATOR_MODULE_HANDLE_H

#include <QThread>
#include <QProcess>
#include <array>
#include <QString>

// Actuator_Module_Handle提供执行器的控制接口
class Actuator_Module_Handle {
public:
    Actuator_Module_Handle();
    ~Actuator_Module_Handle();

    // 启动水泵控制线程，参数为四个水泵各自开启的时长（毫秒）
    void startPumpThread(const std::array<int, 4>& durations);
    // 启动音频播放线程，参数为要播放的MP4文件的那个路径
    void startSpeakerThread(const QString &filePath);

private:
    // 指向水泵和音频线程的指针
    QThread *pumpThread;
    QThread *speakerThread;
};

#endif // ACTUATOR_MODULE_HANDLE_H

