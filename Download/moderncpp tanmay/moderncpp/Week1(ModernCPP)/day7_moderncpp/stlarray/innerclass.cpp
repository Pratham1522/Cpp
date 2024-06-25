/* 
scenario 1:
    i want to design a customer retail selling website
    - customer(name,age,gender,address)
    -address(room no,flatno,location,city,state,country,pincode)
    customer HAS A address:
        Q1) would you make address outside of customer?
            -if no --Inner class.
            -if yes, is it aggregation or composition.

*/


//forward declaration

#include<iostream>

class Customer{
    public:
        Customer()=delete;
        ~Customer()=default;
        Customer(const Customer&) = delete;
        Customer& operator=(const Customer&) = delete;
        Customer(Customer&) = delete;
        Customer& operator=(Customer&&) = delete;

    class Address{
        private:
            std::string _location;
            unsigned int _pincode;
            unsigned short _house_number;
            std::string _street_name;
        public:
            Address()=default;
            ~Address()=default;
            Address(const Address&) = default;
            Address& operator=(const Address&) = default;
            Address(Address&&) = delete;
            Address& operator=(Address&&) = delete;
            Address(std::string location, unsigned int pincode, unsigned short housenumber, std::string streetname){
                _location=location;
                _pincode=pincode;
                _house_number=housenumber;
                _street_name=streetname;
            }

            unsigned int pincode() const { return _pincode; }

            inline friend std::ostream &operator<<(std::ostream &os, const Address &rhs) {
                os << "_location: " << rhs._location
                    << " _pincode: " << rhs._pincode
                    << " _house_number: " << rhs._house_number
                    << " _street_name: " << rhs._street_name;
                return os;
            }
            
    };

        Customer(std::string name, int age, Address address){
            _name=name;
            _age=age;
            _customerAddress=address;
        }
        Customer::Address customerAddress() const { return _customerAddress; }

        private:
            std::string _name;
            Address _customerAddress;
            int _age;
};


int main(){
    Customer c1("tanmay", 22, Customer::Address("pune",411027, 101, "pimple"));
    std::cout<<c1.customerAddress().pincode();
}

/*
    ["tanmay" | 22 | address of ADDRESS CLASS]

    address:
    [Pune | 23849 | 101 | IT PARK | Hinjewadi]
*/

//INNER CLASSES ARE IMPLICITLY FRIEND


/* 
    Tips for modern C++

    1) Everything in modern c++ is still based on basic C++.
        e.g. Inheritance is still the same
        e.g. access specifier are still the same
    2) All versions of C++ are fully backward compatible**
        **except anything that has been removed after deprecation
            e.g. C++11 has a feature called auto_ptr which is removed now!!
        -raw pointers still work but shared ptr is still used.
    3) Every feature in modern C++ falls under 2 categories:
        -brand new editions to the language like smart pointers & lambda functions
        - imporvement or upgrades for existing things like enum class, nullptr.
    4) If you need something, there is a good chance it is present in modern C++.
    5) Our outline has sections:
        -week1: basic cp but modern cpp syntax
        -week2: Functional programming in c++
            - lambdas
            - higher order functions
            - first class functions
        -week3: C++17 & Concurrency.
            - threads
            -ADTs, copy ellision guranttes, etc.
        -week4: STL algorithms
            - STL containers - pros, cons, how to use, when to use.
            - hashtables based on non-linear data containers.
*/
