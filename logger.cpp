#include "logger.h"

QFile* Logger::logFile = nullptr;
QTextStream* Logger::stream = nullptr;
QMutex Logger::mutex;
bool Logger::logToFile = true;

void Logger::init(bool toFile) {
    QMutexLocker locker(&mutex);
    logToFile = toFile;
    if (toFile) {
        QString filename = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + "_log.txt";
        logFile = new QFile(filename);
        if (logFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
            stream = new QTextStream(logFile);
        }
    }
}

void Logger::log(const QString &message, LogLevel level) {
    QMutexLocker locker(&mutex);
    QString prefix;
    switch (level) {
        case INFO:    prefix = "[INFO] "; break;
        case WARNING: prefix = "[WARN] "; break;
        case ERROR:   prefix = "[ERROR]"; break;
    }

    QString logEntry = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") + " " + prefix + " " + message;

    if (logToFile && stream) {
        *stream << logEntry << "\n";
        stream->flush();
    }

    // Console fallback
    qDebug() << logEntry;
}

void Logger::shutdown() {
    QMutexLocker locker(&mutex);
    if (stream) {
        delete stream;
        stream = nullptr;
    }
    if (logFile) {
        logFile->close();
        delete logFile;
        logFile = nullptr;
    }
}
