#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindowButton_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MainWindowButton_init()
{
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(PushButton_Clicked_Slot()));
}




void MainWindow::PushButton_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(1);
}
