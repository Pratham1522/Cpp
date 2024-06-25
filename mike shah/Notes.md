# C++ with mike

## Primitive data types 
- void (1 byte)
- char (1 byte)
- int (mostly 4 bytes)
- short (2 bytes)
- long (8 bytes)
- long long (8 bytes)
- (these can be signed or unsigned)
- bool (1)
- float (4)
- double (8)
- long double (16)
---
- in modern c++, we can explicitely define fixed width integer types like `int64_t`,`int32_t`, `int_fast8_t`,etc.
---
---
## blocked scope
- A block scope is the scope defined by a pair of curly braces {}. Variables declared within this block are **only accessible within the block**.
- Block scope provides a way to limit the visibility and lifetime of variables, which helps in:
  - **Reducing memory usage** by releasing variables when they are no longer needed.
  - **Preventing name conflicts** by limiting the variable's visibility to the block.
  - Making code more modular and easier to understand.
```cpp
int main(){
    {
        int x=7;
    }
    x=42; // x is not defined here.
}
```
- if a variable is globally scoped(declared gloabally), then local variable is given more preference.
- global variables are not a good practice.
- we can use **extern** keyword to use global variables in different files.
```cpp
int x=42;
int main()
{
    {
        x=7; //okay
    }
    x=45; // okay
}
```
---
---
## Loops 
### For loop
- used to iterate over a range of values
- Synthax : `for (initialization; condition; increment) {}`
- Initialization, condition, and increment are all optional
- If the condition is omitted, it is considered to be always true, infinite loop.
- If increment is omitted, variable is never incremented by default, must write increment statement.
- we can also increment iterator inside body of loop.
---
### Range-Based For Loop
- Introduced in C++11, it simplifies iteration over containers.
- Synthax : `for (declaration : container) {}`
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
for (int &x : vec) {
    std::cout << x << std::endl;
}
```
---
### while loop
- Executes as long as a condition is true.
- Synthax : `while (condition) {}`
---
### Do while loop
- Executes the loop body at least once, then checks the condition.
- Synthax : `do {} while (condition);`
---
### Continue and break
- The continue and break statements are control flow statements used within loops to alter the normal flow of execution. 
- The **continue** statement skips the remaining instructions of the current iteration of the loop and proceeds with the next iteration.
```cpp
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) {
        continue; // Skip the rest of the loop body for even numbers
    }
    std::cout << i << std::endl; // This line will only be reached for odd numbers
}
```
- The **break** statement immediately terminates the nearest enclosing loop or switch statement and transfers control to the statement following the terminated loop.
```cpp
for (int i = 0; i < 10; ++i) {
    if (i == 5) {
        break; // Exit the loop when i equals 5
    }
    std::cout << i << std::endl; // This line will be executed for i = 0 to 4
}
```
---
---
## Functions
- Functions encapsulate a set of instructions to perform a specific task, making code more modular, reusable, and easier to maintain.
---
  - **Modularity**: Breaking code into smaller, manageable functions makes it easier to understand, test, and maintain.
  - **Reusability**: Functions can be reused across different parts of a program or in different programs.
  - **Abstraction**: Functions provide a way to abstract complex operations, making the code easier to work with at a higher level.
  - **Maintainability**: Easier to update and fix bugs in smaller, isolated functions rather than in a large monolithic block of code.
  ---
- synthax : `return_type function_name(parameter_list) {}`
---
```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 5);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
```
---
### Things to Take Care Of
#### Function Declaration 
- Declare functions before they are used to inform the compiler about their existence.
- Especially important when functions are defined after the main() function or in other files.
```cpp
int add(int a, int b); // Function declaration

int main() {
    // Use the function here
}

int add(int a, int b) {
    return a + b;
}
```
---
#### Parameter Passing:
- Pass by Value: Copies the argument's value. Modifications inside the function do not affect the original value.
- Pass by Reference (&): Uses references to the original data, allowing the function to modify the argument.
- Pass by Pointer: Uses pointers to the original data, also allowing modification and useful for arrays and dynamic memory.
```cpp
#include <iostream>

// Function that takes an integer by value
void passByValue(int value) {
    value = 20; // Modifies only the local copy
    std::cout << "Inside passByValue: " << value << std::endl; //20
}

// Function that takes an integer by reference
void passByReference(int &ref) {
    ref = 30; // Modifies the original variable
    std::cout << "Inside passByReference: " << ref << std::endl;  //30
}

// Function that takes an integer by pointer
void passByPointer(int *ptr) {
    if (ptr) {
        *ptr = 40; // Modifies the original variable pointed to by ptr
        std::cout << "Inside passByPointer: " << *ptr << std::endl;  //40
    }
}

int main() {
    int a = 10;

    std::cout << "Before passByValue: " << a << std::endl;  //10
    passByValue(a);
    std::cout << "After passByValue: " << a << std::endl; //10

    std::cout << "Before passByReference: " << a << std::endl;  //10
    passByReference(a);
    std::cout << "After passByReference: " << a << std::endl; //30

    std::cout << "Before passByPointer: " << a << std::endl;  //30
    passByPointer(&a);
    std::cout << "After passByPointer: " << a << std::endl; //40

    return 0;
}
```
---
#### Const Correctness:
- Use const keyword to indicate that a function does not modify its arguments or its object state (for member functions).
```cpp
void printValue(const int &value) {
    std::cout << value << std::endl;
}
```
---
#### Default Arguments:
- Provide default values for parameters, allowing function calls with fewer arguments.
- always provide default arg at end of function args, - usecases :  you dont know 2d or 3d data : make z=0, you add new args in legacy codes.
```cpp
void printMessage(const std::string &message = "Hello, World!") {
    std::cout << message << std::endl;
}
```
---
#### Function Overloading:
- Define multiple functions with the same name but different parameter lists or different data types of parameter list.
```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}
```
---
#### Inline Functions:
- Use inline keyword to suggest that the compiler should expand the function body at the point of call to reduce function call overhead.
- can enhance performance by optimization. just replace the code at calling line, no need of copy and return.
```cpp
inline int add(int a, int b) {
    return a + b;
}
```
---
#### Recursion:
- Functions that call themselves. Ensure there is a base case to prevent infinite recursion.
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```
---
### Potential Pitfalls
- Too deep recursion can cause a stack overflow.
- Incorrectly handling pointers and references can lead to undefined behavior.
- Ensure proper initialization and avoid dereferencing null pointers.
---
---
## sizeof operator
- The sizeof operator is a compile-time operator in C++ that returns the size, in bytes, of a data type or an object. 
- It can return size of fixed size containers like arrays, etc.
- When use with `pointers` it give size of pointer, not what the pointer points to.
- Dont use sizeof operator for `class template` containers like `std::vector`, use size() member function.
- Dont use sizeof operator inside functions on arrays, which are passed as parmater.
---
---
## Const keyword 
- The `const` keyword in C++ is used to define constants and to prevent modification of variables, pointers, objects, or functions. It enhances code safety(immutability) and readability by clearly indicating which data or behavior should remain unchanged.
---
### UseCases
- **Constant Variables**
  - A variable declared with `const` cannot be modified after initialization.
  - `const int maxUsers = 100;`
  ---
- **Constant Pointers**
  - Pointer to a constant value.
  - Constant pointer.
```cpp
#include<iostream>

struct demo{
    int number{1};
    int getNumber(){
        return number;
    }
};

int main()
{
    int num1 = 4;
    int num2 = 5;

    const int *ptr = &num1; // ptr is a pointer to a constant Integer;
    //the value pointed by ptr cannot be changed
    // *ptr = 100; // this will give error
    ptr = &num2; //but ptr pointing can be changed.

    int *const ptr2 = &num1; // ptr2 is a Constant pointer to an integer
    //ptr2 itself cannot be changed to point to another address
    // ptr = &num2; //this will give you error
    *ptr2 = 100; //value stored at pointer can be changed

    const int *const ptr3 = &num1; // Both the value and the pointer are constant
    
    const demo obj;
    //obj.number = 5; // cant do this

    const demo* obj1 = new demo;
    // obj1->number = 6; //this will give error
    obj1 = &obj;// can do

    demo* const obj2 = new demo;
    // obj2 = &obj ; // error

    const demo* const obj3 = new demo ;
    
    return 0;

}
```
---
- **Constant Function Parameters**
  - Function parameters can be declared as const to prevent them from being modified inside the function.
```cpp
void printValue(const int value) {
    std::cout << value << std::endl;
}
```
---
- **Constant Member Functions**
  - A member function declared with const guarantees not to modify the object(variable) it is called on.
```cpp
class MyClass {
public:
    int getValue() const { return value; } // This function will not modify any member variables
private:
    int value;
};
```
---
- **Constant Return Types**
  - A function can return a constant value or a constant reference, ensuring the caller cannot modify the returned value or object.
  - `const int& getValue() const { return value; }`

## mutable keyword
- we are allowed to modify variables declared as mutable inside a constant function.
```cpp
struct Point2f{
  float m_x,m_y;
  mutable float m_w;
  explicit Point2f(float x,float y) : m_x(x), m_y(y), m_w(1.0f){}
  void changeW(float newW) const{
    w=newW;
  }
};
``` 

---
---
## typeid().name()
- tells the type of variable.
- present in header `<typeinfo>`
-  Eg : `typeid(x).name()`
---
---
## is_const()
- use `std::is_const` to check if a type is const at compile time.
- declared inside header `<type_traits>`.
```cpp
const int x=42;
cout << std::is_const<decltype(x)>::value ;
```
---
---
## decltype()
- It is a keyword in c++11 that allows you to query the type of an expression at compile time.
- It is **better than auto**.
---
- When to use it
  - **Type Deduction**: When you need to declare a variable with the same type as an expression.
```cpp
#include <iostream>

int main() {
    int x = 10;
    decltype(x) y = 20; // y has the same type as x, which is int
    std::cout << "Type of y: " << typeid(y).name() << ", Value of y: " << y << std::endl;
    return 0;
}
```
---
  - **Type Consistency**: Ensuring that a variable has the same type as another variable or expression, which is useful for maintaining type safety. 
