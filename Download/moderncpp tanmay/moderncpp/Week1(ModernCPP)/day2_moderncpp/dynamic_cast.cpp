#include<iostream>

class Parent{
    private:
        std::string _surname;
    public:
    //function exists in parent and child both, but it is not marked virtual (without upcasting)
    void non_virtual_fn_in_parent_child(){
        std::cout<<"parent output from fn\n";
    }

    //function only exists in parent, not overriden, not marked (upcasting and normal case both)
    void ParentOnlyFunctionTest(){
        std::cout<<"LUKE I AM YOUR FATHER."<<std::endl;
    }

    //function exists in parent and child, implemented in both, marked as virtual (works with upcasting and also gives diff output for diff output)
    virtual void Display(){
        std::cout<<"Parent class func called\n";
    }

    //function exists in parent and child, implemented only in child, marked as PURE virtual
        Parent(std::string surname):_surname(surname){}
        ~Parent(){
            std::cout<<"parent dest called\n";
        }

        std::string surname() const { return _surname; }
        void setSurname(const std::string &surname) { _surname = surname; }
};

class Child : public Parent{
    private:
        std::string _name;
    public:
        void non_virtual_fn_in_parent_child(){
        std::cout<<"parent output from fn\n";
    }
        Child(std::string surname,std::string name) : Parent(surname){
            _name=name;
        }
        void Display() override{
        std::cout<<"Parent class func called\n";
    }
        ~Child(){
            std::cout<<"child dest called\n";
        }

        std::string name() const { return _name; }
        void setName(const std::string &name) { _name = name; }
};

/* in case of upcasting,
for non-virtual functions, compiler does not care about object RHS
for virtual functions, compiler will surely consider object type also
by finding in the hierarchy of inheritance, the most derived version of a functionality. */


int main(){
    Parent *p1 = new Parent("xyz");
    p1->Display();//pointer : parent, object : parent
    p1->ParentOnlyFunctionTest();

    Parent *p2 = new Child("xyz","abc");
    //std::cout<<p2->name(); will give error

    /* dynamic cast is used if you want a functionality that exists only in child
    utilizing the parent pointer BUT BY CONVERTING INTO CHILD TYPE */
    Child* cptr = dynamic_cast<Child*>(p2);
    if(cptr == nullptr){
        std::cerr << "conversion failed\n";
    }
    else{
        std::cout<<"name of child is : "<<cptr->name();
    }
    Parent q("xyz");
    try{
        Child& ch = dynamic_cast<Child&>(q);
        ch.name();
    }
    catch(std::bad_cast& ex){
        std::cerr << "casting was way too risky. It failed\n";
    }
}

/* upcasting: taking ref or pointer of subtype and assigning it to reference or pointer of parent type respectively */


/* objective: craete obj of diff child classes and store/prcoess them collectively
While doing this, if a functionality is difference in these classes, ezecute the correct version of the functionality
based on type */

/* concept: method/function overloading
1. base idea for this : polymorphism
2. syntactically how does the compiler know function will be changed in child class : virtual keyword.
3. will the compiler block parent class obj creation or not? : dependent on abstract class or not!
4. how does the compielr know this? based on existence/lack of atleast 1 pure virtual function! */

