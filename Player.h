/* 
 * File:   Player.h
 * Author: vince
 *
 * Created on April 6, 2019, 9:23 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"
#include "Money.h"
#include "iostream"

class Player {
    private:
        std::string name;
        bool lose;
        bool win;
        Hand* hand;
        Money* money;
        int wager;
        int handScore;
        bool jack;
        
    public:
        Player();
        ~Player();
        int getMoney() const;
        std::string getHand(int n);
        int getHandScore() const;
        void setName(std::string name);
        std::string getName() const;
        void setWager(int wager);
        void setWin();
        bool checkJack() const;
        int getWager() const;
        void setLose();
        void clearHand();
        void restart();
        bool getLose() const;
        void setJack();
        void setMoney(int money);
        void calculateHandScore();
        void loseMoney(int money);
        void winMoney(int money);
        void hit(Cards card);
        void allIn();
        void prntHand();
};


#endif /* PLAYER_H */

