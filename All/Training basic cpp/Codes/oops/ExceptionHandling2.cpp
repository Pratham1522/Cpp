#include<iostream>
#include<cstring>
class LowageException :public std::exception
{
    char errormsg[100];
    public:
    LowageException(){}
    LowageException(const char* m){ strcpy(errormsg,m); }
   const char* what()
    {
        return errormsg;
    }
};
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
                throw LowageException("age should be >18");
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
    catch(LowageException &r)
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