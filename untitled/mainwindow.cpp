#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QPicture>
#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Init_Preparation();
    ui->setupUi(this);
    //show initiate page
    Dynamic_Showing_Start();

    Public_Variable_Init();
    MainWindowButton_Init();
    Camera_Module_Init();
    Actuator_Module_Init();
    Audio_Module_Init();
    Sensor_Module_Init();


    Test_Page_Init();


    //enter ready page check
    Init_Checking_Timer.setTimerType(Qt::CoarseTimer);
    Init_Checking_Timer.setSingleShot(true);
    Init_Checking_Timer.setInterval(50);
    Init_Checking_Timer.start();
    connect(&Init_Checking_Timer,SIGNAL(timeout()),this,SLOT(Init_Finish_Check_Slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


char MainWindow::UI_CurrentPage()
{
    if(!System_Ready.tryLock())
    {
        return ui->tabWidget->currentIndex();
    }
    else
    {
        System_Ready.unlock();
    }
    return 0xff;
}

void MainWindow::Init_Preparation()
{
    if(Camera_Module_Ready.tryLock(5))
    {
        Camera_Module_Ready.unlock();
    }
    else
    {
        Camera_Module_Ready.unlock();
    }


    if(Actuator_Module_Ready.tryLock(5))
    {
        Actuator_Module_Ready.unlock();
    }
    else
    {
        Actuator_Module_Ready.unlock();
    }


    if(Audio_Module_Ready.tryLock(5))
    {
        Audio_Module_Ready.unlock();
    }
    else
    {
        Audio_Module_Ready.unlock();
    }

    if(Sensor_Module_Ready.tryLock(5))
    {
        Sensor_Module_Ready.unlock();
    }
    else
    {
        Sensor_Module_Ready.unlock();
    }

    if(System_Ready.tryLock(5))
    {
        System_Ready.unlock();
    }
    else
    {
        System_Ready.unlock();
    }


    ChangeCurrentMachineState(coffeeMachine_State_SelfCheck);
}

void MainWindow::Dynamic_Showing_Start()
{
    last_Page=ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(INDEX_OF_INITPAGE);
    MachinePage=INDEX_OF_INITPAGE;
    Dynamic_Init_Timer.setSingleShot(true);
    Dynamic_Init_Timer.setTimerType(Qt::CoarseTimer);
    Dynamic_Init_Timer.setInterval(200);
    //Dynamic_Init_Timer.setParent(this);
    connect(&Dynamic_Init_Timer,SIGNAL(timeout()),this,SLOT(Dynamic_showing_Timer_slot()));
    Dynamic_Init_Timer.start();
}

void MainWindow::Dynamic_checkingComplete_slot()
{
    last_Page=ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(INDEX_OF_INITPAGE);
    MachinePage=INDEX_OF_INITPAGE;
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
    MachinePage=INDEX_OF_READYPAGE;
    ChangeCurrentMachineState(coffeeMachine_State_Ready);
    stateMachineState=coffeeMachine_State_Ready;
    System_Ready.tryLock();
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

void MainWindow::Init_Finish_Check_Slot()
{
    int IS_Every_Module_Ready=true;


    if(!Camera_Module_Ready.tryLock())
    {
        IS_Every_Module_Ready++;
    }
    else
    {
        Camera_Module_Ready.unlock();
    }

    if(!Actuator_Module_Ready.tryLock())
    {
        IS_Every_Module_Ready++;
    }
    else
    {
        Actuator_Module_Ready.unlock();
    }

    if(!Audio_Module_Ready.tryLock())
    {
        IS_Every_Module_Ready++;
    }
    else
    {
        Audio_Module_Ready.unlock();
    }

    if(!Sensor_Module_Ready.tryLock())
    {
        IS_Every_Module_Ready++;
    }
    else
    {
        Sensor_Module_Ready.unlock();
    }


    if(IS_Every_Module_Ready>=4)
    {
        Dynamic_checkingComplete_slot();
        Init_Checking_Timer.stop();
        return ;
    }

    if(LoopRound>60)
    {
        Dynamic_Init_Timer.stop();
        ui->label_34->setGeometry(250,270,600,45);
        ui->label_34->setText("Initialising failed, contact your maintainer");
        ui->label_35->setText("");
    }
    else
    {
        LoopRound++;
    }
    Init_Checking_Timer.start();
}

void MainWindow::Public_Variable_Init()
{
    if(Access_for_Camera_Pic.tryLock())
    {
        Access_for_Camera_Pic.unlock();
    }
    else
    {
        Access_for_Camera_Pic.unlock();
    }
}



void MainWindow::Camera_Module_Init()
{
    Public_Varaible_Instant.Camera_Module_Instant=new Camera_Module_Handle();
    Public_Varaible_Instant.Camera_Module_Instant->moveToThread(&Public_Varaible_Instant.Camera_Module_Thread);

    connect(this,SIGNAL(Start_Camera_Fresh()),Public_Varaible_Instant.Camera_Module_Instant,SLOT(Camera_Fresh_Start_Slot()));
    connect(Public_Varaible_Instant.Camera_Module_Instant,SIGNAL(Module_Ready()),this,SLOT(Camera_Module_Ready_Slot()));

    connect(Public_Varaible_Instant.Camera_Module_Instant,SIGNAL(PicRead()),this,SLOT(label_Pic_Show_slot()));
    connect(Public_Varaible_Instant.Camera_Module_Instant,SIGNAL(PicRead()),this,SLOT(test_Pic_Show_slot()));

    connect(Public_Varaible_Instant.Camera_Module_Instant,SIGNAL(MoodStable(char)),this,SLOT(Mood_Judge_slot(char)));


    if(!Public_Varaible_Instant.Camera_Module_Thread.isRunning())
    {
        qDebug()<<"Camera_Module_Thread started";
        Public_Varaible_Instant.Camera_Module_Thread.start();
    }
    emit Start_Camera_Fresh();
}


void MainWindow::Actuator_Module_Init()
{
    Public_Varaible_Instant.Actuator_Module_Instant=new Actuator_Module_Handle();
    Public_Varaible_Instant.Actuator_Module_Instant->moveToThread(&Public_Varaible_Instant.Actuator_Module_Thread);

    connect(this,SIGNAL(IO_ChangeRequest(bool,uchar)),Public_Varaible_Instant.Actuator_Module_Instant,SLOT(IO_Output(bool,uchar)));

    connect(this,SIGNAL(Start_Actuator()),Public_Varaible_Instant.Actuator_Module_Instant,SLOT(Actuator_Module_Start_Slot()));
    connect(Public_Varaible_Instant.Actuator_Module_Instant,SIGNAL(Module_Ready()),this,SLOT(Actuator_Module_Ready_Slot()));

    if(!Public_Varaible_Instant.Actuator_Module_Thread.isRunning())
    {
        qDebug()<<"Actuator_Module_Thread started";
        Public_Varaible_Instant.Actuator_Module_Thread.start();
    }
    emit Start_Actuator();
}

void MainWindow::Audio_Module_Init()
{
    Public_Varaible_Instant.Audio_Module_Instant=new Audio_Module_Handle();
    Public_Varaible_Instant.Audio_Module_Instant->moveToThread(&Public_Varaible_Instant.Audio_Module_Thread);

    connect(this,SIGNAL(Start_Audio()),Public_Varaible_Instant.Audio_Module_Instant,SLOT(Audio_Module_Start_Slot()));
    connect(Public_Varaible_Instant.Audio_Module_Instant,SIGNAL(Module_Ready()),this,SLOT(Audio_Module_Ready_Slot()));

    if(!Public_Varaible_Instant.Audio_Module_Thread.isRunning())
    {
        qDebug()<<"Audio_Module_Thread started";
        Public_Varaible_Instant.Audio_Module_Thread.start();
    }
    emit Start_Audio();
}


void MainWindow::Sensor_Module_Init()
{
    Public_Varaible_Instant.Sensor_Module_Instant=new Sensor_Module();
    Public_Varaible_Instant.Sensor_Module_Instant->moveToThread(&Public_Varaible_Instant.Sensor_Module_Thread);

    connect(this,SIGNAL(Start_Sensor()),Public_Varaible_Instant.Sensor_Module_Instant,SLOT(Sensor_Module_Start_Slot()));
    connect(Public_Varaible_Instant.Sensor_Module_Instant,SIGNAL(Module_Ready()),this,SLOT(Sensor_Module_Ready_Slot()));



    if(!Public_Varaible_Instant.Sensor_Module_Thread.isRunning())
    {
        qDebug()<<"Sensor_Module_Thread started";
        Public_Varaible_Instant.Sensor_Module_Thread.start();
    }
    emit Start_Sensor();
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

    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(PushButton12_Clicked_Slot()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(PushButton15_Clicked_Slot()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(PushButton17_Clicked_Slot()));

    connect(ui->actionEnter_test_mode,SIGNAL(triggered()),this,SLOT(Enter_Test_Page()));

}


void MainWindow::Test_Page_Init()
{
    ui->comboBox->addItem("PUMP1_LIQUIDCOFFEE");
    ui->comboBox->addItem("PUMP2_MILK");
    ui->comboBox->addItem("PUMP3_SUGAR");


    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(PushButton9_Clicked_Slot()));

}



void MainWindow::Dynamic_showing_Info_slot()
{

}

void MainWindow::Failed_showing_Info_slot(QString text)
{

}

void MainWindow::PushButton_Clicked_Slot()
{
    ui->label_41->setText("-");
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE1_EMOTION);
    MachinePage=INDEX_OF_PROCESSINGPAGE1_EMOTION;
    stateMachineState=coffeeMachine_State_Processing;

}

void MainWindow::PushButton2_Clicked_Slot()
{
    ui->label_44->setText("-");
    ui->label_45->setText("-");
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE2_PHYSICS);
    MachinePage=INDEX_OF_PROCESSINGPAGE2_PHYSICS;
    stateMachineState=coffeeMachine_State_Processing;
}

void MainWindow::PushButton3_Clicked_Slot()
{

    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE3_FORMULA);
    MachinePage=INDEX_OF_PROCESSINGPAGE3_FORMULA;
    stateMachineState=coffeeMachine_State_Processing;
}

