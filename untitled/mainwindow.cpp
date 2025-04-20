#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //show initiate page
    Dynamic_Showing_Start();

    MainWindowButton_Init();

    //enter ready page

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Dynamic_Showing_Start()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_INITPAGE);
    Dynamic_Init_Timer.setSingleShot(true);
    Dynamic_Init_Timer.setTimerType(Qt::CoarseTimer);
    Dynamic_Init_Timer.setInterval(200);
    //Dynamic_Init_Timer.setParent(this);
    connect(&Dynamic_Init_Timer,SIGNAL(timeout()),this,SLOT(Dynamic_showing_Timer_slot()));
    Dynamic_Init_Timer.start();
}

void MainWindow::Dynamic_checkingComplete_slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_INITPAGE);
    Dynamic_Init_Timer.stop();
    ui->label_34->setText("Check Complete");
    ui->label_35->setText("");
    connect(&Dynamic_Init_Timer,SIGNAL(timeout()),this,SLOT(Dynamic_checkingCompleteChange_slot()));
    Dynamic_Init_Timer.setSingleShot(true);
    Dynamic_Init_Timer.setInterval(1000);
    Dynamic_Init_Timer.start();
}

void MainWindow::Dynamic_checkingCompleteChange_slot()
{
    Dynamic_Init_Timer.stop();
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
}

void MainWindow::Dynamic_showing_Timer_slot()
{
    int length=ui->label_35->text().length();
    QString ShowingString;
    ShowingString.clear();
    length=(length+1)%3;
    for(int i=0;i<length;i++)
    {
        ShowingString.append(".");
    }
    ui->label_35->setText(ShowingString);
    Dynamic_Init_Timer.start();
}

void MainWindow::Camera_Module_Init()
{
    Public_Varaible_Instant.Camera_Module_Instant=new Camera_Module_Handle();


}



void MainWindow::Actuator_Module_Init()
{

}



void MainWindow::MainWindowButton_Init()
{
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(PushButton_Clicked_Slot()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(PushButton2_Clicked_Slot()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(PushButton3_Clicked_Slot()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(PushButton4_Clicked_Slot()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(PushButton5_Clicked_Slot()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(PushButton6_Clicked_Slot()));

    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Quit_Test_Page()));

    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(PushButton8_Clicked_Slot()));


    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(PushButton15_Clicked_Slot()));

    connect(ui->actionEnter_test_mode,SIGNAL(triggered()),this,SLOT(Enter_Test_Page()));

}





void MainWindow::Dynamic_showing_Info_slot()
{

}

void MainWindow::Failed_showing_Info_slot(QString text)
{

}

void MainWindow::PushButton_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE1_EMOTION);
}

void MainWindow::PushButton2_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE2_PHYSICS);
}

void MainWindow::PushButton3_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE3_FORMULA);
}

void MainWindow::PushButton8_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE4_MAKING);
}

void MainWindow::PushButton4_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
}


void MainWindow::PushButton5_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
}

void MainWindow::PushButton6_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
}



void MainWindow::PushButton15_Clicked_Slot()//override self check pass
{
    Dynamic_checkingComplete_slot();
}



void MainWindow::Enter_Test_Page()
{
    last_Page=ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(INDEX_OF_MAINTAINPAGE);
}

void MainWindow::Quit_Test_Page()
{
    ui->tabWidget->setCurrentIndex(last_Page);
}

void MainWindow::FaceReg_Image_Display_Tab2_Slot()
{

}

void MainWindow::Heartrate_Image_Display_Tab3_Slot()
{
    ui->label_2->setText("100");
}
