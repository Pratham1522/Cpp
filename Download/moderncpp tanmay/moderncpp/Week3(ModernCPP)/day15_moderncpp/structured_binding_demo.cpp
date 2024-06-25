#include<iostream>
#include<array>

int main(){
    std::array<int,2> data {101,10};
    
    auto [employeeid, team_size] = data;
    /* 
        COPIES DATA[0] IN EMPLOYEEID
        COPIES DATA[1] IN TEAM_SIZE
     */
    std::cout<<employeeid<<" "<<team_size<<"\n";

    std::pair<int,std::string> info {101,"tanmay"};
    auto& [id_ref, name_ref] = info;
    /* 
        TAKES REFERENCE OF INFO IN THE TWO VARIABLES
     */
    std::cout<<id_ref<<" "<<name_ref<<"\n";
}
