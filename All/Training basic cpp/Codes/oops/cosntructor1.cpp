#include<iostream>

class Sample
{
    const int x;
  //  int &r;
    public:
        Sample():x(100)
        {
            
        }
        Sample(int y):x(y)
        {

        }
        void show()
        {
            std::cout<<x<<std::endl;
        }
};

int main()
{
    
    Sample s1;
    s1.show();
    Sample s2(200);
    s2.show();
}