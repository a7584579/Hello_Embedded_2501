#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    static void init(bool toFile = true);
    static void log(const QString &message, LogLevel level = INFO);
    static void shutdown();

private:
    static QFile *logFile;
    static QTextStream *stream;
    static QMutex mutex;
    static bool logToFile;
};

#endif // LOGGER_H
