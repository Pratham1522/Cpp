#include"Player.h"
#include<iostream>
#include<cstring>

int main(){
    Player* p=new Player[2];

    for(int i=0;i<2;i++){

        std::cout<<"\n\nEnter Player "<<i <<" Details.\n";
        std::string id;
        while(true){
            std::cout<<"Enter Player ID : ";
            std::cin>>id;
            if(isvalid(id)){
                p[i].setPlayerId(stoi(id));
                break;
            }else{
                std::cout<<"Invalid Input";
            }
        } 

        char* name=new char[20];
        std::cout<<"Enter Player Name : ";
        std::cin>>name;
        p[i].setPlayerName(name);

        float age;
        std::cout<<"Enter Player Age : ";
        std::cin>>age;
        p[i].setPlayerAge(age);

        std::string num;
        while(true){
            std::cout<<"Number Of Matches Player Played : ";
            std::cin>>num;
            if(isvalid(num)){
                p[i].setNumberOfMatchesPlayed(stoi(num));
                break;
            }else{
                std::cout<<"Invalid Input";
            }
        } 

        std::string rank;
        while(true){
            std::cout<<"Enter Player Rank : ";
            std::cin>>rank;
            if(isvalid(rank)){
                p[i].setNumberOfMatchesPlayed(stoi(rank));
                break;
            }else{
                std::cout<<"Invalid Input \n";
            }
        }

        int* score=new int[3];
        for(int i=0;i<3;i++){
            std::cout<<"Enter Score "<< i+1<<" : ";
            std::cin>>score[i];
        }  
        p[i].setScore(score);  
    }    

    std::cout<<p[0];
    std::cout<<p[1];

    bool res1=(p[0]<p[1]);
    std::cout<<"\np[0]<p[1] : "<<res1;

    bool res2=(p[0]==p[1]);
    std::cout<<"\np[0]==p[1] : "<<res2;

    int sum=p[0]+p[1];
    std::cout<<"\np[0]+p[1] : "<<sum;
}