void MainWindow::PushButton8_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE4_MAKING);
    MachinePage=INDEX_OF_PROCESSINGPAGE4_MAKING;
    stateMachineState=coffeeMachine_State_making;
}

void MainWindow::PushButton12_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_PROCESSINGPAGE4_MAKING);
    MachinePage=INDEX_OF_PROCESSINGPAGE4_MAKING;
    stateMachineState=coffeeMachine_State_making;
}

void MainWindow::PushButton4_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
    MachinePage=INDEX_OF_READYPAGE;
    stateMachineState=coffeeMachine_State_Ready;
}


void MainWindow::PushButton5_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
    MachinePage=INDEX_OF_READYPAGE;
    stateMachineState=coffeeMachine_State_Ready;
}

void MainWindow::PushButton6_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
    MachinePage=INDEX_OF_READYPAGE;
    stateMachineState=coffeeMachine_State_Ready;
}

void MainWindow::PushButton17_Clicked_Slot()
{
    ui->tabWidget->setCurrentIndex(INDEX_OF_READYPAGE);
    MachinePage=INDEX_OF_READYPAGE;
    stateMachineState=coffeeMachine_State_Ready;
}


void MainWindow::PushButton9_Clicked_Slot()//Pump IO check
{
    int currentIndexofIO=ui->comboBox->currentIndex();
    unsigned char IO_needtoAct=0;
    bool IO_ReqState=false;

    if(ui->radioButton->isChecked())
    {
        //output
        switch (currentIndexofIO) {
        case 0:
            IO_needtoAct=PUMP1_FOR_LIQUIDCOFFEE_GPIONUM;
            break;
        case 1:
            IO_needtoAct=PUMP2_FOR_MILK_GPIONUM;
            break;
        case 2:
            IO_needtoAct=PUMP3_FOR_LIQUIDSUGAR_GPIONUM;
            break;
        default:return;
        }
        if(ui->radioButton_5->isChecked())IO_ReqState=1;
        else IO_ReqState=0;
    }
    emit IO_ChangeRequest(IO_ReqState,IO_needtoAct);

}