```cpp
#include <iostream>

int main() {
    int a = 10;
    double b = 5.5;
    decltype(a + b) c = a + b; // c is of type double because a + b results in double
    std::cout << "Type of c: " << typeid(c).name() << ", Value of c: " << c << std::endl;
    return 0;
}
```
---
  - **Template Programming**: To deduce return types or member types in template functions and classes.
```cpp
#include <iostream>

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    std::cout << "Sum: " << add(10, 5.5) << std::endl; // The return type is deduced to be double
    return 0;
}
```
---
  - **Reference Types**: decltype preserves the exact type including references.
```cpp
int x = 0;
int& ref = x;
decltype(ref) y = x; // y is of type int& (reference to int)
``` 
--- 
  - **Using decltype with Expressions**: decltype can deduce the type of more complex expressions.
```cpp
struct S {
    double d;
};
S s;
decltype(s.d) d_var = s.d; // d_var is of type double
```
---
  - **decltype vs auto**:
  - auto deduces the type of a variable but does not always preserve the constness or reference qualifiers of the expression.
  - decltype preserves the exact type.
```cpp
const int ci = 0;
auto a = ci;       // a is int (const is discarded)
decltype(ci) d = ci; // d is const int

int a = 5;
int& ref = a;
auto b = ref;  // b is deduced as int, not int&

b = 10;  // This does not change the value of a

```
---
  - **Function Return Types**: decltype is useful for specifying return types of functions, especially when the return type depends on the type of the parameters.
```cpp
template <typename T, typename U>
auto multiply(T t, U u) -> decltype(t * u) {
    return t * u;
}
```
---
---
## std::fill
- A function to assign a given value to a range of elements.
- assign same value to all the elements.
- Synthax : `std::fill(start_iter, end_iter, value);`
```cpp
std::vector<int> vec(5);
std::fill(vec.begin(), vec.end(), 10);
```
---
---
## Address of operator
- The **address-of operator (&)** is used to obtain the memory address of a variable.
- The & operator can be used with any lvalue (an expression that refers to a memory location).
- Example: `int *ptr = &(x);` assigns the address of x to ptr.
- Use it when passing large structures or classes by reference to functions.
- good practice : treat address of as a function, use paraenthesis to enclose variable.
--- 
- It is used for 
  - **Aliases/References**: Refering a memory by another name.
  - **Pointers**: Storing the memory address of variables to enable indirect access and manipulation.
  - **References**: Passing arguments by reference to functions to avoid copying large amounts of data.
  
---
- Important points
  - The name of an array acts as a pointer to its first element, but using the address-of operator also same result can be obtained.
  - Eg : `int arr[5]; int* ptr = &(arr[0]);` is equivalent to `int *ptr = arr`.
  ---
  - usage of **Alias/References**
```cpp
int x = 10;
int &(ref) = x;
ref = 42;
std::cout << x << std::endl; //  x=42
```
  ---
  - **Pointers** : & is used to initialize pointers.
```cpp
int x = 10;
int *ptr = &(x);
int **ptr2 = &(ptr); // ptr2 now holds the address of ptr
```  
  ---
  - `char ch = 65; cout << &(ch);` it gives the char itself, as c++ treat char as string which is array of characters.
  - to obtain address of char use `(void*)&(ch);`.
---
---
## Pointers 
- A pointer is a variable that stores the memory address of another variable.
- Size of pointer on a 64 bit system is 8 bytes, because we want to potentially refer to anything using pointer.
---
### Need of pointers
- **Dynamic Memory Allocation**: Pointers allows the allocation and deallocation of memory at runtime using new and delete.
- **Pointer Arithematic**: Pointers enable efficient handling of arrays and strings, allowing direct manipulation of elements.
  - `arr[5]` is same as `*(arr + 5)`
- **Function Arguments**: Pointers can be used to pass arguments to functions by reference, enabling the function to modify the original variable.
- **Implementing Data Structures**: Pointers are crucial for implementing complex data structures like linked lists, trees, and graphs.
- **Performance**: Pointers can improve performance by avoiding the overhead of copying large amounts of data by passing data by reference. 
---
### Dereferencing
- Dereferencing a pointer means **accessing the value stored at the memory address** the pointer is pointing to.
- This is done using the * operator.
```cpp
#include <iostream>

int main() {
    int x = 10;
    int *ptr = &x; // ptr holds the address of x

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl; // Dereferencing ptr

    *ptr = 20; // Modify the value of x through ptr
    std::cout << "New value of x: " << x << std::endl;

    return 0;
}
```
---
### Cautions 
  - **Uninitialized Pointers**: Always initialize pointers. Uninitialized pointers can lead to undefined behavior.
  `int *ptr = nullptr; // Safe initialization`
  ---
  - **Dangling Pointers**: Pointers that reference memory that has been freed. Avoid using them by setting the pointer to nullptr after deallocation.
```cpp
int *ptr = new int(10);
delete ptr;
ptr = nullptr; // Prevents dangling pointer
```
  ---
  - **Pointer Arithmetic**: Be cautious with pointer arithmetic to avoid accessing out-of-bounds memory.
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
for (int i = 0; i < 5; ++i) {
    std::cout << *(ptr + i) << " "; // Valid access
}
```
  ---
  - **Null Pointers**: Always check if a pointer is nullptr before dereferencing it.
```cpp
int *ptr = nullptr;
if (ptr) {
    // Safe to dereference
    std::cout << *ptr << std::endl;
}
```
  ---
  - Memory leak 
  - Double free
---
### Memory Leak/New and Delete  
  - Memory Leaks: Ensure every new is paired with a delete to avoid memory leaks.
  - **new** : allocate memory in heap at runtime. It returns the size needed for datatype.
  - `new float[5];` is equivalent to `malloc(sizeof(float)*5);`
  - **delete** : deallocate heap memory.
  - `int* ptr = new int(10); delete ptr;`
  - for array's use `delete[] arr;`
---
### Function pointer
- Function pointers are pointers that points to the address of a function. they can be used to call functions and pass functions as arguments to other functions, enabling a form of callback functionality

- Why to use function pointers:
  - Callbacks : can be used to call specific function.
```cpp
#include <iostream>
#include <functional>

// Timer callback function
void on_timer() {
    std::cout << "Timer expired!" << std::endl;
}

// Function to set a timer with a callback
void set_timer(int seconds, std::function<void()> callback) {
    std::cout << "Setting timer for " << seconds << " seconds..." << std::endl;
    // Simulate a delay (not an actual timer implementation)
    callback();
}

int main() {
    set_timer(3, on_timer);
    return 0;
}
```
  - Flexibility : enable writing flexible and reuseable code, such as in event- driven programming.
```cpp
// generic sorting
#include <iostream>
#include <algorithm>
#include <vector>

// Comparison function for ascending order
bool ascending(int a, int b) {
    return a < b;
}

// Comparison function for descending order
bool descending(int a, int b) {
    return a > b;
}

// Function to print the elements of a vector
void print_vector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2};

    std::cout << "Original vector: ";
    print_vector(vec);

    std::sort(vec.begin(), vec.end(), ascending);
    std::cout << "Sorted in ascending order: ";
    print_vector(vec);

    std::sort(vec.begin(), vec.end(), descending);
    std::cout << "Sorted in descending order: ";
    print_vector(vec);

    return 0;
}
```
  - Dynamic Function calls : can be used to call different functions dynamically based on runtime conditions
```cpp
//Operation Selector
#include <iostream>

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int a = 10, b = 5;
    char operator;
    std::cout << "Enter an operator (+, -, *): ";
    std::cin >> operator;

    // Function pointer
    int (*operation)(int, int);

    switch (operator) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
            return 1;
    }

    int result = operation(a, b);
    std::cout << "Result: " << a << " " << operator << " " << b << " = " << result << std::endl;

    return 0;
}
```

- Declaration and Usage
  - Declaring : `return_type (*pointer_name) (parameter_types);`.
  - Assignment : `pointer_name = function_name;`.
  - Call : `pointer_name(arguments);`.
```cpp
#include<iostream>

typedef int(*FPIntegerOperations)(int , int );
int add(int x, int y){
    return x+y;
}
int multiply(int x, int y){
    return x*y;
}

int main()
{
    // function pointer
    // return type , name of pointer(parameters)
    FPIntegerOperations op;
    op=add;
    std::cout<< " Operation : " << op(2,3) << '\n';
    op= multiply;
    std::cout<< " Operation : " << op(2,3) << '\n';
    return 0;
}
```
---
---
## Move Semantics 
Move semantics is a feature introduced in C++11 to optimize the performance of C++ programs by eliminating unnecessary copying of objects, especially when dealing with temporary objects. This is achieved through move constructors and move assignment operators.

### lvalue
- A lvalue have a memory location.
- It genrally present at left side of assignment and represent a memory location.
- `x=14` x is a lvsalue here.

### rvalue
- a rvalue is an expression that does not refer to a memory location.
- If variable name is not given then it is a rvalue.
- it is a temporary value and usually appears on the right hand side of an assignment.
- `x=a+b;` a+b is a rvalue here.
- `x=54;`, 54 is a rvalue here.

### lvalue reference
- an lvalue reference is a **reference that binds to an value**.
- Synthax : `Type&`
- `int x = 10; int& ref = x` ref is an lvalue reference.
- `const int& ref = 10` ,with lvalue reference we cannot refer to rvalue, cannot create reference for constant directly, only works with const keyword added.
- It is used to pass large objects efficiently to avoid copying(pass by reference)

### rvalue reference
- move something already been created instead of copying it.
- Synthax : `Type&&`
- used in implementing move semantics
- avoid unnecessary copying of temporary objects.
```cpp
#include<iostream>

