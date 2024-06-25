## constexpr keyword
- It indicate that a function or variable can be evaluated or computed at compile time. It stands for "constant expression."
```cpp
constexpr int fib(int n)
{
    return (n < 2) ? n : (fib(n - 1) + fib(n - 2));
}

template<int num>
class Stack
{
};

int main()
{
    Stack<5> stk1; //instantiated at compiletime
    Stack<fib(3)> stk2; //fib(3) evaluates to 2 at compiletime and stack is instantiated 
    return 0;
}
```
