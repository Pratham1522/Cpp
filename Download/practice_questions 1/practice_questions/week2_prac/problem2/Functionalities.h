#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<iostream>
#include<functional>

using FnContainer = std::vector<std::function<bool(int)>>;
using Container = std::vector<int>;
extern std::function<bool(int)> PredicateToFindOddNumbers;
extern std::function<bool(int)> PredicateToFindDivBy4;
extern std::function<bool(int)> PredicateToFindNegativeNumbers;
extern std::function<bool(int)> BindPredicateToFindNegativeNumbers;

// void Adaptor(Container &data, std::function<bool(int)> functions);

void Adaptor(Container &data,FnContainer& functions);

#endif // FUNCTIONALITIES_H
