#include<iostream>
using std::cout;
#define line(msg) cout<<"-------------------"#msg"---------------------\n";

class CA
{
    public:
    //default constructor
    CA() // this pointer is created at constructor call @this line
    {
        cout<<"CA Default C-tor \n";
    }

    //copy constructor
    CA(const CA&)
    {
        cout<<"CA Copy C-tor \n";
    } 

    //Assign operator overloading.
    CA& operator=(const CA&)             
    {
        cout<<"CA Assign operator \n";
        return *this;
    }

    //destructor
    ~CA()
    {
        cout<<" CA D-tor \n";
    }
};
class Cat
{
    CA obj2;

    public:
    Cat(CA& par):obj2(par) // CA::CA(copy) ->copy constructor call here
    {
        cout<<"Cat Par C-tor \n";    //then body of constructor is executed
    }
    ~Cat()
    {
        cout<<"Cat D-tor \n";
    }  //CA::~CA Contained obj destructor called here
};
int main()
{
    line(welcome);

    CA obj1; // CA::CA -> call default constructor of CA at this line.

    // Cat cat1(CA obj1);  //didn't work.
    Cat cat1(obj1);

    line(come_back_again);
    return 0;  // Cat::~Cat ,CA::~CA -> destructor call here 
    //anything after return 0 line will not be printed.
}

//container contained object constructor is called using prolog of container constructor '{' 
//and destructor form epilog '}'

//so first contained obj constructor, then obj constructor.

// passing a object by value will invoke copy constructor.

//The copy constructor is used to initialize the members of a newly created object
// by copying the members of an already existing object.
