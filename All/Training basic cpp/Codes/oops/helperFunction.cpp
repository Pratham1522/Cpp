#include<iostream>
class Mobile;
class Sample
{
    int x;
    bool check()//helper functions
    {
        if(x%2==0)
            return true;
        else
            return false;

    }
    public:
        Sample()
        {
            x=10;
        }
        void print()
        {
            if(check())
                std::cout<<"\n number is even";
            else
                std::cout<<"\n odd";
        }   
};

int main()
{
    Sample s1;
    Mobile m;
    s1.print();

}

class Mobile{
    public:
        Mobile()
        {
            std::cout<<"Mobile called";
        }
};