#include "core_module_handle.h"
#include "public_variable.h"

void Core_Module_Handle::Core_Module_Run()
{
    Screen_Fresh_Timer=new QTimer(this);

    Screen_Fresh_Timer->setTimerType(Qt::CoarseTimer);
    Screen_Fresh_Timer->setSingleShot(true);
    Screen_Fresh_Timer->setInterval(5);
    connect(Screen_Fresh_Timer,SIGNAL(timeout()),this,SLOT(Core_ScreenFresh_Slot()));
    Screen_Fresh_Timer->start();
}

void Core_Module_Handle::Core_ScreenFresh_Slot()
{
    char CurrentPage=MachinePage;

    if((CurrentMachineState()==coffeeMachine_State_Processing) && (CurrentPage==INDEX_OF_PROCESSINGPAGE1_EMOTION))
    {
        emit User_GUI_Face_Pic_Fresh();
    }

    if(CurrentPage==INDEX_OF_MAINTAINPAGE)
    {
        emit Test_GUI_Face_Pic_Fresh();
    }
    Screen_Fresh_Timer->start();
}