void func0(int num){ //cantake lvalue and rvalue both
    std::cout << "argument can be a lvalue and rvalue. \n";
}
void func1(int& num){ 
    std::cout << "only lvalue allowed. \n";
}
void setValue(const int& changeMe){
  std::cout << "called using a rvalue but stored as const. \n";
}
void func2(int&& num){
    std::cout << "only rvalue allowed.\n";
}
int main()
{
  int num = 10;

  func0(10);
  func0(num);

//   func1(0); //not allowed
  func1(num);

  setValue(10); 
  setValue(num);

  func2(10);
//   func2(num); //not allowed

  return 0;
}
```

### std::move
- allows the efficient transfer of resources from one object to another.
- std::move allows us to 'adopt' or steal the values.
- std::move is used to cast an lvalue to an rvalue reference, enabling move semantics.
```cpp
#include<iostream>
#includev<string>

int main()
{
  std::string mystr = "copy construct me";
  std::string newValue = std::move(mystr);
  // newValue = static_cast<std::string&&> (mystr);
  return 0 ;
}
```
---
---
## Smart pointers
- automatic memory management, no need of explicit delete.
- smart pointers are present in `<memory>` header. 
- goal of smart pointer is to make our life easy, so that we dont have to perform manual memory management.

### Unique pointer
- we cannot share resource between different pointers, only a single pointer will point to the resource at a time.
- We are not allowed to make copies, but can transfer ownership.

- Automatic release memory(delete) within the blocked scope.
- We can also write our own custom deleter, if we have to follow some steps always.
```cpp
#include<iostream>
#include<memory>

class UDT{
    public:
    UDT(){std::cout << "UDT created" << '\n';}
    ~UDT(){std::cout << "UDT Destroyed" << '\n';}
};
int main(){
    // UDT mike; //fine but static memory
    // UDT* mike = new UDT(); //probelm no auto delete
    
    //Creating a single unique pointer.
    // std::unique_ptr<UDT> mike = std::unique_ptr<UDT>(new UDT);
    //Equivalent to above line , make_unique
    std::unique_ptr<UDT> mike = std::make_unique<UDT>();

    //Creating a array of 10 unique pointers.
    // std::unique_ptr<UDT[]> mike_array = std::unique_ptr<UDT[]>(new UDT[10]);
    //Equivalent to above line , make_unique
    std::unique_ptr<UDT[]> mike_array = std::make_unique<UDT[]>(10);

    // std::unique_ptr<UDT> joe = mike; //not allowed
    std::unique_ptr<UDT> joe = std::move(mike); // allowed

    return 0;
}
```
- `std::make_unique` uses factory pattern.

### shared pointer
- a smart pointer that retains shared ownership of an object, several shared_ptr may own the same object.
- helps us avoid calling new and delete.
- The object is destroyed and its memory is deallocated when 
  - the last remaining shared_ptr owning the object is destroyed.
  - the last remaining shared_ptr owning the object is assigned another object.
- this is done by keeping track(maintaining a reference count for particular resource) of shared pointers
```cpp
#include<iostream>
#include<memory>

class UDT{
    public:
    UDT(){std::cout << "UDT created" << '\n';}
    ~UDT(){std::cout << "UDT Destroyed" << '\n';}
};
int main(){
    
    std::shared_ptr<UDT> mike = std::make_shared<UDT>();
    
    std::shared_ptr<UDT> joe = mike;//allows sharing of resouce.
    std::cout << joe.use_count() << '\n'; //reference count
    return 0;
}
```
- reference count is thread safe.

## weak pointer
- it is a smart pointer that holds a non-owning reference, so it does not increase the resource referene count.
- it models temporary ownership.
- it must be converted to shared pointer in order to access the referenced resource.
- it is a safer way to have dangling pointer.
- it is used to break reference cycles.

```cpp
#include<iostream>
#include<memory>

class UDT{
    public:
    UDT(){std::cout << "UDT created" << '\n';}
    ~UDT(){std::cout << "UDT Destroyed" << '\n';}
};
int main(){
    
    std::weak_ptr<UDT> joe ;
    {
        std::shared_ptr<UDT> mike = std::make_shared<UDT>();
        joe = mike;//reference count not updated
        std::cout << "UDT reference count : " << mike.use_count() << '\n';
    }
    std::cout << "is weak ptr expired " << joe.expired() << '\n';
    
    return 0;
}
```

## Interface .hpp vs .cpp file
- Interface contains high level view of the code we are including.
- It contains declaration of classes, functions, variables, etc. It doesn't know how these things work but know that these things exists.
- .cpp file contains the actual implementation of all the things.
- must apply header guard in .hpp file, `#ifndef MIKE.hpp  #define MIKE.hpp ... #endif`

# Classes
- A class is a user-defined type
- it contain data(member variables) and actions(member functions) associated with data.
- classes can have components as public, private and protected.
- classes allow us to create instances of class and each instance can have its data independent of other instances.
- whenever you create a class, compiler generates `default constructor, copy constructor, copy assignment operator and default destructor ` if needed and if we doesn't provide anyone of them explicitely.

## Constructors
### Default constructor 
- C++ provide us default constructor and default destructor, if we dont provide any constructor/destructor explicitely.
- always write your own constructors

### copy constructor and copy assignment operator
- use to copy values from another object to current object.
- c++ also provides us by default, compiler generated copy constructor and copy assignment operator, but it does shallow copy.
- Use copy constuctor or copy assignment operator if you want to do deep copy.
- copy constructor called if object declaration and assignment at the same time.
- copy assignment operator called when declaration is done earlier and later doing assignment.
   
```cpp
#include<iostream>

class Student{
    public:
        Student(){
            arr = new int[10];
            for(int i=0; i<10; i++)
            {
                arr[i] = i*i;
            }
        }
        //Copy cosnstructor
        // Student Array = someExistingArray.
        Student(const Student& obj)
        {
            arr = new int[10];
            for(int i=0; i<10 ;i++)
            {
                arr[i]=obj.arr[i];
            }
        }
        //Copy assignment operator
        // Student arr;
        // arr = some existing array;
        Student& operator = (const Student& obj)
        {
            if(this != &this)
            {
                for(int i=0; i<10; i++)
                {
                    arr[i]=obj.arr[i];
                }
            }
            return *this;
        }
        void printdata(){
            std::cout << "arr is : ";
            for(int i=0; i<10; i++)
            {
                std::cout << arr[i] << ' '; 
            }
            std::cout << '\n';
        }
        void setdata(int index, int value)
        {
            arr[index]=value;
        }
        ~Student(){
            delete[] arr;
        }
    private:
        int* arr;  
};
int main()
{
    Student mike;
    Student pratham = mike;  //deep copy explicit copy constructor
    Student om; 
    om=mike;  //copy assignment operator.

    mike.setdata(0,10);
    mike.setdata(1,20);
    mike.setdata(2,30);

    mike.printdata();
    pratham.printdata();
    om.printdata();
    return 0;
}
```
### Rule of 3
- If you want to define anyone of custom destructor, custom copy constructor, custom copy assignment operator then you must implement all of them .
-It is considered as a best practice.
- Law of the big two : if a class uses RAII (pnly smart pointers, collections, etc)
, the the destructor may be left undefined

## Operator overloading.
- think of operators as functions.
```cpp
#include<iostream>

class complex{
    private:
        int real;
        int img;
    public:
        complex():real(0),img(0){}
        complex(const int r,const int i):real(r),img(i){}
        complex(const complex &rhs){
            if(this != &obj)
            {
                real = rhs.real;
                img = rhs.img;
            }
        }
        complex& operator=(const complex &rhs)
        {
            if(this != &obj)
            {
                real = rhs.real;
                img = rhs.img;
                return *this;
            }
        }
        complex operator + (const complex& rhs) const {
            complex res;
            res.real = real + rhs.real;
            res.img = img + rhs.img;
            return res;
        }
        complex& operator ++ ()
        {
            real++;
            img++;
            return *this;
        }
        bool operator ==(const complex& rhs) const
        {
           return real==rhs.real && img ==rhs.img; 
        }
        friend std::ostream& operator << (std::ostream& os, complex &rhs);
        ~complex(){}        
};
std::ostream& operator << (std::ostream& os, complex &rhs)
{
    os<< rhs.real << " + " << rhs.img << "i .\n";
    return os;
}
int main()
{
    complex num1(8,9);
    complex num2(4,5);
    complex num3 = num1+num2;
    ++num3;
    std::cout << num3;
    std::cout << (num3==num1) << '\n';
    return 0;
}
```
## Member Initializer lists
- in c++ first we construct the objects(assign memory to member variables) and after that we assign some value to the variables. so  its a two step process.
- But using member initializer list we can assign memory to variable and initialize them with some value at the same time.
- using regular assignment, compiler first creates temporary copies of parameters, which are then passed to member variables, BUT using initializer list compiler doesnt make copies of the objects.
- just use a comma seperated list in constructor.
- to avoid unexpected behaviour, keep the order of initializer list same as the order of member varible declaration.
- `complex(int real, int float): m_real(real),m_img(img){}`
```cpp
#include <iostream>
class collection{
    private:
        int* m_data;
    public:
        collection():m_data(new int[10]){}    
};
```

## Structs 
- structs are user defined types.
- struct and class are same, except for member access.
- the default member access for struct is `public`, whereas for classes it is `private`. 
- they are included in c++ to keep the language compatible with c.
- In c++ they are used to make simple types with some member variables, dont add too many things in it.

## RAII
- It helps us acquire resource before use(allocat heap memory) and free them in correct order.
- It used scope, lifetime of objects.

## Rule of Five
- define destructor, copy constructor, copy assignment operator, move constructor and move assignment operator explicitely.
- `Array(Array&& source);`
- `Array& operator=(Array&& source);`

