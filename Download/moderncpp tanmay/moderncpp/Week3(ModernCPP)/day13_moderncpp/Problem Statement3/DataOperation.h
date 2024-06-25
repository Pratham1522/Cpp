#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <iostream>
#include <condition_variable>
#include <thread>
/*
1)Which function is invoked while constructing a new object ?
  - public member function

  *) Make the constructor private!

2)If Constructor is private, how would yoy make the first object ?

*/
// Singleton Class Design pattern.

// Book for Design Pattern -(https://www.amazon.in/Design-Patterns-Object-Oriented-Addison-Wesley-Professional-ebook/dp/B000SEIBB8);
class DataOperation
{
private:
    int m_value{-1};
    std::mutex m_mt;
    std::condition_variable m_cv;
    bool m_flag{false};
    int *_value{nullptr};
    DataOperation() = delete;
    // copy constructor can only be created if only all the data members are copiable.
    // here class of mutex and condition_variable copy constructor is deleted.
    DataOperation(const DataOperation &) = delete;            // Copy constructor
    DataOperation &operator=(const DataOperation &) = delete; // Copy assignment operator
    DataOperation(DataOperation &&) = delete;                 // Move constructor
    DataOperation &operator=(DataOperation &&) = delete;
    DataOperation(int mval) : m_value{mval} {}
    static DataOperation *_only_object;

public:
    static DataOperation *GetInstance(int val);
    void Producer_Input();
    void Consumer_Operation();
    ~DataOperation() = default; // Destructor
};
/*

 program starts:
 ---> programmer wants first objects
    ---> programmer notices no constructor.
    ---> programmer also notices GetInstance.
    ---> programmer invokes GetInstance

 ---> GetInstance will check if previously any object was created,
  ----> if not, make a new object,return its address
  ---->else, return the address of the existing object

*/

#endif // DATAOPERATION_H
