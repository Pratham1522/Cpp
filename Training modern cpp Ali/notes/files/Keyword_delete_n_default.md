
## delete keyword 
```cpp
static void* operator new(size_t) = delete;
static void* operator new[](size_t) = delete;
static void operator delete(void*) = delete;
static void operator delete[](void*) = delete;
```
- ```delete```  is part of C++11 a and is used for explicitly deleting special member functions or overloaded operators. It's often used to prevent certain operations from being performed, such as preventing dynamic memory allocation for a particular class or preventing certain types of copy operations.

## default keyword
```cpp
CA() = default;
~CA() = default;
```
- `default` keyword is used to instruct the compiler to generate the default implementation of a special member function if it is not explicitly defined by the programmer. This applies to constructors, destructors, copy constructors, copy assignment operators, and move operations.
