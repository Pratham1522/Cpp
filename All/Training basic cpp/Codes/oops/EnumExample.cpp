#include<iostream>
enum PolicyTypes
{
    HEALTH,LIFE,MONEYBACK
};

class Policy
{
    int policynumber;
    int amount;
    enum PolicyTypes ptype;
    public:
        Policy():policynumber(111),amount(200000),ptype(PolicyTypes::LIFE)
        {

        }
         Policy(int pnum,int amt,enum PolicyTypes pt):
         policynumber(pnum),amount(amt),ptype(pt)
        {

        }
        void show();

        void setPolicynumber(int policynumber_) { policynumber = policynumber_; }

        void setAmount(int amount_) { amount = amount_; }

        void setPtype(const enum PolicyTypes &ptype_) { ptype = ptype_; }

};
void Policy::show()
{
    std::cout<<"\n Policynumber="<<policynumber<<" amount ="<<amount;
    switch(ptype)
    {
        case 0:
            std::cout<<"  HEALTH";
            break;
        case 1:
            std::cout<<"  LIFE ";
            break;   
        case 2:
            std::cout<<"  MONEYBACK";
            break;
    }
}

void createObject(Policy &pob)
{
    int pnumber;
    int pamount;
    int potype;
    std::cout<<"\n Enter policynumber ";
    std::cin>>pnumber;
    std::cout<<"\n Enter amount ";
    std::cin>>pamount;
    std::cout<<"\n Enter policy type as 0- HEALTH 1-LIFE  2-MONEYBACK";
    std::cin>>potype;
    pob.setPolicynumber(pnumber);
    pob.setAmount(pamount);
    switch (potype)
    {
    case 0:pob.setPtype(PolicyTypes::HEALTH);
        break;
    case 1:pob.setPtype(PolicyTypes::LIFE);
        break;
    case 2:pob.setPtype(PolicyTypes::MONEYBACK);
        break;         
    default:
       pob.setPtype(PolicyTypes::HEALTH);
    }
    
}

int main()
{
    Policy pobj;
    createObject(pobj);
    pobj.show();

    Policy p1;
    p1.show();

    Policy p2(555,90000,PolicyTypes::HEALTH);
    p2.show();
}