```cpp
#include<iostream>
#include<string>
#include<vector>

class Array{
    private:
        std::string m_name;
        int* m_data;

    public:
        Array():m_name(""),m_data(new int[10]) //default constructor
        {
            std::cout << m_name << " is default constructed.\n";
        };   
        Array(std::string name):m_name(name),m_data(new int[10]) //parameterised constructor
        {
            std::cout << m_name << " is constructed.\n";
        };
        ~Array() //destructor
        {
            std::cout << m_name << " is destructed.\n";
            delete[] m_data;
        }
        Array(const Array& rhs) // copy constuctor
        {
            m_name = rhs.m_name;
            std::cout << m_name << " is copy constructed.\n";
            m_data = new int[10];
            for(int i=0; i<10 ; i++)
            {
                m_data[i] = rhs.m_data[i];
            }
        }   
        Array& operator=(const Array& rhs) // copy assignment operator
        {
            if(this != &rhs)
            {
                m_name = rhs.m_name;
                std::cout << m_name << " is copy assignment operator constructed.\n";
                m_data = new int[10];
                for(int i=0; i<10 ; i++)
                {
                    m_data[i] = rhs.m_data[i];
                }
            }
            return *this;
        }  
        Array( Array&& rhs) //move constructor
        {
            m_name = rhs.m_name;
            rhs.m_name = "";
            std::cout << m_name << " is move constructed.\n";
            m_data = rhs.m_data;
            rhs.m_data = nullptr;
        } 
        Array& operator=(Array&& rhs) //move assignment operator
        {
            if(this != &rhs)
            {
                m_name = rhs.m_name;
                std::cout << m_name << " is copy assignment operator constructed.\n";
                rhs.m_name = "";
                m_data = rhs.m_data;
                rhs.m_data = nullptr;
            }
            return *this;
        }  
};

Array foo()
{
    Array arr("Foo array");
    return arr;
}
int main()
{
    // Array arr1("arr1");
    // Array arr2 = arr1;  // copy constructor

    // Array arr1 = foo();    // no copies are made because of compiler optimistation. we dont have to reconstruct the resource, arr is directly assigned to arr1. It is called return value optimisation.

    std::vector<Array> myArrays;
    myArrays.reserve(10); //optimisation else recursive copies , becoz of how vector works.
    for(int i=0; i<10; i++)
    {
        Array temp(std::to_string(i));
        // myArrays.push_back(temp); //copy constructor called
        myArrays.push_back(std::move(temp)); //move constructor called, further optimisation.
    }
    return 0;
}
```
## Friend functions
- allows acess to private members of the class.
- Declare it in public, private or protected section of the class, doesn't matter.
- even classes can be friend.
- try to avoid friend function and classes.
```cpp
#include<iostream>

class privateSecurityInfo{
    friend class UserDefinedType; //friend class
    private:
    int passcode;
};
class UserDefinedType{
    public:
    UserDefinedType(): m_privateMemberVariable(0){
        m_info.passcode = 7; //friend class
    }
    private:
    int m_privateMemberVariable;
    privateSecurityInfo m_info;
    friend void PrintPrivateMemberVariablesOfUDT(UserDefinedType u); //friend function
};
void PrintPrivateMemberVariablesOfUDT(UserDefinedType u){
    std::cout << "m_privateMemberVariable : " << u.m_privateMemberVariable << '\n';
}
int main()
{
    UserDefinedType instance;
    PrintPrivateMemberVariablesOfUDT(instance);
    return 0;
}
```
## Explicit constructor and list initialization
- avoides implicit conversions, eg from float to int.
```cpp
#include <iostream>
#include <string>

class udt{
    public: 
    explicit udt(int i){ //explicit constructor
        m_variable = i;
    }
    private:
    int m_variable; 
};
int main()
{
    udt u1{500}; // list initialization avoid narrowing
    return 0;
}
```
## Inheritance
- a derived class(subclass) inherits traits from base class(class).
- creates new classes from existing classes, and change how object behave.
- Inheritance `IS-A` relationship

### Different access level specifiers public, private and protected.
### Different constructor called during inheritance

## Virtual Keyword
### Virtual functions
- dynamic dispatch : at runtime find the correct function to call.
- for `Base* instance = new Derived`, if we call a memFunc() that is present in both base and derived, base function will be called, to fix this problem make function in base as `virtual` and `override` in derived class.
```cpp
#include<iostream>
class Base{
    public:
    virtual void MemFunc()
    {
        std::cout << "Base::MemFunc()" << '\n';
    }
};
class Derived : public Base
{
    public:
    void MemFunc() override
    {
        std::cout << "Derived::MemFunc()" << '\n';
    }
};
int main()
{
    Base* instance = new Derived;
    instance->MemFunc();
    delete instance;
    return 0;
}
```
### Virtual Destructors
- In case of heap allocated object, to call the correct destructors, make base destructors as virtual for inheritance based polymorphism.
- `virtual ~Base(){}`

### vtable
- if there is atlest one virtual function in a class, we have a vtable for that class,there is a pointer(member variable) vptr for the class that points to this vtable.
- when a virtual function is called by a heap allocted object, th vtable points us to the right function.

## Interfaces
- It is also called as Abstract class.
- We implement interfaces in cpp using pure virtual functions.
```cpp
#include <iostream>

class IRenderer{
    public:
    virtual void Draw() = 0; //pure virtual function = 0.
    virtual void Update() = 0;
    virtual void extraFunction()=0;
};

class OpenGL : public IRenderer{
    public: 
        void Draw() override{
            std::cout << "OpenGL::Draw.\n";
        }
        void Update() override{
            std::cout << "OpenGL::Update.\n";
        }
        void extraFunction() override{
            std::cout << "OpenGL::ExtraFunction.\n";
        }; 
};
class Vulkan: public IRenderer{
    public:
        void Draw() override{
            std::cout << "Vulkan::Draw.\n";
        }
        void Update() override{
            std::cout << "Vulkan::Update.\n";
        }
        void extraFunction() override{
            std::cout << "Vulkan::ExtraFunction.\n";
        }; 
};
int main()
{
    IRenderer* myRenderer = new OpenGL;
    myRenderer->Update();
    myRenderer->Draw();
    myRenderer->extraFunction();

    return 0;
}
```
## Multiple Inheritance (Caution)
- diamond problem
```cpp
#include<iostream>

struct Dog{
    virtual void Bark() {
        std::cout << "Dog::Bark.\n";
    }
};
struct Golden :public Dog{
    virtual void Bark() override{
        std::cout << "Golden::Bark.\n";
    }
};
struct BorderCollie :public Dog{
    virtual void Bark() override{
        std::cout << "BorderCollie::Bark.\n";
    }
};
struct Coltriever : public Golden, BorderCollie{
    // void Bark() override{
    //     std::cout << "Coltriever::Bark.\n";
    // }
};
int main()
{
    Dog* dog = new Dog;
    Dog* golden = new Golden;
    Dog* borderCollie = new BorderCollie;
    Dog* coltriever = new Coltriever; //works with c++20

    dog->Bark();
    golden->Bark();
    borderCollie->Bark();
    coltriever->Bark();

    return 0;
}
```
### Need of virtual Inheritance
```cpp
#include <iostream>

struct Entity{
    int x{4},y{5};
};
struct Warrior : public Entity{
    int power{10};
};
struct Goblin : public Entity{
    int power{7};
};
struct Player : public Goblin, public Warrior{
};
int main(){
    Player mike;
    // std::cout << mike.x << '\n'; // x is ambigious
    std::cout << mike.Warrior::x << '\n';
    std::cout << mike.Warrior::y << '\n';
    
    std::cout << mike.Goblin::x << '\n';
    std::cout << mike.Goblin::y << '\n';

    std::cout << mike.Goblin::power << '\n';
    
    // Instead make use of virtual inheritance.
    
    return 0;
}
```
## virtual Inheritance
- Virtual Inheritance is a technique which ensures only one copy of a base class member variables are iniherited by grandchild derived classes
- It merges all of the member variables.
```cpp
#include <iostream>

struct Entity{
    int x{4},y{5};
};
struct Warrior : virtual public Entity{
    int power{10};
};
struct Goblin : virtual public Entity{
    int power{7};
};
struct Player : public Goblin, public Warrior{
};
int main(){
    Player mike;

    std::cout << mike.x << '\n'; // Globlin variable as Globlin is written first for inheritance.
    std::cout << mike.y << '\n';

    std::cout << mike.Warrior::y << '\n'; //also works

    // std::cout << mike.power << '\n'; //doesnt work even we make Player inheritance as virtual.
    std::cout << mike.Goblin::power << '\n';
    return 0;
}
```

## Curly Braces initializer list.
- curly braces prevents narrowing.
- a std::initializer_list is a lightweight array like container which keeps track of size and we can also iterate through this data.
- As a initializer list `std::vector<int> v{1,2,3};`.
- using parenthesis `std::vector<int> v(1,2,3);` is not allowed becoz constructor is not defined for it.
- `std::vector<int> v(10,1);` it creates a vector of size 10 and initialize them with value 1.
```cpp
#include <iostream>
#include <initializer_list>

class UDT{
    public:
    UDT(std::initializer_list<int> data): m_data (data)
    {
        std::cout << "initializer list constructor. \n";
    }
    UDT(int a, int b, int c)
    {
        std::cout << "constructor with 3 parameters. \n";
    }
    ~UDT(){}
    void printData(){
        for(auto& e:m_data){
            std::cout << e << ',';
        }
        std::cout << '\n';
    }

    private:
    std::initializer_list<int> m_data;
};
int main(){
    UDT u{1,2,3}; // init list constructor
    UDT u1(1,2,3); // 3 para constructor
    u.printData();
    return 0;
}    
```
## Composition and Aggregation
- Composition : `HAS-A` relationship.
- In composition one class object is contained within another.
```cpp
struct Point2D{
    int x,y;
};
class Character{
    public:
        Character() { }
        ~Character() { }
    private:
        Point2D m_position;
        Point2D m_direction;
}
```
- Aggregation is also a type of composition but the lifetime of contained object is not necessarily tied to the object.
```cpp
struct Point2D{
    int x,y;
};
class Character{
    public:
        Character(Point2D& ref): ref_home(ref) { }
        ~Character() { }
    private:
        Point2D& ref_home;
}

int main()
{
    Point2D somePoint;
    Character mike(somePoint);

    return 0;
}
```

