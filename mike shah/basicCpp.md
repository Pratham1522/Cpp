# C++
- C++ is a general-purpose programming language developed by Bjarne Stroustrup as an extension of the C programming language. It includes object-oriented, generic, and functional programming features in addition to facilities for low-level memory manipulation. C++ is widely used for system/software development, game programming, real-time simulation, and in performance-critical applications.
- C++ is a statically-typed language, meaning that the type of a variable is determined during compilation, and has an extensive library called the C++ Standard Library, which provides a rich set of functions, algorithms, and data structures for various tasks.
- C++ builds upon the features of C, and thus, most C programs can be compiled and run with a C++ compiler.

### Object-Oriented Programming (OOP)
**Definition:** OOP is a paradigm that uses "objects" to design applications and programs. Objects are instances of classes, which can contain both data (attributes) and functions (methods).

**Key Concepts:**
- **Encapsulation:** Bundling data and methods that operate on the data within one unit (class) and restricting access to some of the object's components.
- **Inheritance:** Creating new classes from existing ones, allowing for code reuse and the creation of a hierarchical relationship.
- **Polymorphism:** Allowing objects to be treated as instances of their parent class rather than their actual class, enabling one interface to be used for a general class of actions.
- **Abstraction:** Hiding the complex implementation details and showing only the essential features of the object.

**Benefits:**
- **Modularity:** Code is organized into separate objects, making it easier to manage and maintain.
- **Reusability:** Classes can be reused in different parts of a program or in different programs.
- **Scalability:** OOP makes it easier to manage larger codebases.

### Generic Programming
**Definition:** Generic programming is a paradigm where algorithms are written in terms of types that are specified later. This is typically achieved using templates.

**Key Concepts:**
- **Templates:** Allow functions and classes to operate with any data type without being rewritten for each type.

**Benefits:**
- **Type Safety:** Errors are caught at compile time rather than runtime.
- **Reusability:** Functions and classes can work with any data type, promoting code reuse.
- **Performance:** Code can be optimized by the compiler for specific data types, improving performance.

### Functional Programming
**Definition:** Functional programming is a paradigm that treats computation as the evaluation of mathematical functions and avoids changing-state and mutable data.

**Key Concepts:**
- **Pure Functions:** Functions that have no side effects and return the same result given the same arguments.
- **First-Class Functions:** Functions that can be passed as arguments to other functions, returned as values from other functions, and assigned to variables.
- **Immutability:** Data cannot be modified after it is created.
- **Higher-Order Functions:** Functions that can take other functions as arguments and/or return them as results.

**Benefits:**
- **Predictability:** Pure functions and immutability make the code more predictable and easier to debug.
- **Concurrency:** Easier to write concurrent or parallel code since functions don't have side effects.
- **Modularity:** Functions can be combined in flexible ways, enhancing code modularity.

Each paradigm offers unique strengths, and C++ allows programmers to leverage all three, providing flexibility in designing and implementing software.

---
## Why to use C++
C++ is used for various reasons due to its unique combination of features and strengths:

### 1. **Performance and Efficiency**
- It offers fine-grained control over system resources, making it easier to optimize your software.
- **Compiled Language:** Being a compiled language, C++ programs are generally faster and more efficient compared to interpreted languages.

### 2. **Object-Oriented Programming (OOP)**
- **Modularity and Code Reuse:** C++ supports OOP principles like inheritance, encapsulation, and polymorphism, which help in organizing complex programs into manageable, reusable, and modular code.
- **Scalability:** OOP makes it easier to manage large-scale software projects.

### 3. **Generic Programming**
- **Templates:** C++ supports templates, enabling the creation of generic and reusable functions and classes that work with any data type, enhancing code reusability and type safety.

### 4. **Standard Template Library (STL)**
- **Rich Library Support:** The STL provides a collection of well-tested algorithms, data structures (like vectors, lists, and maps), and iterators, facilitating faster and more efficient coding.

### 5. **System and Application Software**
- **System Programming:** C++ is ideal for system-level programming (such as operating systems, device drivers) due to its close-to-hardware capabilities and performance.
- **Application Software:** Widely used in developing desktop applications, games, real-time simulations, and high-performance software like financial modeling tools.

