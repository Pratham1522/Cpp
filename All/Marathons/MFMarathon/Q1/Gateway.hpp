#pragma once
#include <iostream>
using namespace std;

class GatewaySecurity
{
    GatewaySecurity() 
    {        
    }
    ~GatewaySecurity()
    {
    }

    static GatewaySecurity* head;

    static GatewaySecurity* makeObj()
    {
        if(head==nullptr)
        {
            head=new GatewaySecurity();
        }
        return head;
    }

    static void releaseObj()
    {
        if(head!=nullptr)
        {
            delete head;
            head=nullptr;
        }
    }
    friend class SmartSingle;

    public:
    void IssueTokens(int userID)
    {
        std::cout << " Token Claims Issued for " << userID << '\n';
    }
    static void fun()
    {
        cout<<"Fun called! \n";
    }
};
GatewaySecurity* GatewaySecurity::head=nullptr;
