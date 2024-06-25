##  static_assert 
- It is a C++11 feature that allows you to perform compile-time assertions. It checks a condition at compile time and produces a compiler error if the condition is false.
- Synthax : `static_assert(constexpr_condition,"optional_error_message"); `
- Eg : `static_assert(std::is_same<double, decltype(MulFun(1.2, 3))>(), "different \n");`
