#include "audio_module_handle.h"

Audio_Module_Handle::Audio_Module_Handle(QObject *parent)
    : QObject{parent}
{}


void Audio_Module_Handle::Audio_Module_Start_Slot()
{
    emit Module_Ready();
}

class SpeakerThread : public QThread {
    public:
        SpeakerThread(const QString &path) : filePath(path) {}
    protected:
        void run() override {

            QString program = "ffplay";
            QStringList arguments;
            arguments << "-nodisp" << "-autoexit" << "-loglevel" << "quiet" << filePath;

            int result = QProcess::execute(program, arguments);
            if (result != 0) {
                std::cerr << "Audio playback process exited with code " << result << std::endl;
            }
            // run() end
        }
    private:
        QString filePath;  // MP4
};
    
// Audio_Module_Handle
Audio_Module_Handle::Audio_Module_Handle() : pumpThread(nullptr), speakerThread(nullptr) {}
    

Audio_Module_Handle::~Audio_Module_Handle() {

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
    // sound speaker start
void Audio_Module_Handle::startSpeakerThread(const QString &filePath) {

    if (speakerThread) {

        QObject::connect(speakerThread, &QThread::finished, speakerThread, &QObject::deleteLater);
        if (speakerThread->isRunning()) {
            qWarning("Speaker thread already running, skipping new start.");
            return;
        }
        speakerThread = nullptr;
    }

    SpeakerThread *thread = new SpeakerThread(filePath);
    speakerThread = thread;

    speakerThread->start();
}