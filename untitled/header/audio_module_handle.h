#ifndef AUDIO_MODULE_HANDLE_H
#define AUDIO_MODULE_HANDLE_H

#include <QObject>
#include <QThread>





class Audio_Module_Handle : public QObject
{
    Q_OBJECT
public:
    explicit Audio_Module_Handle(QObject *parent = nullptr);

public slots:
    void Audio_Module_Start_Slot();

signals:
    void Module_Ready();
};

#endif // AUDIO_MODULE_HANDLE_H
