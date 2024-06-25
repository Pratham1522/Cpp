/* #include<iostream>
#include<functional>

void DataAdaptor(int n1, std::string& name, float salary, char& grade, std::function<void()>  fn){
//inside this func logic should cahnge name and grade
    fn();
}

int main(){
    //declaration and initialization of a char type variable grade wit initial 'A' 
    char grade{'A'};
    std::string name{"here"};

    //declaration and init of a variable f1 whose type is to be deducted by compler based on
    // initial lambda literal for a function that accepts 2 parameters
    // - string reference name and character reference grade with function returning void.
    auto f1 = [](std::string& name, char& grade){name="tanmay";grade = 'B';};

    //invoke dataapadtop function by passing 
    //a) int by rvalue, name as lvalue reference to string, grade as lvalue 
    //reference to character, salaray by rvlaue of type float, lambda object by value
    DataAdaptor(10,name,10000,grade,f1);
    DataAdaptor(
        10,
        name,
        10000.0f,
        grade,[&](){
            name = "ben";
            grade = 'B';
        }
    );
}


//logic for modifyin name and grade */