## Value Initialization
- To avoid garbage value, always initialize your member variables.
- To zero initialize object use `{}` in front of object creation.
- In class Init and constructor Init has more priority than this.
```cpp
#include <iostream>
#include <string>

struct Entity{
    Entity() : name("mike"), x(0), y(0), collection(nullptr){
    }
    std::string name;
    int* collection;
    int x;
    int y;
};

int main(){

    // Entity e; //assign variables garbage values.
    Entity e{}; //zero intialize variables except string iff no explicit constructor is defined.
    // else if constructor = default;
    std::cout << e.name << '\n';
    std::cout << e.collection << '\n';
    std::cout << e.x << '\n';
    std::cout << e.y << '\n';

    return 0;
}
```

##  In class Initializer.
- constructor Init has more precedence than InClass Initializer.
```cpp
#include <iostream>
#include <string>

struct Entity{
    // Entity() : name("mike"), x(0), y(0), collection(nullptr){
    // }
    std::string name;
    int* collection{nullptr};
    int x{4}; //inclass initializer
    int y{5};
};

int main(){

    Entity e; 

    std::cout << e.name << '\n';
    std::cout << e.collection << '\n';
    std::cout << e.x << '\n';
    std::cout << e.y << '\n';

    return 0;
}
```

## Delegating constructor
- Dont repeat yourself.
```cpp
#include <iostream>
#include <string>

struct Entity{
    public:
    Entity() : name {}, x{0}, y{0}, collection{nullptr}{
        init();
    }
    Entity(std::string _name) : Entity(){ //delegate constructor.
    // Call to another constructor
        name = _name;
    }
    void printData(){
        std::cout << "Name = " << name << '\n';
        std::cout << "X = " << x << '\n';
        std::cout << "Y = " << y << '\n';
        std::cout << "Pointer = " << collection << '\n';
    }


    private:
    std::string name;
    int x{0};
    int y{0};
    int* collection{nullptr};

    void init(){
        name = std::to_string(x) + std::to_string(y);
    }
};
int main()
{
    Entity e1("mike");
    e1.printData();

    return 0;
}
```

## Optimising class size
- for `bool, float and short` it should have taken 7 bytes of size but it actually takes 12 bytes of size because of padding.
- `1 byte bool + 3 byte padding` + `4 byte float` + `2 byte short + 2 byte padding` = total 12 bytes.
- To optimise `arrange the variables from largest to shortest size`.

## pIMPL (pointer to implementation) : more stable
- To hide implementation from client.
```cpp
#include<iostream>
#include<string>
#include<memory>

class Person{
    private:
        struct pImplPerson{
            std::string m_name;
            std::string m_strength;
            std::string m_speed;
        };
        std::unique_ptr <pImplPerson> m_impl;

    public:
        Person(std::string s){
            m_impl = std::make_unique<pImplPerson>();
            m_impl->m_name = s;
            m_impl->m_strength = "n/a";
            m_impl->m_speed = "n/a";
        }  
        ~Person(){}
        std::string GetAttributes(){
            return m_impl->m_name + ", "+ m_impl->m_strength + ", "+m_impl->m_speed + '\n';
        }  
};
int main(){
    Person mike("mike");
    std::cout << mike.GetAttributes() ;
}
```
- Another way is to pass a struct with different functions and member variables to a function, so that we need to pass only one parameter.
## This Keyword
- This is a pointer to current instance of object, which stores the address of current instance of object.
```cpp
#include <iostream>

class Person{
    public:
        Person(int age){
            // age = age; //ambigious
            this->age = age;
        }
        int getAge() const{
            return age;
        }
        Person* getThisAddress(){
            return this;
        }
    private:
        int age;
};
int main(){
    Person mike(50);
    std::cout << mike.getAge() << '\n';
    std::cout << mike.getThisAddress() << '\n';
    std::cout << &mike << '\n';

    std::cout << "\n Heap allocated.\n";
    Person* rishi = new Person(35);
    std::cout << rishi->getThisAddress() << '\n';
    std::cout << rishi << '\n';

    return 0;
}
```

## Static Keyword
- Stack memory gets deallocated automatically when out of scope. It is a smaller memory (512 kb).
- Heap memory remains until we explicitely delete the object. Its relatively very large memory (some GBs).
- Static is another type of storage, static variables are allocated in the actual executable
- Static keyword have a block scope for access but its lifetime is the lifetime of the project.
- It is only initialized one time.
- Inside a class we can declare a variable as `inline static int var = 37;` , which is same as `static constexpr int var = 37`. 
```cpp
#include <iostream>

void foo(){
    static int static_variable = 0;
    static_variable += 1;

    std::cout << static_variable << ' ';
}
int main()
{
    for(int i=0; i<10; i++){
        foo();
    }
    // static_variable = 10; //out of scope
    
    return 0;
}
```
### Static in class
- Static varibles in a class exist outside of the class, they have their own storage, but their scope is within the class.
- They are instance/object independent, they live on their own.
- we can also have static member functions in a class
```cpp
#include <iostream>

struct API{
    API() { }
    ~API() { }
    
    static int MAJOR;
    const static int MINOR = 5;  //declaration

    static int getMajor(){
        return MAJOR; //only static variables can be manipulated or returned.
    }
};
int API::MAJOR =10; //defination
 //we need to use scope resolution operator as static variables have class scope.

int main()
{
    API instance;
    std::cout << instance.getMajor() << '\n';
    return 0;
}
```

# Templates 
- It is also called "Generics". It introduces genericity in code, and increase code reuseability.
- It serve as a blueprint for compiler to generate code for us.
- Synthax : `template <typename/class T> void...`
- Templates have proceeding block scope, means it is only available for one function or class.
- Instantation means generation of our overloaded function.

```cpp
#include<iostream>

template <typename T>
T square(T input){
    return input*input;
}
int main(){
    std::cout << square<int>(5) << '\n';
    std::cout << square<int>(5.5f) << '\n';
    std::cout << square<double>(6.25) << '\n';

    return 0;
}
```
- we can also use auto keyword instead of template.
- for multiple template parameter take caution of the order of parameter which you are passing to function, else many functions will be created.
- we can also use non-object type ,eg `template <typename T1, size_t N>.

## Template specialization
- What if we want a different code for a particular data type? It is possible in C++ to get a special behavior for a particular data type. This is called template specialization. 
- In C++, partial template specialization allows us to define a specialized version of the template for some of the template arguments in contrast to full template specialization which requires all the arguments to be defined.
- may need specialization for a variety of cases like choosing a sorting algorithm based on size of container.
```cpp
#include<iostream>
#include<cmath>

template <typename T>
bool equal(T a, T b){
    return a==b ;
}
template<>  //specialization for float
bool equal<float> (float a, float b)
{
    std::cout << "equal<float>. \n";
    return std::fabs(a-b) < 0.00001f;
}
template<>  //specialization for double
bool equal<double> (double a, double b)
{
    std::cout << "equal<double>. \n";
    return std::fabs(a-b) < 0.00000001f;
}
int main(){

    std::cout << equal<int>(2,2) << '\n';
    std::cout << equal<int>(2,3) << '\n';
    std::cout << equal<float>(1.0f-0.999999f, 0.000001f) << '\n';
    std::cout << equal<double>(1.0f-0.999999999f, 0.000000001f) << '\n';

    return 0;
}
```
- Partial template specialization.
```cpp
template <class T, class X>
class Geek {
      // General implementation for the primary template
};
template < class T> //partial specialization.
class Geek<T, int> {
      //  Specialized implementation for the primary template
}
```
## Variadic Templates
- functions with multiple undefined number of parameters.
- we make use of ` parameter pack`. 
```cpp
#include <iostream>
template<typename T>
T sum(T arg){
    return arg;
}
template <typename T, typename... args>
T sum(T start, args... arg){
    return start + sum(arg...);
}
int main(){
    std::cout << sum(1,2,3,4,5) << '\n';
    std::cout << sum(1,2,3) << '\n';
    std::cout << sum<double, double>(1,2.2,3) << '\n';

    return 0;
}
```
## class Templates
```cpp
#include <iostream>

template<typename T=int, int Size = 10> // default size if not specified.
class Container{
    public:
    Container(){
        m_data = new T[Size];
    }
    ~Container(){
        delete[] m_data;
    }

    static T m_variable; //every instantiated class will have its own copy of static variable.

    private:
    T* m_data;
};
//static member variable telling compiler , he exists
template <typename T, int Size>
T Container<T, Size>::m_variable ;

int main(){
    Container<int, 5> c();
    Container<int, 5> c1();
    Container<int,5>::m_variable =7;//initializing static member variable.  
    // Container<double, 7> c2();
    // Container<float, 5> c3();

    return 0;
}
```
## Class template Argument Deduction (CTAD)
- no need to explicitely specify the template argument, compiler will automatically deduce the type, based on its intellegence.


# Unions
- unions differs from a struct in a way that it only holds the largest type.
- Union limitations, no virtual functions, cannot have base class or used as a base class, cannot have non-static data members of reference types.
```cpp
#include <iostream>

union U{
    int i;
    short s;
    float f;

    void printf()
    {
        std::cout << "float " << f << '\n' ;
    }
};
int main(){
    U myUnion ;
    myUnion.i = 33365;

    std::cout << "int " << myUnion.i << '\n'; 
    std::cout << "short " << myUnion.s << '\n'; 

    std::cout << sizeof(myUnion) << '\n';

    myUnion.printf();

    return 0;
}
```

# Variant
- `std::variant` is a type-safe union in C++17 that can hold one of several different types, providing a way to define a variable that can store different types of values at different times. 
- Unlike traditional unions, std::variant handles the construction and destruction of its contained values correctly, ensuring type safety and managing resources properly.
```cpp
#include <iostream>
#include <variant>
#include <string>

// Define a variant type that can hold int, float, or std::string
using MyVariant = std::variant<int, float, std::string>;

// Visitor functor to print the value stored in the variant
struct PrintVisitor {
    void operator()(int value) const {
        std::cout << "int: " << value << std::endl;
    }

    void operator()(float value) const {
        std::cout << "float: " << value << std::endl;
    }

