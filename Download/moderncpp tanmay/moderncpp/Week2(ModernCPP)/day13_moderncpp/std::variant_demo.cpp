#include<iostream>
#include<variant>
#include "Employee.h"
#include "BusinessOwner.h"
#include<array>


using VType = std::variant<Employee*,BusinessOwner*>;

/* 
    Each variant variable when declared is always initialized with default value of type
    at first position in the variant declaration
    eg: VType was declared for <EMployee,BusinessOwner>, employees is at 1st position.
    VType v; v will be assigned defuat value of type eployee which means employee class must have
    def const enabled.
*/

void CreateObject(){
    VType v = new Employee("tanmay",5384752.0f);

}

void CreateObjects(std::array<VType,2>& data){
    data[0] = new Employee("tanmay",36472.0f);
    data[1] = new BusinessOwner("tan",8888,3421);

    data[0] = new BusinessOwner("abc",7890,3456);
}

void TaxFunctionCall(std::array<VType,2>& data){
    /* 
    for each variant that is stored in the array,
        a) "visit" the variant
        b) open the variant wrapper, you should get a pointer inside, ptr can be emp or businowner
        c) regardless of type call the ptr as "val" now use val to call paytax function.
    */
   for(VType& v:data){
    std::visit(
        [](auto&& val){val->payTax();},v
    );
   }
   /*visit func takes 2 param
   1) a callable that explains what u want to do
   with the item dound inside the variant
   2) you can pass one or more than 1 variant (based on requirements)  */
   
}


int main(){
    std::array<VType,2> data;
    CreateObjects(data);
    TaxFunctionCall(data);

}

/*
    variant helps byreducing drawbacks in upcasting

    Manager m1;
    Accountant a1;
    Hr h1;
    variant<Manager,Accountant,HR> = h1;
*/
