#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtGlobal>

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

private:
    Ui::MainWindow *ui;

    void MainWindowButton_init();


private slots:
    //For Pushbutton slots
    void PushButton_Clicked_Slot();
    void PushButton2_Clicked_Slot();
    void PushButton3_Clicked_Slot();
    void PushButton4_Clicked_Slot();
    void PushButton5_Clicked_Slot();


    //For variable or widgt control
    void FaceReg_Image_Display_Tab2_Slot();
    void Heartrate_Image_Display_Tab3_Slot();


};
#endif // MAINWINDOW_H
