#ifndef AUDIO_MODULE_HANDLE_H
#define AUDIO_MODULE_HANDLE_H

#include <QObject>
#include <QThread>





class Audio_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Audio_Module_Handle(QObject *parent = nullptr);
    void startSpeakerThread(const QString &filePath);

public slots:
    void Audio_Module_Start_Slot(); // start the thread of audio-play, the parameter is the path of MP4 file which could be played.

signals:
    void Module_Ready();

private:
//point of audio thread.
    QThread *speakerThread;
    QString filePath;  // MP4

};

#endif // AUDIO_MODULE_HANDLE_H