### 6. **Multi-Paradigm Support**
- **Versatility:** C++ supports multiple programming paradigms (procedural, object-oriented, and generic programming), providing flexibility in how developers approach problem-solving.
- **Functional Programming:** With C++11 and later standards, C++ has incorporated features supporting functional programming.

### 7. **Portability**
- **Cross-Platform Development:** C++ is portable across various operating systems and hardware platforms, making it suitable for developing cross-platform applications.

### 8. **Community and Ecosystem**
- **Mature Ecosystem:** C++ has a vast, active community and a wealth of libraries, frameworks, and tools that support development across different domains.
- **Industry Adoption:** C++ is widely used in industries such as game development (e.g., Unreal Engine), finance, telecommunications, and more.

Overall, C++ is chosen for its performance, versatility, and the ability to efficiently manage system resources while providing high-level abstractions.


## C vs C++
C and C++ are two fundamental programming languages, both originating from the same lineage but having distinct characteristics and use cases. Here's a comparison of the two:

### Origins and Evolution
- **C:**
  - **Developed By:** Dennis Ritchie
  - **Year:** Early 1970s
  - **Purpose:** System programming language for developing operating systems (notably Unix)
  - **Type:** Procedural language

- **C++:**
  - **Developed By:** Bjarne Stroustrup
  - **Year:** Early 1980s
  - **Purpose:** Enhance C with object-oriented features
  - **Type:** Multi-paradigm language (supports procedural, object-oriented, and generic programming)

### Key Differences

#### 1. **Programming Paradigms**
- **C:**
  - Procedural Programming: Focuses on functions and procedures to operate on data.
- **C++:**
  - Multi-Paradigm: Supports procedural, object-oriented, and generic programming. Allows combining different styles for better code organization and flexibility.

#### 2. **Object-Oriented Features**
- **C:**
  - Does not support classes, objects, inheritance, or polymorphism.
- **C++:**
  - Supports classes and objects.
  - Includes features like inheritance, polymorphism, encapsulation, and abstraction, facilitating modular and reusable code.

#### 3. **Standard Libraries**
- **C:**
  - Standard Library: Includes functions for input/output, string manipulation, memory allocation, etc.
- **C++:**
  - Standard Template Library (STL): Provides a rich set of template classes and functions for data structures (e.g., vectors, lists, maps) and algorithms.
  - Includes the C standard library as well.

#### 4. **Memory Management**
- **C:**
  - Manual memory management using functions like `malloc` and `free`.
- **C++:**
  - Manual memory management using operators like `new` and `delete`.
  - Supports RAII (Resource Acquisition Is Initialization) for automatic resource management using constructors and destructors.

#### 5. **Exception Handling**
- **C:**
  - Error handling is done through return codes and `errno`.
- **C++:**
  - Supports robust exception handling with `try`, `catch`, and `throw` constructs.

#### 6. **Function Overloading and Templates**
- **C:**
  - Does not support function overloading or templates.
- **C++:**
  - Supports function overloading (same function name with different parameters).
  - Supports templates for generic programming, allowing functions and classes to operate with any data type.

#### 7. **Namespaces**
- **C:**
  - Does not support namespaces.
- **C++:**
  - Supports namespaces to organize code and avoid name collisions.

### Use Cases
- **C:**
  - System programming (operating systems, embedded systems).
  - Performance-critical applications where low-level manipulation is required.
  - Legacy codebases.

- **C++:**
  - Application development (desktop applications, games, real-time simulations).
  - System software (compilers, device drivers).
  - High-performance software in finance, telecommunications, and more.
  - Projects where object-oriented and generic programming can enhance code maintainability and reusability.

### Performance
- **C:**
  - Generally considered slightly faster due to its lower-level operations and lack of additional abstractions.
- **C++:**
  - Can achieve comparable performance to C, but the additional features (like OOP) can introduce some overhead. However, modern C++ compilers optimize code to minimize this overhead.

### Community and Ecosystem
- **C:**
  - Mature and well-established with extensive documentation and libraries.
- **C++:**
  - Also mature with a rich set of libraries (STL, Boost) and active community support.

