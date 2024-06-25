#include"Employee.h"
#include"Business.h"
#include<variant>
#include<list>

using Vtype = std::variant<Employee*,Business*>;


using Contanier = std::list<Vtype>;

int main()
{
    Contanier data;
    data.push_back(new Employee("This is Employee 1"));
    data.push_back(new Business("This is Business 1"));
    data.push_back(new Business("This is Business 2"));
    data.push_back(new Employee("This is Employee 2"));

    for(auto a : data)
    {
        if(std::holds_alternative<Employee*>(a))
        {
            std::get<0>(a) -> Display(); // use the index where that type is present in variant definition
        }
        else
        {
            std::get<1>(a) -> Display();
        }
    }

    // std::visit




    return 0;
}