void MainWindow::PushButton15_Clicked_Slot()//override self check pass
{
    Dynamic_checkingComplete_slot();
}



void MainWindow::Enter_Test_Page()
{
    if(ui->tabWidget->currentIndex()==INDEX_OF_MAINTAINPAGE)goto end;
    last_Page=ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(INDEX_OF_MAINTAINPAGE);

    end:
    MachinePage=INDEX_OF_MAINTAINPAGE;
}

void MainWindow::Quit_Test_Page()
{
    ui->tabWidget->setCurrentIndex(last_Page);
    MachinePage=last_Page;
}


void MainWindow::Camera_Module_Ready_Slot()
{
    Camera_Module_Ready.tryLock();
}

void MainWindow::Actuator_Module_Ready_Slot()
{
    Actuator_Module_Ready.tryLock();
}

void MainWindow::Audio_Module_Ready_Slot()
{
    Audio_Module_Ready.tryLock();
}

void MainWindow::Sensor_Module_Ready_Slot()
{
    Sensor_Module_Ready.tryLock();
}


void MainWindow::Mood_Judge_slot(char mood_Value)//Show realtime pic on user gui
{
    if(mood_Value>50)ui->label_41->setText("happy");
    else ui->label_41->setText("unhappy");
}

void MainWindow::label_Pic_Show_slot()//Show realtime pic on user gui
{
    if((CurrentMachineState()==coffeeMachine_State_Processing) && (ui->tabWidget->currentIndex()==INDEX_OF_PROCESSINGPAGE1_EMOTION))
    {
        QImage image;
        //image.load(PUB_REALTIME_PIC_PATH);
        if(Access_for_Camera_Pic.tryLock(5))
        {
            image.load(PUB_REALTIME_PIC_PATH);
            Access_for_Camera_Pic.unlock();
        }
        if(image.isNull())
        {
            //qDebug()<<"image read failed";
            return ;
        }

        QPixmap input;
        input.convertFromImage(image);
        input.scaled(500,400);

        ui->label->setPixmap(input);
    }
}

