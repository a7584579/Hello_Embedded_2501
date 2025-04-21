#include "audio_module_handle.h"

Audio_Module_Handle::Audio_Module_Handle(QObject *parent)
    : QObject{parent}
{}


void Audio_Module_Handle::Audio_Module_Start_Slot()
{
    emit Module_Ready();
}
