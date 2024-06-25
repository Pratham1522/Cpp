#include<iostream>
using std::cout;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class Account
{ 
    protected:
    virtual void ActualDebit(int accId, int amount) = 0;

    public:
    void Debit(int accid,int amount)
    {
        cout<<"Open DB\n";
        ActualDebit(accid, amount);
        cout<<"Close DB\n";
    }
};
class SavingsAcc:public Account
{
    protected:
    void  ActualDebit(int accId, int amount) override
    {
        cout << "Debit Savings\n";
    }
};
class CurrentAcc:public Account
{
    protected:
    void ActualDebit(int accId,int amount) override
    {
        cout<<"Debit Current\n";
    }
};

int main()
{
    line(welcome);

    SavingsAcc sa;
    sa.Debit(101,100);
    line(x);
    CurrentAcc ca;
    ca.Debit(102,200);

    line(end);
    return 0;
}  

/*
1. yagni -> you arn't gonna need it
2. High cohession
3. SRP -> Single Responsibility Priniciple
4. Kiss -> keep it simple and stupid
5. Dry/Die/Wet/Oaoo -> dont repeat yourself/duplication is evil/We Enjoy typing/Once and only once
*/