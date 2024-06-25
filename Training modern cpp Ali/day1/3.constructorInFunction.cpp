#include<iostream>
using std::cout;
#define line(msg) cout<<"-------------------"#msg"---------------------\n";

class CA
{
    public:
    CA()
    {
        cout<<"Default C-tor \n";
    }
    CA(const CA&)
    {
        cout<<"CA Copy C-tor \n";
    }
    CA& operator=(const CA&)             
    {
        cout<<"CA Assign operator \n";
        return *this;
    }
    ~CA()
    {
        cout<<"CA D-tor \n";
    }
};
void f1()
{
    CA obj1; //CA::CA 
}//CA::~CA  
int f2()
{
    CA obj2;  //CA::CA
    return 0; //CA::~CA
}
CA f3()
{
    CA obj3;    //CA::CA
    return obj3;
}
// CA& f4()
// {
//     CA obj4;
//     return obj4;    //returning reference to local var
// }
// CA* f5()
// {
//     CA obj5;
//     return  &obj5;   //returning address of local obj.
// }
int main()
{
    line(welcome);
    f1();       //f1()
    line();
    f2();       //f2()
    line();
    // CA obj4;
    CA obj4 ;
    obj4 = f3();     //f3()

    line();

    line(come_back_again);
    return 0;    //f3->CA::~CA
}
//returning from function calls copy constructor or assignment operator but compiler dont show that becoz of constructor elide, compiler optimise creating tempory objects.
// when object already declared and copy then assignment operator.
//when same line copy as declaration then copy constructor.

//whenever you return a obj and reciving it in a obj , then copy constructor is called two times be called as obj is already defined , but assignment operator can be called depending on situation. 

/*
-fno-elide-constructors
       The C++ standard allows an implementation to omit creating a
       temporary which is only used to initialize another object of the
       same type.  Specifying this option disables that optimization, and
       forces G++ to call the copy constructor in all cases.
*/
