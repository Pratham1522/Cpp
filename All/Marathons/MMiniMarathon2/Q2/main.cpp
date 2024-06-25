#include<string>
#include "CAR.hpp"
#include "Lorry.hpp"
#include "OX.hpp"

#include<bits/stdc++.h>
using namespace std;
#define line() cout<<"-------------------------\n";
// using std::cout;


class Functor
{
public:
    void operator()(CAR& car)
    {
        car.carFun();
    }
    void operator()(Lorry& lorry)
    {
        lorry.LorryFun();
    }
    void operator()(OX& ox)
    {
        ox.oxFun();
    }
};

void DoBussiness(std::variant<CAR, Lorry, OX> var)//comp
{
    std::visit(Functor{}, var);
}

void BookVehicle(int id,std::string driverName)
{
    cout << "BookVehicle id : " << id << '\t' << ",Booked By : " <<driverName << '\n';
}
void FeedAnimal(std::string item,int weight)
{
    cout << "FeedAnimal with : " << item << " of : " << weight << "kgs. \n";
}

void ExecuteBussinessFlow(std::function<void()> fn) //comp
{
    fn();
}

int main()
{
    CAR car;
    Lorry lorry;
    OX ox;
    line();
    DoBussiness(car);
    DoBussiness(lorry);
    DoBussiness(ox);
    line();

    ExecuteBussinessFlow(bind(DoBussiness,car));
    ExecuteBussinessFlow(bind(DoBussiness,ox));
    ExecuteBussinessFlow(bind(DoBussiness,lorry));
    ExecuteBussinessFlow(bind(BookVehicle,101,"Pratham"));
    ExecuteBussinessFlow(bind(FeedAnimal,"Grass",1));
    line();
    return 0;
}
