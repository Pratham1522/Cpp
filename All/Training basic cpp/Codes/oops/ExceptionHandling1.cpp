#include<iostream>

class Vote
{
    int age;
    public: 
        Vote():age(22){}
        Vote(int a):age(a){}
        void doVoting()
        {
            if(age>18)
                std::cout<<"\n Can VOTE ";
            else
                throw std::runtime_error("age should be >18");
        }
};

int main()
{
    Vote v1(10);
    try
    {
        v1.doVoting();
        std::cout<<"End of try block ";
    }
    catch(std::runtime_error &r)
    {
        std::cout<<r.what()<<"\n";
    }
    catch(std::exception &e)//generic handler
    {
            std::cout<<e.what()<<"\n";
    }

     Vote v2(45);
    v2.doVoting();
}