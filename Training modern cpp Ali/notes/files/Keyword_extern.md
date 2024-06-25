## extern
- `extern` keyword is used to declare a variable or function that is defined in another source file or external linkage. It informs the compiler that the specified variable or function is defined elsewhere, allowing the program to access it without generating an error related to multiple definitions.
```cpp
// In a header file (e.g., myfunctions.h)
extern void myFunction(); // Declaration

// In one source file (e.g., file1.cpp)
void myFunction() {
    // Function definition
}
```
- This tells the compiler to use C linkage for the `fun` function, which means that the function will have C-style name mangling and can be called from C code .
```cpp
extern "C" void fun(int, int);
```
