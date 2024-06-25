#include "Functionalities.h"
#include <array>

void CreateObjects(Container &data)
{
    data.push_back(new Customer(123, "tanmay", CustomerType::VIP, new int[5]{10, 10, 10, 10, 10}));
    data.push_back(new Customer(1234, "john", CustomerType::VIP, new int[5]{10, 10, 10, 10, 10}));
    data.push_back(new Customer(1235, "tan", CustomerType::REGULAR, new int[5]{30, 10, 10, 10, 10}));
}

unsigned int FindID(Container &data)
{
    int id;
    int max = 0;
    if (data.empty())
    {
        throw VectorEmptyException("DATA is empty.\n");
    }
    for (Customer *obj : data)
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            // sum+=obj->customerTransactionAmount()[i];
            sum += *(obj->customerTransactionAmount() + i);
        }
        if (sum > max)
            {
                max = sum;
                id = obj->customerId();
            }
    }
    return id;
}
Container FindInstanceOfSameType(Container &data, CustomerType type)
{
    Container answer;
    // for(Customer* obj:data){
    //     if(obj->customerType()==type){
    //         answer.push_back(obj);
    //     }
    // }
    for (Container::iterator itr = data.begin(); itr != data.end(); itr++)
    {
        std::cout << **itr << "\n";
    }
    return answer;
}

Container FindInstanceInSameRange(Container &data)
{
    Container answer;
    for (Customer *obj : data)
    {
        if (obj->customerStoreCredits() >= 100 && obj->customerStoreCredits() <= 200)
        {
            answer.push_back(obj);
        }
    }
    return answer;
}

void FindSumOfHigeshtAndLowest(Container &data)
{
    int min = 10000;
    int max = 0;
    for (Customer *obj : data)
    {
        if (obj->customerStoreCredits() > max)
        {
            max = obj->customerStoreCredits();
        }
        if (obj->customerStoreCredits() < min)
        {
            min = obj->customerStoreCredits();
        }
    }
    std::cout << "sum of highest and lwoest is: " << min + max << "\n";
}

void DeleteObjects(Container &data)
{
    for (auto obj : data)
    {
        if (obj)
        {
            delete obj;
        }
    }
}