void MainWindow::test_Pic_Show_slot()//Show realtime pic on test page
{
    if( ui->tabWidget->currentIndex()==INDEX_OF_MAINTAINPAGE)
    {
        QImage image;
        //image.load(PUB_REALTIME_PIC_PATH);
        if(Access_for_Camera_Pic.tryLock(5))
        {
            image.load(PUB_REALTIME_PIC_PATH);
            Access_for_Camera_Pic.unlock();
        }
        if(image.isNull())
        {
            //qDebug()<<"image read failed";
            return ;
        }

        QPixmap input;
        input.convertFromImage(image);
        input.scaled(300,200,Qt::IgnoreAspectRatio);

        ui->label_25->setPixmap(input);
    }
}

void MainWindow::Heartrate_Image_Display_Tab3_Slot()
{
    ui->label_2->setText("70");
}

void SensorMonitorThread::run() {
    char buffer[1];
    while (true) {
        ssize_t n = read(readFd, buffer, 1);
        if (n > 0) {
            if (buffer[0] == '1') {
                emit personDetected();
            } else if (buffer[0] == '0') {
                emit noPersonDetected();
            }
        }
        msleep(200);
    }
}

void MainWindow::setupSensorMonitor() {
    sensorThread = new SensorMonitorThread(readFd, this);
    connect(sensorThread, &SensorMonitorThread::personDetected, this, &MainWindow::onPersonDetected);
    connect(sensorThread, &SensorMonitorThread::noPersonDetected, this, &MainWindow::onNoPersonDetected);
    sensorThread->start();

    sleepTimer = new QTimer(this);
    sleepTimer->setInterval(30000); // 30 秒
    connect(sleepTimer, &QTimer::timeout, this, &MainWindow::enterSleepMode);
}

void MainWindow::onPersonDetected() {
    if (stateMachineState == coffeeMachine_State_Sleep) {
        stateMachineState = coffeeMachine_State_Startup;
        qDebug() << "Waking up...";
    }
    sleepTimer->stop(); 
}

void MainWindow::onNoPersonDetected() {
    if (!sleepTimer->isActive())
        sleepTimer->start(); 
}

void MainWindow::enterSleepMode() {
    stateMachineState = coffeeMachine_State_Sleep;
    qDebug() << "Entering sleep mode.";
}

void gpio_monitor(int writeFd) {
    const char* chipname = "gpiochip0";
    const int line_num = 6;

    gpiod_chip* chip = gpiod_chip_open_by_name(chipname);
    gpiod_line* line = gpiod_chip_get_line(chip, line_num);
    gpiod_line_request_input(line, "gpio_monitor");

    int lastVal = -1;
    while (true) {
        int val = gpiod_line_get_value(line);
        if (val != lastVal) {
            char msg = val ? '1' : '0';
            write(writeFd, &msg, 1);
            lastVal = val;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    gpiod_line_release(line);
    gpiod_chip_close(chip);
}