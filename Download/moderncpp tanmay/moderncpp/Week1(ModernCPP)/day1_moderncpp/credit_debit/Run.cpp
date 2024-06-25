#include "Functionalities.h"

int main()
{
    try
    {
        std::vector<BankAccount *> data;
        //createObject(data);
        Print(data);
        std::cout << calculateAverage(data);
    }
    catch(VectorEmptyException &ex){
        std::cout<<ex.what()<<"\n";
    }
}