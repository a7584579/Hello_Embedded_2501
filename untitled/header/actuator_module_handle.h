#ifndef ACTUATOR_MODULE_HANDLE_H
#define ACTUATOR_MODULE_HANDLE_H

#include <QObject>
#include <QThread>
#include <pigpio.h>
#include <QAudioOutput>
#include <QMediaPlayer>

class Actuator_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Actuator_Module_Handle(QObject *parent = nullptr);
    ~Actuator_Module_Handle();

    void startBumpThread(const int durations[4]); // bump start thread
    void startAudioThread(const QString &filePath); // audio start thread

private:
    QThread bumpThread;
    QThread audioThread;
    // bump control
    void controlBump(const int durations[4]);

    // audio control
    void playSound(const QString &filePath);

    // GPIO
    const int bumpPins[4] = {14, 15, 23, 24}; // bump used gpio

signals:
};

#endif // ACTUATOR_MODULE_HANDLE_H
