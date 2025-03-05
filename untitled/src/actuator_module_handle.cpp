#include "actuator_module_handle.h"
#include <gpiod.h>      // libgpiod
#include <iostream>

// 内部类：水泵控制线程
class PumpThread : public QThread {
public:
    PumpThread(const std::array<int, 4>& durations)
        : pumpDurations(durations) {}
protected:
    void run() override {
        // 打开树莓派5的 GPIO 芯片
        struct gpiod_chip *chip = gpiod_chip_open_by_number(4);
        if (!chip) {
            std::cerr << "Failed to open GPIO chip" << std::endl;//没能打开GPIO芯片
            return;
        }

        // GPIO 引脚号和水泵
        int pumpPins[4] = {14, 15, 23, 24};
        struct gpiod_line *lines[4];

        // 每个引脚为输出 (初始化为低电平0)
        for (int i = 0; i < 4; ++i) {
            lines[i] = gpiod_chip_get_line(chip, pumpPins[i]);
            if (!lines[i] || gpiod_line_request_output(lines[i], "actuator", 0) < 0) {
                std::cerr << "Failed to request GPIO line " << pumpPins[i] << std::endl;
                // 如果失败释放已申请资源后退出
                for (int j = 0; j <= i; ++j) {
                    if (lines[j]) gpiod_line_release(lines[j]);
                }
                gpiod_chip_close(chip);
                return;
            }
        }

        // 将所有水蚌引脚置为高电平，启动水蚌
        for (int i = 0; i < 4; ++i) {
            gpiod_line_set_value(lines[i], 1);  // 设置引脚为高电平
        }

        // 计算每个水泵的关闭时间点，相对于启动时刻，ms单位制度
        // 蚌索引，主要用于让各个水泵并行运行，挨个运行太费时间
        struct PumpOffEvent { int offTime; int index; };
        PumpOffEvent offEvents[4];
        for (int i = 0; i < 4; ++i) {
            offEvents[i].offTime = pumpDurations[i];
            offEvents[i].index = i;
        }
        // 关闭时间升序排lie
        std::sort(offEvents, offEvents + 4, [](const PumpOffEvent &a, const PumpOffEvent &b) {
            return a.offTime < b.offTime;
        });

        // 按顺序等待各泵的关闭时间并依次关闭
        int currentTime = 0;
        for (int k = 0; k < 4; ++k) {
            int waitTime = offEvents[k].offTime - currentTime;
            if (waitTime > 0) {
                QThread::msleep(waitTime);  // 线程休眠等待到达下一个关闭时刻
            }
            currentTime = offEvents[k].offTime;
            int idx = offEvents[k].index;
            gpiod_line_set_value(lines[idx], 0);  // 将对应泵引脚置低电平，关闭水泵
        }

        // 释放 GPIO 资源
        for (int i = 0; i < 4; ++i) {
            gpiod_line_release(lines[i]);
        }
        gpiod_chip_close(chip);
        // 线程将腿出
    }
private:
    std::array<int, 4> pumpDurations;  // 保存四个水蚌的开启时长
};

// 内部类：音频播放线程
class SpeakerThread : public QThread {
public:
    SpeakerThread(const QString &path) : filePath(path) {}
protected:
    void run() override {
        // 使用 QProcess 执行 ffplay 播放音频
        // -nodisp：不显示视频画面；-autoexit：播放结束后自动退出
        /*
            todo：音频文件测试
        */
        QString program = "ffplay";
        QStringList arguments;
        arguments << "-nodisp" << "-autoexit" << "-loglevel" << "quiet" << filePath;
        // 同步执行外部进程并等待其结束
        int result = QProcess::execute(program, arguments);
        if (result != 0) {
            std::cerr << "Audio playback process exited with code " << result << std::endl;
        }
        // run() 结束，线程自动退出
    }
private:
    QString filePath;  // MP4 文件路径
};

// Actuator_Module_Handl
Actuator_Module_Handle::Actuator_Module_Handle()
    : pumpThread(nullptr), speakerThread(nullptr) {}

// 析构函数：确保清理线程对象
Actuator_Module_Handle::~Actuator_Module_Handle() {
    // 若线程还存在，先等待其结束再删除
    if (pumpThread) {
        pumpThread->wait();
        delete pumpThread;
        pumpThread = nullptr;
    }
    if (speakerThread) {
        speakerThread->wait();
        delete speakerThread;
        speakerThread = nullptr;
    }
}

// 启动水泵线程
void Actuator_Module_Handle::startPumpThread(const std::array<int, 4>& durations) {
    // 如果已有水泵线程在运行，先删除-测试功能，要改
    if (pumpThread) {
        pumpThread->wait();
        delete pumpThread;
    }
    // 创建新的水泵线程对象
    PumpThread *thread = new PumpThread(durations);
    pumpThread = thread;
    // 启动线程
    pumpThread->start();
}

// 启动音频线程
void Actuator_Module_Handle::startSpeakerThread(const QString &filePath) {
    if (speakerThread) {
        speakerThread->wait();
        delete speakerThread;
    }
    // 创建新的音频线程对象
    SpeakerThread *thread = new SpeakerThread(filePath);
    speakerThread = thread;
    // 启动线程
    speakerThread->start();
}