### Conclusion
C is preferred for low-level programming and situations requiring close hardware interaction. C++ is chosen for its flexibility, supporting both low-level and high-level programming, making it suitable for a broader range of applications, especially where object-oriented and generic programming can be advantageous.

## Basics of C++ Programming
### Including Libraries
- In C++, we use the #include directive to include libraries or header files into our program. For example, to include the standard input/output library, we write:
- `#include <iostream>`

### Main Function
- The entry point of a C++ program is the main function. Every C++ program must have a main function:
```cpp
int main() {
    // Your code goes here
    return 0;
}
```

### Input/Output
- To perform input and output operations in C++, we can use the built-in objects std::cin for input and std::cout for output, available in the iostream library. Here’s an example of reading an integer and printing its value:
```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
```
### Variables and Data Types
- int: integer values
- float: single-precision floating-point values
- double: double-precision floating-point values
- char: single characters
- bool: boolean values
- Variables must be declared with a data type before they can be used:

### Control Structures
- C++ provides control structures for conditional execution and iteration, such as if, else, while, for, and switch statements.

- If-Else Statement
```cpp
if (condition) {
    // Code to execute if the condition is true
} else {
    // Code to execute if the condition is false
}
```
### While Loop
```cpp
while (condition) {
    // Code to execute while the condition is true
}
```
### For Loop
```cpp
for (initialization; condition; update) {
    // Code to execute while the condition is true
}
```
### Switch Statement
```cpp
switch (variable) {
    case value1:
        // Code to execute if variable == value1
        break;
    case value2:
        // Code to execute if variable == value2
        break;
    // More cases...
    default:
        // Code to execute if variable does not match any case value
}
```
### Functions
- Functions are reusable blocks of code that can be called with arguments to perform a specific task. 
- Functions are defined with a return type, a name, a parameter list, and a body.

```cpp
ReturnType functionName(ParameterType1 parameter1, ParameterType2 parameter2) {
    // Function body
    // ...
    return returnValue;
}
```
- For example, here’s a function that adds two integers and returns the result:
```cpp
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 4);
    std::cout << "3 + 4 = " << result << std::endl;
    return 0;
}
```
## Data Types in C++

In C++, data types categorize different types of data that a program can process, determining the type of value a variable can hold and how much memory space it occupies. Here's an overview of basic data types in C++:

### Fundamental Data Types

1. **Integer (`int`)**:
   - Stores whole numbers, positive or negative.
   - Size depends on system architecture (usually 4 bytes).

   ```cpp
   int num = 42;
   ```

   Variants: `short`, `long`, `long long`.

2. **Floating-Point (`float`, `double`)**:
   - Represents real numbers with decimal points.
   - `float`: Single-precision (4 bytes).
   - `double`: Double-precision (usually 8 bytes).

   ```cpp
   float pi = 3.14f;
   double pi_high_precision = 3.1415926535;
   ```

3. **Character (`char`)**:
   - Represents a single character stored using ASCII value (1 byte).

   ```cpp
   char letter = 'A';
   ```

4. **Boolean (`bool`)**:
   - Represents logical values: `true` or `false` (1 byte).

   ```cpp
   bool is_cpp_great = true;
   ```

### Derived Data Types

5. **Arrays**:
   - Stores multiple values of the same data type in consecutive memory locations.

   ```cpp
   int numbers[5] = {1, 2, 3, 4, 5};
   ```

6. **Pointers**:
   - Stores memory address of a variable.

   ```cpp
   int num = 42;
   int* pNum = &num;
   ```

7. **References**:
   - Creates an alias for another variable.

   ```cpp
   int num = 42;
   int& numRef = num;
   ```

### User-Defined Data Types

8. **Structures (`struct`)**:
   - Stores different data types under a single variable.
   - Member variables and methods are public by default.

   ```cpp
   struct Person {
       string name;
       int age;
       float height;
   };

   Person p1 = {"John Doe", 30, 5.9};
   ```

9. **Classes (`class`)**:
   - Similar to structures but with access specifiers.
   - Access to members is private by default.

   ```cpp
   class Person {
   public:
       string name;
       int age;

       void printInfo() {
           cout << "Name: " << name << ", Age: " << age << endl;
       };
   };

   Person p1;
   p1.name = "John Doe";
   p1.age = 30;
   ```

