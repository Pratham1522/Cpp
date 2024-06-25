#include"Salesperson.h"
class DoortoDoor :public Salesperson
{    int houses;
    public:
        DoortoDoor():Salesperson(),houses(10)
        {
             std::cout << "\n DoortoDoor() called ";
        }
DoortoDoor(int eid,std::string nm,double esal,float exp,double samt,
             double cr,int h):
             Salesperson(eid,nm,esal,exp,samt,cr)
        {
            std::cout << "\n DoortoDoor(...) called ";
            houses=h;
        }
        void display()
        {
            Salesperson::display();
            std::cout<<" houses ="<<houses;
        }
};
 