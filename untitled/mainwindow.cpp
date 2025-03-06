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
}



void MainWindow::PushButton_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::PushButton2_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::PushButton3_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(3);
}


void MainWindow::PushButton4_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(0);
}


void MainWindow::PushButton5_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::PushButton6_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::FaceReg_Image_Display_Tab2_Slot()
{

}

void MainWindow::Heartrate_Image_Display_Tab3_Slot()
{
    ui->label_2->setText("100");
}