    void operator()(const std::string& value) const {
        std::cout << "string: " << value << std::endl;
    }
};

int main() {
    MyVariant v;

    // Assign an int to the variant
    v = 42;
    std::visit(PrintVisitor(), v); // Outputs: int: 42

    // Assign a float to the variant
    v = 3.14f;
    std::visit(PrintVisitor(), v); // Outputs: float: 3.14

    // Assign a std::string to the variant
    v = std::string("Hello, Variant!");
    std::visit(PrintVisitor(), v); // Outputs: string: Hello, Variant!

    // Check the currently active type
    if (std::holds_alternative<int>(v)) {
        std::cout << "Variant holds an int" << std::endl;
    } else if (std::holds_alternative<float>(v)) {
        std::cout << "Variant holds a float" << std::endl;
    } else if (std::holds_alternative<std::string>(v)) {
        std::cout << "Variant holds a string" << std::endl;
    }

    return 0;
}
```
## constexpr keyword
constexpr is a keyword introduced in C++11 that allows expressions to be evaluated at compile time. It is used to define constants and functions that can be evaluated at compile time, providing potential performance improvements by shifting computations from runtime to compile time.
- Type Safety: Ensuring that certain values are constants and known at compile time can lead to safer and more predictable code.
```cpp
#include <iostream>

class Point {
public:
    constexpr Point(int x, int y) : x_(x), y_(y) {}

    constexpr int getX() const { return x_; }
    constexpr int getY() const { return y_; }

private:
    int x_;
    int y_;
};

int main() {
    constexpr Point p(10, 20); // Constructed at compile time
    static_assert(p.getX() == 10, "Compile-time check failed!");

    std::cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    return 0;
}
```
# Assert and Static assert statements
Assertions are used in C++ to check assumptions made by the program and to catch programming errors during development. 
- `assert` : The assert macro, defined in the `<cassert>` header, is used to perform runtime checks. If the condition provided to assert is false, the program prints an error message and terminates.
```cpp
#include <iostream>
#include <cassert>

int main() {
    int x = 10;
    int y = 0;

    // Runtime assertion
    assert(y != 0 && "Division by zero!");

    int result = x / y; // This line won't be executed if assert fails

    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
- `static_assert` : The static_assert keyword, introduced in C++11, is used to perform compile-time checks. If the condition provided to static_assert is false, the compiler generates an error message.
```cpp
#include <iostream>

template <typename T>
void checkType() {
    static_assert(sizeof(T) == 4, "T must be 4 bytes");
}

int main() {
    checkType<int>();    // Passes because sizeof(int) is 4 on most systems
    checkType<double>(); // Fails because sizeof(double) is not 4

    return 0;
}
```
# auto keyword
The auto keyword in C++ is used for type inference, allowing the compiler to automatically deduce the type of a variable from its initializer. Introduced in C++11, auto simplifies code and reduces redundancy by eliminating the need to explicitly specify types.
- Flexibility : Helps in scenarios where the type might change, reducing the need to update type declarations manually.
- be cautious when to use auto and when not, eg: string and char*. dont use until you know the type of variable, becoz if u dont understand the type , how will u know whats wrong with code.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <functional>

// Function returning an auto type
auto createVector() {
    return std::vector<int>{1, 2, 3, 4, 5};
}

int main() {
    std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}, {"three", 3}};

    // Use auto for iterator
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << '\n';
    }

    auto vec = createVector();
    // Use auto in range-based for loop
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << '\n';

    // auto in lambda expressions to deduce parameter types and return types.
    auto add = [](auto a, auto b) { return a + b; };

    std::cout << add(2, 3) << std::endl;          // Output: 5

    return 0;
}

```
# Casting
- C style cast is most powerful and tries all of the below.
- avoid casting wherever possible, prefer dynamic_Cast if must, unless if you need performance try static_cast.

## Why Different Types of Casting?
- Type Safety: C++ casts are more type-safe, ensuring that only appropriate conversions are allowed.
- Clarity: Different casts make the programmer's intentions explicit, improving code readability and maintainability.
- Debugging and Maintenance: C++ casts make it easier to spot potential issues and understand the code during debugging and maintenance.
## Static cast
- used for safe, well defined casts between related types. It performs implicit conversation
- synthax : `static_cast<new-type>(expression)`
- static_cast attempt at compile time . 
```cpp
#include<iostream>

int main()
{
    float f {3.14f};
    int i = static_cast<int>(f);

    return 0;
}
```
- problem
```cpp
#include<iostream>

struct Base{
    int baseData{1};
    Base(){baseData=11;}
    virtual void Do (){
        std::cout << "Base::Do()\t" << baseData << '\n';
    }
};
struct Derived: public Base{
    int deriveData{2};
    Derived(){deriveData=22;}
    void Do (){
        std::cout << "Base::Do()\t" << deriveData << '\n';
    }
};
int main()
{
    // stack objects
    Base b;
    Derived d;

    b.Do();
    d.Do();

    (static_cast<Base>(d)).Do(); //If Inherited from base, works.
    // (static_cast<Derived>(b)).Do(); // wont work even if base::Do is virtual
    
    return 0;
}
```
## Dynamic cast
- safely converts `pointers` and `references` to classes up, down and sideways along th inheritance hierarchy.
- synthax : `dynamic_cast<new-type>(expression)`
- dynamic_cast attempt at runttime to do the conversion and if it fails it returns the null pointer.
- It is more expensive than static_cast.
- Use when `Parent* ptr = new Child;` and we have to use some child function that is not present in parent.
```cpp
#include <iostream>
#include <string>

struct Parent{
    std::string m_surname;

    Parent(std::string surname): m_surname(surname){}

    std::string getSurname(){
        return m_surname;
    }
    virtual void somefun(){
        std::cout << "Parent::somefun. \n";
    }
};
struct Child : public Parent{
    std::string m_name;

    Child(std::string name, std::string surname) : m_name(name),Parent(surname) {}

    std::string getName(){
        return m_name;
    }
    void somefun() override {
        std::cout << "Child::somefun \n";
    }
};
int main(){
    Parent* obj = new Child("Pratham","Kangane");

    // std::cout << obj->getName() << '\n'; //cannot access name of object

    Child* obj1 = dynamic_cast<Child*>(obj);
    std::cout << obj1->getName() << '\n';
    std::cout << obj1->getSurname() << '\n';
    obj1->somefun() ;

    return 0;
}
```
## Reinterpret cast
- reinterpret cast literally interpret the bytes as whatever type you decide to treat the raw bytes.
- Its the last type of cast you should try.
```cpp
#include <iostream>

int main()
{
  float pi =3.14f;

  std::cout << *reinterpret_cast<int*>(&pi) << '\n';
  std::cout << *reinterpret_cast<float*>(&pi) << '\n';
  //goto address of pi, treat the bytes as float, return a pointer, dereference it to retive value form pointer.
  return 0;
}
```
- Another use
```cpp
#include <iostream>
#include <cstring>

struct gameState{
  int level;
  int health;
  int points;
  bool GameCompleted;
  bool BossDefeated;
};

int main()
{
  //create some gs object.
  gameState gs = {66, 100, 999, false, true};
  //allocate some memory to store gs bytes.
  char bagOfBytes[sizeof(gs)]; 
  // store bytes into bag of bytes.
  memcpy(bagOfBytes, &gs, sizeof(gs));
  //read the data
  std::cout << *reinterpret_cast<int*>(bagOfBytes) << '\n';
  std::cout << *reinterpret_cast<int*>(bagOfBytes + sizeof(int)) << '\n';
  std::cout << *reinterpret_cast<int*>(bagOfBytes + sizeof(int)*2) << '\n';
  std::cout << *reinterpret_cast<bool*>(bagOfBytes + sizeof(int)*3 ) << '\n';
  std::cout << *reinterpret_cast<bool*>(bagOfBytes + sizeof(int)*3 + sizeof(bool)) << '\n';

  return 0;
}
```
## Functor
- constructing object out of functions using operator overloading.
- function object : use objects as function, it is a object with state.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>

struct Goblin{
  int m_health{0};
  int m_strength{0};//attack per second
  Goblin(int health,int strength) : m_health(health),m_strength(strength){}

  int operator<(const Goblin& obj){
    return this->m_health < obj.m_health;
  }
};
struct goblinComparator{
  bool operator()(const Goblin& lhs, const Goblin& rhs) const{
    return lhs.m_strength < rhs.m_strength;
  }
};

int main(){
  std::vector<Goblin> goblins { Goblin(5,30), Goblin(3,25), Goblin(100,1)};
  // i want to attack the weakest goblin first.
  std::sort(begin(goblins),end(goblins),goblinComparator());

  for(auto g : goblins){
    std::cout << g.m_health << '\n';
  }

  return 0;
}
``` 
# std::for_each()
- defined in header `<algorithm>`.
- synthax : `std::for_each(start_itr, end_itr, function);`
- applies the given function to every object form start to end.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>