10. **Unions (`union`)**:
    - Stores different data types in the same memory location.

    ```cpp
    union Data {
        int num;
        char letter;
        float decimal;
    };

    Data myData;
    myData.num = 42;
    ```

Understanding these data types is crucial for effective programming in C++, enabling you to manage variables and data efficiently.

## Operators in  C++
### Arithmetic Operators in C++

Arithmetic operators are used to perform mathematical operations with basic variables such as integers and floating-point numbers. Below is a summary of the different arithmetic operators in C++:

#### 1. Addition Operator (+)
- **Description:** Adds two numbers together.
- **Example:**
  ```cpp
  int sum = a + b;
  ```

#### 2. Subtraction Operator (-)
- **Description:** Subtracts one number from another.
- **Example:**
  ```cpp
  int difference = a - b;
  ```

#### 3. Multiplication Operator (*)
- **Description:** Multiplies two numbers together.
- **Example:**
  ```cpp
  int product = a * b;
  ```

#### 4. Division Operator (/)
- **Description:** Divides one number by another. Note that if both operands are integers, it will perform integer division and the result will be an integer.
- **Examples:**
  ```cpp
  int quotient = a / b;           // Integer division
  float quotient = float(a) / float(b); // Floating-point division
  ```

#### 5. Modulus Operator (%)
- **Description:** Calculates the remainder of an integer division.
- **Example:**
  ```cpp
  int remainder = a % b;
  ```

#### 6. Increment Operator (++)
- **Description:** Increments the value of a variable by 1. There are two ways to use this operator: prefix (++x) and postfix (x++). Prefix increments the value before returning it, whereas postfix returns the value first and then increments it.
- **Examples:**
  ```cpp
  int x = 5;
  int y = ++x; // x = 6, y = 6
  int z = x++; // x = 7, z = 6
  ```

#### 7. Decrement Operator (--)
- **Description:** Decrements the value of a variable by 1. It can also be used in prefix (--x) and postfix (x--) forms.
- **Examples:**
  ```cpp
  int x = 5;
  int y = --x; // x = 4, y = 4
  int z = x--; // x = 3, z = 4
  ```
### Logical Operators in C++
- Logical operators are used to perform logical operations on expressions, primarily to test relationships between variables or values. They return a boolean value: either true (1) or false (0) based on the evaluation result.

- C++ provides the following logical operators:

#### 1. AND Operator (&&)
- **Description:** Checks if both operands/conditions are true. If both are true, the result is true; otherwise, it is false.
- **Syntax:** 
  ```cpp
  (expression1 && expression2)
  ```
- **Example:**
  ```cpp
  int a = 5, b = 10;
  if (a > 0 && b > 0) {
      cout << "Both values are positive." << endl;
  }
  ```

#### 2. OR Operator (||)
- **Description:** Checks if either of the operands/conditions is true. If at least one condition is true, the result is true; if both are false, the result is false.
- **Syntax:** 
  ```cpp
  (expression1 || expression2)
  ```
- **Example:**
  ```cpp
  int a = 5, b = -10;
  if (a > 0 || b > 0) {
      cout << "At least one value is positive." << endl;
  }
  ```

#### 3. NOT Operator (!)
- **Description:** Reverses the result of the condition/expression it is applied to. If the condition is true, the NOT operator makes it false, and vice versa.
- **Syntax:** 
  ```cpp
  !(expression)
  ```
- **Example:**
  ```cpp
  int a = 5;
  if (!(a < 0)) {
      cout << "The value is not negative." << endl;
  }
  ```

#### Complex Logical Expressions

Using these operators, you can create more complex logical expressions. For example:

```cpp
int a = 5, b = -10, c = 15;

if (a > 0 && (b > 0 || c > 0)) {
    cout << "At least two values are positive." << endl;
}
```

In this example, the expression inside the `if` statement checks if `a` is positive and either `b` is positive or `c` is positive, making use of both the AND (`&&`) and OR (`||`) operators.

## Loops in C++

