#include "Functionalities.h"

void createObjects(Container &data)
{
    data.push_back(new Customer(
        1,
        "tanmay",
        CustomerType::VIP,
        {1,2,3,4,5},
        151)
    );
        data.push_back(new Customer(
        2,
        "abcd",
        CustomerType::VIP,
        {1,2,3,4,6},
        444)
    );
        data.push_back(new Customer(
        3,
        "harsh",
        CustomerType::PREMIUM,
        {1,2,3,4,5},
        555)
    );
}

int FindCustomerIDByMaxTransactionAmount(Container &data){
    int id=0;
    int max=0;
    for(int i=0;i<data.size();i++){
        double total=0.0f;
        total+=data[i]->sumofarr();
        if(max<total){
            max = total;
            id = data[i]->customerId();
        }
    }
    return id;
}

Container FindContainerOfSameType(Container &data, CustomerType type){
    Container solution;
    for(auto obj : data){
        if(obj->customerType()==type){
            solution.push_back(obj);
        }
    }
    return solution;
}

Container FindInstancesinSameRange(Container &data){
    Container solution;
    for(auto obj:data){
        if(obj->customerStoreCredits()>=100 && obj->customerStoreCredits()<=200){
            solution.push_back(obj);
        }
    }
    return solution;
}

void FindInstanceOfHighestnLowest(Container &data){
    int sum=0;
    int minimum=10000;
    int maximum=0;
    for(auto obj:data){
        if(obj->customerStoreCredits()<minimum){
            minimum = obj->customerStoreCredits();
        }
        if(obj->customerStoreCredits()>maximum){
            maximum = obj->customerStoreCredits();
        }
    }
    std::cout<<"Sum of credits of highest and lowest is: "<<maximum+minimum<<std::endl;
}

double FindAverageOfSameType(Container &data, CustomerType type){
    double total = 0.0f;
    int count=0;
    for(auto obj:data){
        if(obj->customerType()==type){
            total+=obj->customerStoreCredits();
            count++;
        }
    }
    return static_cast<double>(total/count);
}

bool FindIfAllTypeAreSame(Container &data){
    int count=0;
    CustomerType type = data[0]->customerType();
    for(auto obj:data){
        if(obj->customerType()==type){
            count++;
        }
    }
    if(count==data.size()){
        return true;
    }
    return false;
}
