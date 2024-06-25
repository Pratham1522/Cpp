#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include<iostream>
#include<vector>
#include<functional>

// #include "emptycontainer.h"
// #include "notmatchingcharaceter.h"
// #include "notenoughcharacter.h"
// #include""

using DataContainer = std::vector<std::string>;
using FnContainer = std::vector<FnType>;
using FnType = std::function<void(const DataContainer&)>;


class DataOperation
{
private:
    DataContainer _data;
    FnContainer _functions;
public:
    DataOperation() = delete;
    DataOperation(const DataOperation&) =delete;
    DataOperation(DataOperation&&) =delete;
    DataOperation& operator=(const DataOperation&)=delete;
    DataOperation& operator=(DataOperation&&)=delete;
    ~DataOperation() =default;

    DataOperation(DataContainer& data): _data{data}{}

    void Adaptor(const DataContainer& data,FnContainer& functions);
    void FindAllVowelCharacters(const DataContainer& data);
    void FindAndDisplayLastThreeCharacters(const DataContainer& data);
    void FindFirstNonVowelCharacter(const DataContainer& data);

};

#endif // DATAOPERATION_H
