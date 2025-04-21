#include "coffee_daemon.h"
#include <QCoreApplication>

CoffeeDaemon::CoffeeDaemon(QObject* parent)
    : QObject(parent), daemonThread(nullptr), isRunning(false)
{
    Logger::init(true);
    Logger::log("Coffee Daemon initialized", INFO);
}

CoffeeDaemon::~CoffeeDaemon()
{
    if (isRunning) {
        stopDaemon();
    }

    Logger::log("Coffee Daemon destroyed", INFO);
    Logger::shutdown();
}

void CoffeeDaemon::startDaemon()
{
    if (isRunning) {
        Logger::log("Daemon is already running.", WARNING);
        return;
    }

    isRunning = true;
    daemonThread = new QThread(this);

    connect(daemonThread, &QThread::started, this, &CoffeeDaemon::run);
    connect(daemonThread, &QThread::finished, this, &CoffeeDaemon::onDaemonThreadFinished);

    this->moveToThread(daemonThread);
    daemonThread->start();

    Logger::log("Coffee Daemon started", INFO);
}

void CoffeeDaemon::stopDaemon()
{
    if (!isRunning) {
        Logger::log("Daemon is not running.", WARNING);
        return;
    }

    isRunning = false;

    emit stopRequested();

    daemonThread->quit();
    daemonThread->wait();

    Logger::log("Coffee Daemon stopped", INFO);
}

void CoffeeDaemon::run()
{
    initializeModules();
}

void CoffeeDaemon::initializeModules()
{
    Logger::log("Initializing modules...", INFO);

    auto actuator = new Actuator_Module_Handle(this);
    auto audio = new Audio_Module_Handle(this);
    auto camera = new Camera_Module_Handle(this);
    auto core = new Core_Module_Handle(this);
    auto sensor = new Sensor_Module(this);
    auto irSensor = new InfraredSensor(this);

    connect(irSensor, &InfraredSensor::humanDetected, this, []() {
        Logger::log("Human proximity detected, triggering recognition process", INFO);
    });

    Logger::log("Modules initialized successfully", INFO);
}

void CoffeeDaemon::onDaemonThreadFinished()
{
    Logger::log("Daemon thread finished", INFO);
    delete daemonThread;
    daemonThread = nullptr;
}

