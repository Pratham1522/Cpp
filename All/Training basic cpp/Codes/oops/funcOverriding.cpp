#include<iostream>

// A class with pure virtual function is called as abstarct class
// we cannot create object of abstract class
//we can create pointer/reference to abstract class
class Animal
{
    std::string color;
    int wt;
    float age;
    public:
        Animal():color("black"),wt(100),age(5)
        {

        }
        virtual void display()
        {
            std::cout<<color<<" "<<wt<<" "<<age;
        }
        virtual void eat()=0;// pure virtual function
};
class Horse :public Animal
{
    public:
        void display(){  }
        void eat(){
            std::cout<<"horse eats grass ";
        }
        void ride()
        {
            std::cout<<"horse riding ";
        }
};
class Tiger :public Animal
{
     public:
        void display(){  }
        void eat(){
            std::cout<<"Tiger eats .... ";
        }
};

int main()
{
    //Animal obj;//Not allowed
    // Animal *p;
    // Horse h1;
    // h1.eat();

    // Horse h2;
    // Animal &ref = h2;
    // Horse &href = dynamic_cast<Horse&>(ref);
    // href.ride();

    Horse h2;
    Animal &ref = h2;

    try
    {
        Tiger &href = dynamic_cast<Tiger&>(ref);
        href.eat();
    }
    catch( std::bad_cast &bobj )
    {
        std::cout<<bobj.what()<<"\n";
    }


//bad_cast exception is thrown if dynamic_cast fails to convert references

}