#pragma once
#include "Gateway.hpp"

using FPTR = void(*)();
class SmartSingle
{
    GatewaySecurity* gateway_security { nullptr };
    FPTR fp = GatewaySecurity::fun;
    static int count;

    public:
    explicit SmartSingle():gateway_security(GatewaySecurity::makeObj())
    {
        count++;
    }
    static void* operator new(size_t) = delete;
    static void* operator new[](size_t) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;

    GatewaySecurity* operator -> ()
    {
        return gateway_security;
    }
    GatewaySecurity& operator *()
    {
        return *gateway_security;
    }
    // SmartSingle& operator->*(FPTR fp)
	// {
	// 	this->fp = fp;
	// 	return *this;
	// }
	// void operator()()
	// {
	// 	(gateway_security->*fp)();
	// }

    

    ~SmartSingle()
    {
        count--;
        if(count <=0)
        {
            GatewaySecurity::releaseObj;
        }
    }
};
int SmartSingle::count=0;
