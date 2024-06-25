#pragma once
#include "LogSwitch.h"

class File:public LogSwitch
{
    public:
    File(ILogger *sender):LogSwitch(sender)
    {

    }
    void log(string msg) override
    {
        cout<<"File "<<msg;
        LogSwitch::log(msg);  
    }
};
