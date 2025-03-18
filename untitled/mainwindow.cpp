#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindowButton_Init();
    CoffeeMaker_Module_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CoffeeMaker_Module_Init()
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

    connect(ui->actionEnter_test_mode,SIGNAL(triggered()),this,SLOT(Enter_Test_Page()));

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
