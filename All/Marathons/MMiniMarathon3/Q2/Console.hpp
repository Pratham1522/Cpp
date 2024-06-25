#pragma once
#include "LogSwitch.h"

class Console:public LogSwitch
{
    public:
    Console(ILogger *sender):LogSwitch(sender)
    {

    }
    void log(string msg) override
    {
        msg = "logger logged [ "+msg+" ] \n";
        cout<<"Cosole "<<msg;
        LogSwitch::log(msg);  
    }
};
