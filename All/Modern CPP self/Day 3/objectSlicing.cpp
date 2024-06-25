#include<iostream>
using namespace std;
#define line(msg) cout<<"----------(msg)------------\n";
// class CA
// {
//     int x;

//     public:
//     CA(int x):x(x)
//     {
//         cout<<"Param Const\n";
//     }
//     void Disp()
//     {
//         cout << "X=" << x << '\n';
//     }

// };
// class CB
// {

// };
// int main()
// {
//     CA obj1(100); //construction
//     obj1.Disp();
//     line();
//     CA obj2 = 200;  //conversion
//     obj2.Disp();
//     line();
//     obj1=300; //conversion and then assignment
//     //obj1.Disp();
//     line();
//     return 0;
// }



//comma operator, execute l to r , assign r most value to var.


#-------------------------------------------------------------------------
class CA
{
    int x;
    int y;

    public:
    CA(int x):x(x),y(x)
    {
        cout<<"Param Const\n";
    }
    CA& operator=(const CA& par)
    {
        cout<<"Assignment";
        this->x=par.x;
        return *this;
    }
    void Disp()
    {
        cout << "X=" << x << '\n';
    }

};
int main()
{
    CA obj1(100); //construction
    obj1.Disp();
    line();
    CA obj2 = 200;  //conversion
    obj2.Disp();
    line();
    obj1=(100,200); //conversion and then assignment
    //obj1.Disp();
    line();
    CA obj4=(111,222);
    obj4.Disp();
    obj1=234;
    line();
    obj1 = (22,33);
    line(BraceInit);
    int x{ 10 };
    CA obj5{ 10 };
    line();
    CA obj6 = { 10 };
    line();
    CA obj7{10,10 };
    line();
    CA obj8={ 11,22 };
    line();
    

    return 0;
}
//explict for multi para from modern cpp