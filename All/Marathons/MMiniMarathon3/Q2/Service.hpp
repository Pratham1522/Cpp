#pragma once
#include "LogSwitch.h"

class Service:public LogSwitch
{
    public:
    Service(ILogger *sender):LogSwitch(sender)
    {

    }
    void log(string msg) override
    {
        cout<<"Service "<<msg;
        LogSwitch::log(msg);  
    }
};
