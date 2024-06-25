#include "DataOperation.h"

void DataOperation::Adaptor(const DataContainer &data, FnContainer &functions)
{
    for(auto fn : functions){
        fn(data);
        std::cout<<std::endl;
    }
}

void DataOperation::FindAllVowelCharacters(const DataContainer &data)
{
    int count=0;
    for(const std::string& str:data){
        for(int i=0;i<str.length();i++){
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||
            str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
                count++;
               
            }
        }
        std::cout<<"total count of vowels are: "<<count<<"\n";
    }
}

void DataOperation::FindAndDisplayLastThreeCharacters(const DataContainer &data)
{
    for(const std::string& str:data){
        if(str.length()<3){
            std::cout<<"the word has less than 3 words.\n";
        }
        // std::cout<<"The last 3 characters are: "<<str[str.length()-3]<<str[str.length()-2]<<str[str.length()-1]<<"\n";
        std::cout<<"last 3 chars are: "<< str.substr(str.length()-3)<<"\n";
    }
}

void DataOperation::FindFirstNonVowelCharacter(const DataContainer &data)
{
    for(const std::string& str:data){
        for(int i=0;i<str.length();i++){
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||
            str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){}
            else{
                std::cout<<str[i]<<"\n";
                break;
            }
        }
    }
}
