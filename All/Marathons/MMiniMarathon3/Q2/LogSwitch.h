#pragma once
#include "ILogger.h"
#include"NullLogger.h"
using std::cout;

class LogSwitch:public ILogger
{
    ILogger* msgSender;

    protected:
    LogSwitch(ILogger* sender):msgSender(sender) 
    {

    }
    public:
    void log(string msg) override
    {
        msgSender->log(msg);
    }
};
