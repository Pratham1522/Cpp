#include "Player.h"

Player::Player()
{
    playerId=0;
    playerName=new char[20];
    strcpy(playerName,"Pratham");
    playerAge=20;
    numberOfMatchesPlayed=0;
    playerRank=0;
    score=new int[3];
}

Player::Player(Player &obj){
    playerId=obj.playerId;
    playerName=new char[20];
    strcpy(playerName,obj.playerName);
    playerAge=obj.playerAge;
    numberOfMatchesPlayed=obj.numberOfMatchesPlayed;
    playerRank=obj.playerRank;
    score=new int[3];
    for(int i=0;i<3;i++){
        score[i]=obj.score[i];
    }
}
void Player:: operator= (Player &obj){
    playerId=obj.playerId;
    playerName=new char[20];
    strcpy(playerName,obj.playerName);
    playerAge=obj.playerAge;
    numberOfMatchesPlayed=obj.numberOfMatchesPlayed;
    playerRank=obj.playerRank;
    score=new int[3];
    for(int i=0;i<3;i++){
        score[i]=obj.score[i];
    }
}
Player::~Player(){
    delete []score;
    delete []playerName;
}

bool isvalid(std::string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            return false;
        }
    }
    return true;
}

float Player::calculateAverageScore()
{
    float avg=0;
    for(int i=0;i<3;i++){
        avg+=score[i];
    }
    return  avg/3.0;
}

bool Player::operator<(Player &obj)
{
    if(calculateAverageScore()<obj.calculateAverageScore()){
        return true;
    }
    return false;
}

bool Player::operator==(Player &obj)
{
    if(numberOfMatchesPlayed==obj.numberOfMatchesPlayed){
        return true;
    }
    return false;
}

int Player::operator+(Player &obj)
{   
    return calculateAverageScore()+obj.calculateAverageScore();
}

std::ostream& operator<<(std::ostream &o, Player &obj)
{
    o<<"\nPlayer Details are as follow : \n";
    o<<"Player Id is : "<<obj.playerId;
    o<<"\nPlayer Name is : "<<obj.playerName;
    o<<"\nPlayer Age is : "<<obj.playerAge;
    o<<"\nNumber of Matches Played : "<<obj.numberOfMatchesPlayed;
    o<<"\nPlayer rank is : "<<obj.playerRank;
    o<<"\nScores are : {"<<obj.score[0]<<", "<<obj.score[1]<<", "<<obj.score[2]<<"}\n";
    return o;
}

// void Player::accept()
// {
//     std::cout<<"\n***# Enter Player Details #***\n";
//     std::cout<<"Enter Player ID : ";
//     std::cin>>playerId;
//     std::cout<<"Enter Player name : ";
//     char* name;
//     std::cin>>name;
//     strcpy(playerName,name);
//     std::cout<<"Enter Player Age : ";
//     std::cin>>playerAge;
//     std::cout<<"Enter Number of matches Played : ";
//     std::cin>>numberOfMatchesPlayed;
//     std::cout<<"Enter Player Rank : ";
//     std::cin>>playerRank;
//     for(int i=0;i<3;i++){
//         std::cout<<"Enter Score "<< i+1<<" : ";
//         std::cin>>score[i];
//     }
// }
