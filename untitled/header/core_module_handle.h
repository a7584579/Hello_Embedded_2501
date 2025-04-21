#ifndef CORE_MODULE_HANDLE_H
#define CORE_MODULE_HANDLE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>

class Core_Module_Handle : public QThread
{
    Q_OBJECT
public:

    explicit Core_Module_Handle(QObject *parant)
    {
        parant_point=parant;
    }

    ~Core_Module_Handle()
    {
        ;
    }

private:
    QObject *parant_point;
    QTimer* Screen_Fresh_Timer;







public slots:
    void Core_Module_Run();

private slots:
    void Core_ScreenFresh_Slot();

signals:
    void User_GUI_Face_Pic_Fresh();
    void Test_GUI_Face_Pic_Fresh();
};

#endif // CORE_MODULE_HANDLE_H