void func(int n)
{ 
  std::cout << n << ' '; 
}
int main(){
  std::vector<int> v{1,3,2,5,6};
  std::for_each(begin(v), end(v), func);
  std::cout << '\n';

  return 0;
}
```

# Lambda Expressions
- constructs a closure : an unnamed function object capable of capturing variables in scope.
- synthax : `[captures](params){function body}`
- compiler generates a class for lambda, create members for captures, creates a functor , then make instances of the class and use it in for each loop.
- `[]` Empty capture means ur capturing nothing, that makes it simple raw pointer.
- `[&var1, &var2, ...]` captures variables by reference.
- `[&]` captures all variables in scope by reference.
- `[var1, var2, ...]` captures variables by value.(read only)
- `[=]` captures everything in scope by value.(read only)
- mutable : `auto print_v = [lastResult](int n) mutable {}` : we are allowed to modify lastResult inside body but the result will not be modified.
- If we declare a global variable, and captures nothing in lambda then also we can modify the global and the changes will reflect outside also.
- If we create a lambda in class we can capture `[this]` to capture all the members and member variables of class by reference.
- Note `[*this]` is same as pass by value.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>

//lambdas are same as functors
struct print_functor{
  int lastResult{-1};
  void operator()(int n){
    lastResult = n;
    std::cout << n << ',';
  }
};

int main(){
  std::vector<int> v{1,3,2,5,6};

  int lastResult = -1; 
  //store a function obaject.
  auto print_v = [&](int n)->void { //trailing return type.
    lastResult = n; 
    std::cout << n << ' '; };
  std::for_each(begin(v), end(v), print_v);
  std::cout << '\n' << lastResult << '\n';

  return 0;
}
```
# using keyword
- namespace is a way to group block of codes so that they have a unique name.
- it is used for type aliases : another name for some type. same as typedef. 
```cpp
template <class T,size_t>
struct DataStructure{

};
typedef DataStructure<int,10> DataStructureInt10;
template<class T>
using DataStructure10 = DataStructure<T,10> //can do this
```
# Macros, defines, __LINE __
- `g++ -E main.cpp | nl` ,-E preprocess our code (no compilation), nl : assign line number to each line.
- macros are something that compiler replaces with associated text at compile time.
- Ex : `#define PI 3.1415926`
- safe method : `constexpr float PI = 3.1415926`
- conditional compilation
```cpp
int main(){
    #if DEBUG
        std::cout << "debugged \n";
    #else
        std::cout << "not debugged \n";
    #endif    
}
```
`g++ -DDEGUG=0 main.cpp` ,change debug from here to choose path from code.
- header guard : `ifndef DEBUG , #def DEBUG . #endif`
- Logging : Function like macros
```cpp
#include <iostream>
#define LOG(param) std::cout << "LOG:" << #param << param; \ 
std::cout << '\n'; //# treat as string 
      
int add(int a,int b){
    return a+b;
}              
int main(){
    LOG(add(7,2);) //no semicolan macro
    return 0;
} 

```             
- file : the file we are in, line: line number(help to debug our program)
`std::cout << __LINE__ << : __FILE__ << '\n`;
# upto 114
---
---
# Data Stuctures in CPP
## Array 
- it is used to store homogenous data, which is stored in contiguous memory location.
- fixed size : we have to decide the size of data at compile time.(predefined)
- `std::iota()` is used to fill container with values starting from some value. it is defined inside `<numeric>` header.
- Synthax :: `std::iota(std::begin(),std::end(),value)` .
```cpp
#include <iostream>
#include <numeric>
#include <iterator>

int main()
{
    int arr[100];
    std::iota(std::begin(arr),std::end(arr),10);

    for(int i=0;i<100;i++)
    {
        std::cout << arr[i] << '\n';
    }

    return 0;
}


```
- The problem with raw arrays is that it is not safe to use, if array size is 100 and you try to access 110th element , it will not restrict you and give some random value.
---
## std::array
- synthax : `std::array<type, size> arr_name`.
- It is a container data structure that encapsulates fixed size arrays.
- It is a container that is more safer to use as it gives you more safety by bound checking.
- Unlike a C-style array, it doesn't decay to T* automatically.
```cpp
#include <iostream>
#include <numeric>
#include <iterator>
#include <array>

int main()
{
    std::array<int,100> arr;
    std::iota(std::begin(arr),std::end(arr),10);

    for(int i=0;i<100;i++)
    {
        std::cout << arr.at(i) << '\n';
    }

    return 0;
}
```
- `arr.at()` function provides safer way to access array items.
- `arr.size()` gives the no. of elements stored in size.
- `sizeof(arr)` gives the bytes req to store the arr.


---
### Passing Arrays to function.
- whenver we pass array into function, also pass the size with it(using int or size_t).
```cpp
#include <iostream>

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
// std::vector
void printVector(const std::vector<int>& vec) { 
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// std::array
template <std::size_t N>
void printArray(const std::array<int, N>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {2, 3, 4, 5, 6};
    std::array<int, 3> arr = {3, 4, 5};

    // Calculate the size of the array
    int size = sizeof(myArray) / sizeof(myArray[0]); 

    printArray(myArray, size);
    printVector(vec);
    printArray(arr);
    return 0;
}
```
## std::string
- std::string is a typedef for std::basic_string which stores and manipulates sequences of character.
- defined in header `<string>`
- the elements are stored contiguously
- string_literal is const char*
```cpp
#include<iostream>
#include<string>

int main(){
    std::string s = "mike";
    //  'm','i','k','e','\0'
    //   0   1   2   3   4
    std::cout << s << '\n';
    std::cout << s.size() << '\n';
    std::cout << s.capacity() << '\n';
    
    s.shrink_to_fit();
    std::cout << s.capacity() << '\n';
    std::cout << s.find("i") << '\n';

    s.reserve(30);

    std::string str = "Hello";
    str.append(" World");          // Appends " World" to str, resulting in "Hello World"
    str.append(3, '!');            // Appends "!!!" to str, resulting in "Hello World!!!"
    std::string str2 = "!!!";
    str.append(str2);              // Appends "!!!" to str, resulting in "Hello World!!!!!!"

    //push_back single char, append char or string.
    std::string str = "Hello";
    str.push_back('!');            // Appends '!' to str, resulting in "Hello!"

    return 0;
}
```
## std::string_view
- It can refer to a constant contiguous sequence of objects with first element at index 0.
-  It provides us a pointer to first char of string and size of string.
- It provides us just read only access.
- It allows us to create substrings
- It does not allocate memory or copy the string content. It just refer to the orignal string.
```cpp
#include <iostream>
#include <string>
#include<string_view>

void print(std::string_view sv){
    std::cout << static_cast<const void*>(sv.data()) << '\n';
}
int main(){
    std::string s = "Hello World";
    std::string_view sv = s;
    std::cout << static_cast<const void*>(s.data()) << '\n';
    std::cout << static_cast<const void*>(sv.data()) << '\n';
    print(sv);
    return 0;
}
```

## std::span
- It can refer to a contiguous sequence of objects with first element at index 0.
- It provides us a pointer to first object of container and size of container.
- It provides us just read only access.
- It does not own the data it points to  avoiding unnecessary copies and allocations.
```cpp
#include <iostream>
#include <span>
#include <array>

void printArray(std::span<int,4> param){
    for(auto &ele : param){
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::array<int, 4> arr = {1,2,3,4};
    printArray(arr);
    return 0;
}
```
## std::vector 
- It is a dynamic size array. 
- It is heap allocated.
- The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted. The total amount of allocated memory can be queried using capacity() function. Extra memory can be returned to the system via a call to shrink_to_fit().
- Reallocations are usually costly operations in terms of performance. The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.
- Time Complexity
  - Random access - constant 𝓞(1).
  - Insertion or removal of elements at the end - amortized constant 𝓞(1).
  - Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).
```cpp
#include <iostream>
#include <vector>

void printArray(std::vector<int>& param){
    std::cout << "vec : ";
    for(auto &ele : param){
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> vec = {1,2,3};
    printArray(vec);
    std::cout << "size : " << vec.size() << '\n';
    std::cout << "Capacity : " << vec.capacity() << '\n';
    
    vec.push_back(4);
    std::cout << "size_after_pushback : " << vec.size() << '\n';
    std::cout << "Capacity_after_pushback : " << vec.capacity() << '\n';

    vec.reserve(50);
    std::cout << "Capacity after reservation : " <<vec.capacity() << '\n';

    vec.shrink_to_fit();
    std::cout << "Capacity after shrink_To_Fit : " << vec.capacity() << '\n';

    vec.data(); //returns a pointer used for functions having arr*
     
    return 0;
}
```
## std::list
- std::list is a container that supports constant time insertion and removal of elements at front and back.
- Fast Random Access is not supported.
- It is usually implemented as a doubly linked list.It has bidirectional iteration capability.
```cpp
#include <iostream>
#include <list>

void printlist(std::list<int>& param){
    std::cout << "list : ";
    for(auto &ele : param){
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::list<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(4);

    mylist.insert(begin(mylist),0);
    mylist.insert(end(mylist),5); 

    auto it = cbegin(mylist);
    it = std::next(it, mylist.size()/2); //returns a iterator
    mylist.insert(it,9);

    mylist.sort();
    mylist.reverse();
    mylist.remove_if([](int n){return n<1;});

    printlist(mylist);

    it = cbegin(mylist);
    std::advance(it,mylist.size()/2); //doesnt return a iterator
    std::cout << "middle value : " << *it << '\n';

    std::cout << "reverse list : " ;
    for(std::list<int>::reverse_iterator it = mylist.rbegin(); it != mylist.rend() ; ++it){
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    mylist.sort();
    std::list<int> list2 {2,4,6,8,10};
    list2.merge(mylist);
    printlist(list2);

    return 0;
}
```
## std::distance : 
- tells us the number of hops between start and end position.
## std::forward_list
- std::forward_list is a container that is more lightweight and efficient than list. Fast *random access* is *not* supported. It is implemented as a singly-linked list. *unidirectional* iteration.
- insert at end 
```cpp
void push_back(std::forward_list<int>& list, int val)
{
    auto pos = begin(list); 
    int distance = std::distance(begin(list),end(list)); 
    std::advance(pos, distance-1);
    list.insert_after(pos,val);
}
```
- Also it doesnt have `size()` member.

## std::deque
- std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end. 
- As opposed to std::vector, the elements of a deque are not stored contiguously. It is implemented using fixed size arrays linked to each other.
- The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper than the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location. On the other hand, deques typically have large minimal memory cost; a deque holding just one element has to allocate its full internal array.
- Time complexity :
  - Random access - constant O(1).
  - Insertion or removal of elements at the end or beginning - constant O(1).
  - Insertion or removal of elements - linear O(n).
