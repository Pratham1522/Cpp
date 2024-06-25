#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include<functional>
#include "DataOperation.h"

using StringContainer = std::vector<std::string>;
using FnType = std::function<void(const StringContainer&)>;
using FnContainer = std::vector<FnType>;

void Adaptor(StringContainer& stringContainer, FnContainer& fnContainer);

extern FnType FindAllVowelCharacters;
extern FnType FindAndDisplayLastThreeCharacters;
extern FnType FindFirstNonVowelCharacter;

#endif // FUNCTIONALITIES_H
