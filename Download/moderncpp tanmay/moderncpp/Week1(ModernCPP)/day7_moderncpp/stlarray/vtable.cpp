#include<iostream>

class Vehicle{
    public:
        virtual void Display()=0;
        virtual void VehicleRegister(){
            std::cout<<"VEHICLE REGISTER\n";
        }
};

class Car : public Vehicle{
    public:
        void Display() override{
            std::cout<<"CAR"<<"\n";
        }
        void VehicleRegister() override{
            std::cout<<"CAR REGISTERED BY BS6\n";
        }
};

class Bike : public Vehicle{
    public:
        void Display() override{
            std::cout<<"BIKE\n";
        }
};

int main(){
    Vehicle* ptr = new Car();
    ptr->Display();
    /* 1)what is the ptr = Vehicle
    2)does vehicle class have any mention of display member?
        -if no then compile time error
        -yes> proceed further.
    3)what is nature of display function?
        - non-virtual function---> go to question x.
        -for virtual function ---> go to question y.
    x) is the function concrete or abstract?
        -if conc call function from pointer class
        -if abstract compile time error.
    y) what is type of object:
        -find the vtable for the object type
        -find the address of display for object type::display()
 */
}

/* 
    vtables: these are records of virtual functions and their location in code segment.

    rule 1: a vtable will be always made for a class that contains atleast 1 virtual function

    rule 2: a child class that inherits from a parent containing a vtable has to make its own vtable also.

    rule 3: the location where the vtable for a class "X" is stored is recorded in vptr.

    rule 4: exact data structure level implementation of a vtable not standardized
*/

/* 
    vtable for vehicle
    [Display : 0x0000, Register : 0x987H]<-----
                                              |
    vtale for Car                             |
    [Display : 0x111H, Register : 0x555H]     |
                                              |
    vtable for bike                           |
    [Display : 0x222H, Register : 0x987H]-----|
*/