Loops are an essential concept in programming that allow you to execute a block of code repeatedly until a specific condition is met. In C++, there are three main types of loops: `for`, `while`, and `do-while`.

### 1. For Loop

A `for` loop is used when you know the number of times you want to traverse through a block of code. It consists of an initialization statement, a condition, and an increment/decrement operation.

**Syntax:**
```cpp
for (initialization; condition; increment/decrement) {
    // block of code to execute
}
```

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << "Iteration: " << i << endl;
    }
    return 0;
}
```

### 2. While Loop

A `while` loop runs as long as a specified condition is true. The loop checks the condition before entering the body of the loop.

**Syntax:**
```cpp
while (condition) {
    // block of code to execute
}
```

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 5) {
        cout << "Iteration: " << i << endl;
        i++;
    }
    return 0;
}
```

### 3. Do-While Loop

A `do-while` loop is similar to a `while` loop, with the key difference being that the loop body is executed at least once, even if the condition is false.

**Syntax:**
```cpp
do {
    // block of code to execute
} while (condition);
```

**Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    do {
        cout << "Iteration: " << i << endl;
        i++;
    } while (i < 5);
    return 0;
}
```

### Summary

Loops are an integral part of C++ programming that allow you to execute a block of code multiple times. The three types of loops in C++ are:

1. **For Loop:** Best used when the number of iterations is known beforehand.
2. **While Loop:** Best used when the number of iterations is not known and depends on a condition.
3. **Do-While Loop:** Similar to the `while` loop but ensures the loop body is executed at least once.

Each type of loop has its own specific use case and can be chosen depending on the desired behavior.

## Bitwise operations in C++
Bitwise operations are fundamental in C++ for directly manipulating the bits of numbers. They find applications in optimizing algorithms, performing specific calculations, and managing memory at a lower level. Here's a summary of common bitwise operations in C++:

### 1. Bitwise AND (&)
- **Description:** Compares two numbers bit by bit and returns a new number where each bit is set (1) if both corresponding bits in the input numbers are set (1).
- **Example:**
  ```cpp
  int result = 5 & 3; // result will be 1 (0000 0101 & 0000 0011 = 0000 0001)
  ```

### 2. Bitwise OR (|)
- **Description:** Compares two numbers bit by bit and returns a new number where each bit is set (1) if at least one of the corresponding bits in either input number is set (1).
- **Example:**
  ```cpp
  int result = 5 | 3; // result will be 7 (0000 0101 | 0000 0011 = 0000 0111)
  ```

### 3. Bitwise XOR (^)
- **Description:** Compares two numbers bit by bit and returns a new number where each bit is set (1) if the corresponding bits in the input numbers are different.
- **Example:**
  ```cpp
  int result = 5 ^ 3; // result will be 6 (0000 0101 ^ 0000 0011 = 0000 0110)
  ```

### 4. Bitwise NOT (~)
- **Description:** Inverts each bit of a number.
- **Example:**
  ```cpp
  int result = ~5; // result will be -6 (1111 1010)
  ```

### 5. Bitwise Left Shift (<<)
- **Description:** Shifts the bits of a number to the left by a specified number of positions, filling vacated bits with zeros.
- **Example:**
  ```cpp
  int result = 5 << 1; // result will be 10 (0000 0101 << 1 = 0000 1010)
  ```

### 6. Bitwise Right Shift (>>)
- **Description:** Shifts the bits of a number to the right by a specified number of positions, filling vacated bits with zeros or sign bit depending on whether the input value is signed or unsigned.
- **Example:**
  ```cpp
  int result = 5 >> 1; // result will be 2 (0000 0101 >> 1 = 0000 0010)
  ```

These operations are powerful tools in C++, but be cautious when using them, ensuring you understand their behavior with specific data types and scenarios.

## Functions in C++
Functions in C++ serve as organized units of code that execute specific tasks, aiding in breaking down programs into smaller, reusable blocks. They are categorized into two main types:

1. **Standard Library Functions**: These are pre-defined functions available in the C++ standard library. Examples include `printf()`, `scanf()`, `sqrt()`, and more. To utilize these functions, you must include the appropriate header file.

2. **User-defined Functions**: These are functions crafted by programmers to fulfill specific tasks. Creating a user-defined function involves defining the function and subsequently invoking it within the code.

**User Defined Function**

A function in C++ follows a general format:

```cpp
return_type function_name(parameter list) {
    // function body
}
```

- **return_type**: Specifies the data type of the output produced by the function. It can be `void`, indicating that the function doesn’t return any value.
- **function_name**: Represents the name given to the function, following C++ naming conventions.
- **parameter list**: Encompasses the input parameters/arguments required to execute the task. It's optional, and when no parameters are needed, it can be left blank or utilize the keyword `void`.

**Example of User Defined Function**

```cpp
#include <iostream>
using namespace std;

