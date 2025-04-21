#ifndef TESTER_H
#define TESTER_H

#include <QObject>

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(QObject *parent = nullptr);

signals:
};

#endif // TESTER_H
