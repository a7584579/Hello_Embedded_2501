#include "actuator_module_handle.h"

Actuator_Module_Handle::Actuator_Module_Handle(QObject *parent)
    : QObject{parent}
{
    if (gpioInitialise() < 0) {
        qCritical() << "Failed to initialize pigpio!";
        exit(1);
    }

    // set gpio as output mode
    for (int pin : bumpPins) {
        gpioSetMode(pin, PI_OUTPUT);
        gpioWrite(pin, 0); // initialise to low voltage
    }
}

Actuator_Module_Handle::~Actuator_Module_Handle()
{
    // clear gpio
    for (int pin : bumpPins) {
        gpioWrite(pin, 0); // return to 0 voltage
        gpioSetMode(pin, PI_INPUT); // set as input mode
    }

    // gpio terminate
    gpioTerminate();
}

void Actuator_Module_Handle::startBumpThread(const int durations[4])
{
    QFuture<void> future = QtConcurrent::run(this, &Actuator_Module_Handle::controlBump, durations);
}

void Actuator_Module_Handle::startAudioThread(const QString &filePath)
{
    QFuture<void> future = QtConcurrent::run(this, &Actuator_Module_Handle::playSound, filePath);
}

void Actuator_Module_Handle::controlBump(const int durations[4])
{
    for (int i = 0; i < 4; ++i) {
        gpioWrite(bumpPins[i], 1); // start bump
        qDebug() << "Bump" << i + 1 << "activated for" << durations[i] << "ms";
        gpioDelay(durations[i] * 1000); // delay
        gpioWrite(bumpPins[i], 0); // close bump
    }

    qDebug() << "Bump control finished.";
}

void Actuator_Module_Handle::playSound(const QString &filePath)
{
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(filePath));

    QObject::connect(player, &QMediaPlayer::playbackStateChanged, [player](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            qDebug() << "Playback finished.";
            player->deleteLater();
        }
    });

    player->play();
    qDebug() << "Playing sound:" << filePath;
}