// Function to add two numbers
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int num1 = 5, num2 = 10;
    int result = addNumbers(num1, num2); // Calling the function
    cout << "The sum is: " << result << endl;
    return 0;
}
```

**Function Prototypes**

Sometimes, it's necessary to use a function before actually defining it. To achieve this, a function prototype is declared at the beginning of the code. 

A function prototype is a declaration of the function without its body, informing the compiler about the function’s name, return type, and parameters.

**Example of Function Prototypes**

```cpp
#include <iostream>
using namespace std;

// Function prototype
int multiplyNumbers(int x, int y);

int main() {
    int num1 = 3, num2 = 7;
    int result = multiplyNumbers(num1, num2); // Calling the function
    cout << "The product is: " << result << endl;
    return 0;
}

// Function definition
int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}
```
### Lambda Functions in C++

A lambda function, or simply “lambda”, is an anonymous (unnamed) function defined in place within your source code, characterized by a concise syntax. Lambda functions were introduced in C++11 and have since become a widely used feature, particularly in combination with the Standard Library algorithms.

**Syntax:**

```cpp
[capture-list](parameters) -> return_type {
    // function body
};
```

- **capture-list**: A list of variables from the surrounding scope that the lambda function can access.
- **parameters**: The list of input parameters, similar to a regular function. Optional.
- **return_type**: The type of the value that the lambda function will return. Optional; the compiler can deduce it in many cases.
- **function body**: The code defining the operation of the lambda function.

**Usage Examples:**

1. Lambda function with no capture, parameters, or return type.
   ```cpp
   auto printHello = []() {
       std::cout << "Hello, World!" << std::endl;
   };
   printHello(); // Output: Hello, World!
   ```

2. Lambda function with parameters.
   ```cpp
   auto add = [](int a, int b) {
       return a + b;
   };
   int result = add(3, 4); // result = 7
   ```

3. Lambda function with capture-by-value.
   ```cpp
   int multiplier = 3;
   auto times = [multiplier](int a) {
       return a * multiplier;
   };
   int result = times(5); // result = 15
   ```

4. Lambda function with capture-by-reference.
   ```cpp
   int expiresInDays = 45;
   auto updateDays = [&expiresInDays](int newDays) {
       expiresInDays = newDays;
   };
   updateDays(30); // expiresInDays = 30
   ```

When using capture by reference, any changes made to the captured variable inside the lambda function will affect its value in the surrounding scope. Lambda functions offer a flexible and concise way to define functionality, especially when it's needed locally and isn't reused elsewhere in the code.


## Static Typing in C++

In C++, static typing refers to determining the data type of a variable at compile time, before the program is executed. This ensures that variables can only be used with data of specific types, and the compiler verifies that operations performed with variables are compatible with their types. If there's a type mismatch, the compiler may adjust the data types if feasible, or raise an Invalid Type Conversion error during compilation.

C++ is a statically typed language, employing static typing for data types and type checking during compile time. This enhances type safety and helps prevent certain types of errors during program execution.

**Example:**
```cpp
#include <iostream>