```cpp
#include<iostream>
#include<deque>

void printDeque(const std::deque<int>& data){
    std::cout << "Deque : ";
    std::for_each(data.begin(),data.end(),[](const int& n){
        std::cout << n << " ";
    });
    std::cout << '\n'; 
}
int main(){
    std::deque<int> dq{1,2,3,4};
    
    std::deque<int>::iterator it = dq.begin();
    dq.insert(it,0); 
    std::advance(it,2);
    dq.insert(it,500);
    dq.push_back(1000);
    dq.push_front(-1);

    printDeque(dq);

    return 0;
}
```
## std::set
- std::set is a container that contains a `sorted` set of `unique` objects of type T. 
- sorting is done using a T comparison function *Compare*.
- insertion, removal, search opearations have logarithmic complexity.
- sets are usually implemented using `red-black trees`.
```cpp
#include<iostream>
#include<set>

void printSet(const std::set<int>& s){
    std::cout << "Set : ";
    std::for_each(s.begin(), s.end(), [](int n){std::cout << n << ' ';});
    std::cout << '\n';
}
int main()
{
    std::set<int> set1{1,1,3,5,12};

    set1.insert(10);
    set1.insert(2);
    set1.insert(3);

    printSet(set1);

    auto lower = set1.lower_bound(3);
    auto upper = set1.upper_bound(10);

    std::cout << "Values betn range : ";
    for(;lower!=upper;++lower){
        std::cout << *lower << ' ';
    }
    std::cout << '\n';

    lower = set1.lower_bound(3);
    set1.erase(lower,upper);
    set1.erase(1);
    std::cout << "After erase ";
    printSet(set1);
    
    return 0;
}
```
## std::multiset
- defined in header `<set>`
- std::multiset is a container that contains a `sorted` set of objects of type key, but unlike set repeated elements are allowed and their order is preserved. 
- Sorting is done using the key comparision function compare. 
- search, insert, removal operations have logarithmic complexity.
- It is implemented using `redblack tree only`.
```cpp
#include <iostream>
#include <set>

//custom comparator
struct compare{
    bool operator()(const int& lhs, const int& rhs){
        int lhs_prod = lhs *2;
        int rhs_prod = rhs *3;
        return lhs_prod < rhs_prod;
    }
};
void printMultiSet(const std::multiset<int>& ms){
    std::cout << "Multiset : ";
    std::for_each(ms.begin(), ms.end(), [](int n){std::cout << n << ' ';});
    std::cout << '\n';
}
int main()
{
    std::multiset<int> ms{1,9,3,2,9,5,9,9};
    std::cout << "9's Count : " << ms.count(9) << '\n';

    if(ms.contains(9)){
        std::multiset<int>::iterator it = ms.find(9);
        ms.erase(it);
    }
    ms.erase(9);
    printMultiSet(ms);

    return 0;
}
```
## std::unordered_set
- It is a container that contains a set of unique objects of type Key.
- Unordered_set have search, insert, removal in average constant time complexity.
- Internally the elements are not stored in any particulat order, but organized into buckets based on hash values. This allow fast access to individual elements, since once hash is computed, it refers to the exact bucket the element is placed into.
- container elements may not be modified, since modification could change an element's hash and corrupt the container.
```cpp
#include<iostream>
#include<unordered_set>

int main(){
    std::unordered_set<int> us{1,2,3,4,5,6};

    std::cout << us.bucket_count() << '\n';
    std::cout << us.load_factor() << '\n';

    if(!us.contains(12)){
        us.insert(12);
    }

    return 0;
}
```
## std::unordered_multiset 
- defined in header `<unordered_set>`.
- std::unordered_set is an container that contains can contain set of non-unique objects of type k.
- In Unordered_multiset order of contained objects does not matter.
- search, insertion and removal have average consant time- complexity.
- Internally elements are not stored in any particular order, but organized into buckets based on hash values, which allows fast access to individual elements.
- It is implemented using a hash table.
```cpp
#include <unordered_set>
#include <iostream>

int main()
{
    std::unordered_multiset<int> ums = {1,3,5,2,4,6};
    for(int i : ums){
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
```
## std::pair
- present in `<utility>` header.
-  It is a class template that provides a way to store two hetrogenous objects as a single unit.
- It is a special case of std::typle with two elements.
```cpp
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <functional>

using student_t = std::pair<int, std::string>;
int main()
{
    std::vector<student_t> students;
    for (int i=1 ; i<=5 ; i++){
        student_t student(i,"pratham");
        students.push_back(student);
    }

    for(student_t student : students){
        std::cout << student.first << " : " << student.second << '\n';
    }

    std::string teacher = "OP_Pandey";
    auto newPair = std::make_pair("teacher",std::ref(teacher));

    teacher = "Yadav";

    std::cout << newPair.first << " : " << newPair.second << '\n';

    std::pair<std::string, std::vector<int>> results("divA",{1,2,3});
    std::cout << results.first << " : " << results.second[2] << '\n';
    return 0;
}
```

## std::map 
- std::map is a sorted container that stores `key-value` pair with unique keys. Keys are sorted using comparison function compare. 
- search, removal, insertino operations have `logarithmic` complexity.
- Maps are also implemented as `Red-black-trees`. 
- need to provide custom comparator for custom data structure.    
```cpp
#include <iostream>
#include <map>
#include <string>

struct Edge{
    unsigned long v1;
    unsigned long v2;

    Edge() = default;
    Edge(size_t pv1, size_t pv2):v1(pv1),v2(pv2){}

    friend std::ostream& operator << (std::ostream& os, const Edge& e){
        os << e.v1 << " , " << e.v2 ;
        return os;
    } 
};

int main(){
    //create a map 
    std::map<std::string, Edge> mymap;
    // created first edge1 in map
    mymap["Edge1"] = Edge(0,1);
    std::cout << mymap["Edge1"] << '\n';

    // update Egde1
    mymap["Edge1"]= Edge(1,2);
    std::cout << mymap["Edge1"] << '\n';

    //Try to display edge that doesnt exist.
    std::cout << mymap["Edge2"] << '\n'; // outputs : 0,0 , use .at() for bound checking.

    mymap.insert(std::pair("Edge4",Edge(2L,3L)));  //wont give error if Edge2 instead of Edge4, but also didnt update the Edge.
    std::cout << mymap["Edge4"] << '\n';

    //use a structured binding , to return successful and retrive an iterator to where the element was inserted.
    const auto[it, success] = mymap.insert(std::pair("Edge3",Edge(3,4)));
    std::cout << "Edge3 added ? : " << success << '\n';
    std::cout << it->first << " : " << it->second << '\n';

    std::cout << "Whole map is like : \n";
    for (std::map<std::string, Edge>::iterator it = mymap.begin(); it != mymap.end() ; it++){
        std::cout << it->first << " : " << it->second << '\n';
    }

    if(mymap.contains("Edge3")){
        mymap.erase("Edge3");
        std::cout << "After Erase : \n\n";
    }
    std::cout << "using range based loop : \n";
    for (const auto& entry: mymap){
        std::cout << entry.first << " : " << entry.second << '\n';
    }

    std::cout << "using range based loop (structed binding): \n";
    for (const auto& [key,value]: mymap){
        std::cout << key << " : " << value << '\n';
    }

    return 0;
}
```
## std::multimap
- It contains sorted list of key-value pair, while permitting multiple entries with the same key. Sorting is done according to the comparison function Compare, applied to the keys.
- Search, insertion, and removal operations have logarithmic complexity.
- It is ordered, stable.
- It is also implemented using red-black trees.
```cpp
#include<iostream>
#include <string>
#include <map>

int main()
{
    std::multimap<std::string, int> mymultimap;

    mymultimap.insert(std::pair{"Pratham",100});
    mymultimap.insert(std::pair{"Pratham",101});
    mymultimap.insert(std::pair{"Pratham",100});
    mymultimap.insert(std::pair{"Pratham",102});

    for (const auto& element: mymultimap){
        std::cout << element.first << " : " << element.second << '\n';
    }

    return 0;
}
```
## unordered_map
- unordered_map is a container that contains key-value pairs with unique keys.
- search, insert, removal of elements have average constant time complexity.
- Internally the elements are organized into buckets depending on hash_value. keys with same hash_value are stored in same bucket and it allows fast access to elements.
```cpp
#include<iostream>
#include<unordered_map>
#include<string>

struct Edge{
    int src{0};
    int dest{0};

    Edge() = default;
    Edge(int v1, int v2):src(v1),dest(v2){}
    
    friend std::ostream& operator << (std::ostream& os, const Edge& e){
        os << e.src << " , " << e.dest ;
        return os;
    }

};

int main(){
    std::unordered_map <std::string, Edge> um ;
    Edge e1(1,2);
    um.insert({"Edge1",e1});

    for(auto const& [key, value] : um){
        std::cout << key << " : " << value << '\n';
    }

    return 0;
}
```
## std::unordered_multimap
- std::unordered_multiset is an unordered container that supports duplication of keys.
- search, insertion and removal have average constant time complexity.
- it is stored in hashmap buckets using hash value.

## std::Stack
- defined in the header `<stack>`.
- It is a Last-In First-Out data structure(LIFO).

## std::queue
- defined in header '<queue>'
- It is a First-In First-out data structure(FIFO).

## std::priority_queue

























# Handling program arguments
- `g++` : executable, `main.cpp -o(flag) prog` : arguments. 
- synthax : ./prog (args, ...)
- Ex : `./prog some long string` are 4 args, `./prog "some long string"` are 2 args.
- `int main(int argc, char* argv[]){}` , argc : arg count, argv[] : arg values.

# Tools for debugging 
- compiler explorer : godbolt.org : provides assembly code for given source code.
- valgrind ./a.out
- cppinsights.io : compiler generated cpp code : good for templates.

# Books :
- The Pragmatic Programmer 
- google c++ style guide, mesos c++ style guide, bungie c++ guide(gaming company), clang format
- cpp core guidelines : isocpp.github.io/CppCoreGuidelines
- `-Weffc++ `flag 
- mike recommendations
  - c++ for game programmers : micheal d (old cpp implementations)
  - A tour of c++ (third edition) : bjarne stroustrup(modern cpp).
  - API design for c++ : Martin Reddy (design patterns)
  - Professional c++ : MArc Gregoire
  - Effective modern c++ : scott meyers. 
