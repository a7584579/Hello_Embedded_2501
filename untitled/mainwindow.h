#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtGlobal>
#include <QString>
#include <QTimer>
#include <QMutex>
#include <QMutexLocker>
#include "public_variable.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    char UI_CurrentPage();

private:
    Ui::MainWindow *ui;

    QTimer Dynamic_Init_Timer;
    int LoopRound=0;
    QTimer Init_Checking_Timer;
    class Public_Varaible Public_Varaible_Instant;


    QMutex Camera_Module_Ready;
    QMutex Actuator_Module_Ready;
    QMutex Audio_Module_Ready;
    QMutex Sensor_Module_Ready;
    void Init_Preparation();
    QMutex System_Ready;

    void Dynamic_Showing_Start();

    void Public_Variable_Init();
    void MainWindowButton_Init();
    void Camera_Module_Init();
    void Actuator_Module_Init();
    void Audio_Module_Init();
    void Sensor_Module_Init();




    void Core_Module_Init();





    //For test page
    int last_Page=-1;
    void Test_Page_Init();

    //Core
    QThread Core_Module_Thread;
    Core_Module_Handle* Core_Module_Instant=nullptr;


private slots:
    //For initiate page

    void Dynamic_showing_Timer_slot();
    void Dynamic_showing_Info_slot();
    void Dynamic_checkingComplete_slot();
    void Dynamic_checkingCompleteChange_slot();


    void Init_Finish_Check_Slot();


    //For self check failed info page
    void Failed_showing_Info_slot(QString text);


    //For Pushbutton slots
    void PushButton_Clicked_Slot();
    void PushButton2_Clicked_Slot();
    void PushButton3_Clicked_Slot();
    void PushButton4_Clicked_Slot();
    void PushButton5_Clicked_Slot();
    void PushButton6_Clicked_Slot();

    void PushButton8_Clicked_Slot();

    void Enter_Test_Page();
    void Quit_Test_Page();

    //For variable or widgt control
    void Heartrate_Image_Display_Tab3_Slot();



    //For test page
    void PushButton9_Clicked_Slot();//Pump IO check
    void PushButton15_Clicked_Slot();//override self check pass


public slots:
    //Module Ready slots
    void Camera_Module_Ready_Slot();
    void Actuator_Module_Ready_Slot();
    void Audio_Module_Ready_Slot();
    void Sensor_Module_Ready_Slot();


    //Freshing is charged by corethread
    void label_Pic_Show_slot();//Show realtime pic on user gui
    void test_Pic_Show_slot();//Show realtime pic on user gui

signals:
    //For camera init
    void Start_Camera_Fresh();
    void Start_Actuator();
    void Start_Audio();
    void Start_Sensor();

    //For state machine start
    void Core_Thread_Start();


    //For IO changing
    void IO_ChangeRequest(bool IO_State,unsigned char IO_Num);

};
#endif // MAINWINDOW_H
