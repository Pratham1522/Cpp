#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<array>
#include <mutex>
#include<functional>
#include <thread>
std::mutex mt;

using DataContainer=std::array<int,5>;
using ResultContainer=std::array<int,15>;
using ThreadsArray= std::array<std::thread,3>;


void Factorial(DataContainer &data,ResultContainer &result);
void Sq(DataContainer &data,ResultContainer &result);
void Cube(DataContainer &data,ResultContainer &result);
void MapThreadsToFunction(ThreadsArray &th,DataContainer &data,ResultContainer &result);
void JoinThreads(ThreadsArray &th);
void Display(ResultContainer &result);
void Input(DataContainer &data);


#endif // FUNCTIONALITIES_H
