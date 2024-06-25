#include <iostream>

class CA {
public:
    CA() {
        std::cout << "Default constructor called" << std::endl;
    }

    CA(const CA& other) {
        std::cout << "Copy constructor called" << std::endl;
    }
};

CA f3() {
    CA obj3;
    return obj3;
}

int main() {
    CA obj4 = f3(); // why Copy constructor is not invoked here
    return 0;
}