int main() {
    int num = 65;        // 'num' is statically typed as an integer
    double pi = 3.14159; // 'pi' is statically typed as a double
    char c = 'c';        // 'c' is statically typed as a char

    c = num;    // Conversion of num's value to ASCII equivalent character
    num = pi;   // Conversion of pi's value from double type to int type
    
    std::cout << "The value of num is: " << num << std::endl;
    std::cout << "The value of pi is: " << pi << std::endl;
    std::cout << "The value of c is: "<< c << std::endl;
    return 0;
}
```

In the provided code, variables `num`, `pi`, and `c` are statically typed as int, double, and char, respectively. When attempting to assign the value of `pi` to `num`, the compiler converts 3.14159 to the integer 3 and assigns it to `num`. Similarly, assigning the value of `num` to `c` converts 65 to its corresponding ASCII code, which is 'A'.

## Dynamic Typing in C++

While C++ is primarily a statically-typed language, meaning data types are determined at compile time, it also provides mechanisms for dynamic typing, where data types are determined at runtime. Here's an overview of two ways to achieve dynamic typing in C++:

### 1. `void*` Pointers

A `void*` pointer is a generic pointer that can point to objects of any data type. It allows storing a reference to any type of object without knowing the specific type of the object.

**Example:**
```cpp
#include <iostream>

int main() {
    int x = 42;
    float y = 3.14f;
    std::string z = "Hello, world!";

    void* void_ptr;

    void_ptr = &x;
    std::cout << "int value: " << *(static_cast<int*>(void_ptr)) << std::endl;

    void_ptr = &y;
    std::cout << "float value: " << *(static_cast<float*>(void_ptr)) << std::endl;

    void_ptr = &z;
    std::cout << "string value: " << *(static_cast<std::string*>(void_ptr)) << std::endl;

    return 0;
}
```

### 2. `std::any` (C++17)

C++17 introduced the `std::any` class, which represents a generalized type-safe container for single values of any type.

**Example:**
```cpp
#include <iostream>
#include <any>

int main() {
    std::any any_value;

    any_value = 42;
    std::cout << "int value: " << std::any_cast<int>(any_value) << std::endl;

    any_value = 3.14;
    std::cout << "double value: " << std::any_cast<double>(any_value) << std::endl;

    any_value = std::string("Hello, world!");
    std::cout << "string value: " << std::any_cast<std::string>(any_value) << std::endl;

    return 0;
}
```

Both `void*` pointers and `std::any` have performance implications due to the additional type checking and casting that occur during runtime. Therefore, they should be used carefully and only when necessary.

## Run-Time Type Identification (RTTI) in C++

Run-Time Type Identification (RTTI) is a feature in C++ that allows obtaining type information of an object during program execution. It's particularly useful when dealing with polymorphic classes or dynamic typing scenarios.

### 1. **typeid Operator**

The `typeid` operator returns a reference to an object of type `std::type_info`, containing information about the type of the object. It's used to determine the dynamic type of an object at runtime.

**Example:**
```cpp
#include <iostream>
#include <typeinfo>

class Base { virtual void dummy() {} };
class Derived : public Base { /* ... */ };

int main() {
    Base* base_ptr = new Derived;

    // Using typeid to get the type of the object
    std::cout << "Type: " << typeid(*base_ptr).name() << '\n';

    delete base_ptr;
    return 0;
}
```

### 2. **dynamic_cast Operator**

The `dynamic_cast` operator performs a runtime type check and safely downcasts a base pointer or reference to a derived pointer or reference. It returns null or throws a `bad_cast` exception (if casting references) when the casting fails.

**Example:**
```cpp
#include <iostream>

class Base { virtual void dummy() {} };
class Derived1 : public Base { /* ... */ };
class Derived2 : public Base { /* ... */ };

int main() {
    Base* base_ptr = new Derived1;

    // Using dynamic_cast to safely downcast the pointer
    Derived1* derived1_ptr = dynamic_cast<Derived1*>(base_ptr);
    if (derived1_ptr) {
        std::cout << "Downcast to Derived1 successful\n";
    }
    else {
        std::cout << "Downcast to Derived1 failed\n";
    }

    Derived2* derived2_ptr = dynamic_cast<Derived2*>(base_ptr);
    if (derived2_ptr) {
        std::cout << "Downcast to Derived2 successful\n";
    }
    else {
        std::cout << "Downcast to Derived2 failed\n";
    }

    delete base_ptr;
    return 0;
}
```

Please note that while RTTI provides flexibility, its use can incur performance overhead due to additional compiler-generated information and runtime checks. Therefore, it should be used judiciously, especially in performance-critical applications.
