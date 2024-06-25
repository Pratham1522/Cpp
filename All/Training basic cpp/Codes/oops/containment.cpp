#include<iostream>
//containment
class Address
{
    std::string city;
    int pincode;
    public:
        Address():city("Pune"),pincode(1234){ 

            std::cout<<"\n Adress() called ";
        }
        Address(std::string ct,int pin):city(ct),pincode(pin)
        {
            std::cout<<"\n Adress(...) called ";
        }
        void display()
        {
            std::cout<<"\t city = "<<city<<" pincode ="<<pincode;
        }
};
class Student// container class
{
    int rollno;
    std::string name;
    Address add;//contained object
    public:
        Student():rollno(1),name("Yash")
        {
             std::cout<<"\n Student() called ";
        }
        Student(int r,std::string nm,std::string ct,int p)
        :rollno(r),name(nm),add(ct,p)
        {
            std::cout<<"\nStudent(... ) called ";
            //Address(ct,p);
        }
        void display()
        {
            std::cout<<"\n Rollno ="<<rollno<<" name="<<name;
            add.display();
        }
};

int main()
{
   Student s1;
   s1.display();

    Student s2( 2,"Jay", "Mumbai",3456 );
    s2.display();
}
