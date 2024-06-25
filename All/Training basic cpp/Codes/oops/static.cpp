#include <iostream>

class Bankaccount
{
    static int accno_count;
    int accno;
    std::string custname; // object of string class- data member of bankaccount class
    double balance;
    static double interestrate; // data section- single copy is created per class

public:
    Bankaccount():custname("Yash"),balance(25000)
    {
        accno_count++;
        accno = accno_count;
        
    }
    Bankaccount(std::string cname, double b):custname(cname),balance(b)
    {
        accno_count++;
        accno = accno_count;
    }
    static void print()
    {
        std::cout << "\n interestrate =" << interestrate;
        // static funs can access static data members only
        // ? they do not receive this pointer
    }
    void display()
    {
        std::cout<<"\n Accno ="<<accno;
        std::cout<<"\n Name ="<<custname;
        std::cout<<"\n Balance ="<<balance;
    }
};
double Bankaccount::interestrate = 7.5;
int Bankaccount::accno_count = 10000;
int main()
{

    Bankaccount::print();
    Bankaccount b1, b2;
    b1.display();
    b2.display();
    Bankaccount b3("Jay",75000);
    b3.display();
    return 0;
}