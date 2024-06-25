#pragma once
#include<iostream>
#include<cstring>

class Player{
    private:
        int playerId;
        char* playerName;
        float playerAge;
        int numberOfMatchesPlayed;
        int playerRank;
        int* score;

    public:
        Player();
        Player(Player &);
        ~Player();

        void operator= (Player &);
        // Player(int id, char * name, float age, int num, int rank, int * arr);
        // void accept();
        float calculateAverageScore();
        bool operator< (Player&);
        bool operator==(Player&);
        int operator+(Player&);

        int getPlayerId() const { return playerId; }
        void setPlayerId(int playerId_) { playerId = playerId_; }

        char* getPlayerName() const { return playerName; }
        void setPlayerName(char* playerName_) { playerName = playerName_; }

        float getPlayerAge() const { return playerAge; }
        void setPlayerAge(float playerAge_) { playerAge = playerAge_; }

        int getNumberOfMatchesPlayed() const { return numberOfMatchesPlayed; }
        void setNumberOfMatchesPlayed(int numberOfMatchesPlayed_) { numberOfMatchesPlayed = numberOfMatchesPlayed_; }

        int getPlayerRank() const { return playerRank; }
        void setPlayerRank(int playerRank_) { playerRank = playerRank_; }

        int* getScore() const { return score; }
        void setScore(int* score_) { score = score_; }
        
        friend std::ostream& operator<< (std::ostream&,Player&);

};
// bool isvalid(char* );
bool isvalid(std::string s);