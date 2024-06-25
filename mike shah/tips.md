# C++ general tips
- use functions for whatever task possible.
- avoid making copies use `const` and `references(&)`.
- you may invoke copy constuctor bymistake , so instead delete the copy constructor and copy assignment operator or make them private.
- always init member variables with initializer list in class constructor.
- make use of RAII or remember to clear memory to avoid memory leak.
- check `this!=&rhs` for copy assignment operator.


- use functions for whatever task possible.
- avoid making copies use `const` and `references(&)`.
- if possible, provide default arguments.
- you may invoke copy constuctor bymistake , so instead delete the copy constructor and copy assignment operator or make them private.
- always init member variables with initializer list in class constructor.
- make use of RAII or remember to clear memory to avoid memory leak.
- check `this!=&rhs` for copy assignment operator.

//tracking : only detect once and then track it until it is present in the frame.
// for counting two counters, one total cars , one cars at a time.
