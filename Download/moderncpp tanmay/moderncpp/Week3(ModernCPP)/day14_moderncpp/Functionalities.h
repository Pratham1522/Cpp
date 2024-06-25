#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<array>
#include<thread>
#include<iostream>
#include<functional>

using resultContainer = std::array<int,15>;
using inputContainer = std::array<int,5>;
using ThreadsArray = std::array<std::thread,3>;

void Factorial(inputContainer& inputArr, resultContainer& result);

void Cube(inputContainer& inputArr, resultContainer& result);

void Square(inputContainer& inputArr, resultContainer& result);

void MapThreadsToFunctions(ThreadsArray& th,inputContainer& inputArr, resultContainer& result);

void Display(resultContainer& result);

void Input(inputContainer& inputArr);

#endif // FUNCTIONALITIES_H
