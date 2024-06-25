#include "Functionalities.h"

int main(){

    StringContainer str = {"abc","bcd","tanmay"};
    FnContainer functions;
    functions.push_back(FindAllVowelCharacters);
    functions.push_back(FindAndDisplayLastThreeCharacters);
    functions.push_back(FindFirstNonVowelCharacter);
    Adaptor(str,functions);
    // DataContainer data{"tanmay","abc","xyzo"};
    // DataOperation d1(data);
    // FnContainer fns{
    //     DataOperation::FindAllVowelCharacters,
    //     DataOperation::FindAndDisplayLastThreeCharacters,
    //     DataOperation::FindFirstNonVowelCharacter
    // };
    // d1.Adaptor(data,fns);
}
