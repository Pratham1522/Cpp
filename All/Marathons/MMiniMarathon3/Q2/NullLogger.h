#pragma once
#include"ILogger.h"

class NullLogger : public ILogger
{
    public: 
    void log(string) override
    {

    }
};
