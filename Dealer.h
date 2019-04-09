/* 
 * File:   Dealer.h
 * Author: vince
 *
 * Created on April 5, 2019, 6:11 PM
 */
#ifndef DEALER_H
#define DEALER_H
#include "Hand.h"
#include "Money.h"
#include <map>

class Dealer {
    private:
        std::map<Hand*, Money*> dealer;
        Hand* hand;
        Money* money;
        int handScore;
        bool hidden;
        bool lose;
        bool win;
        int hiddenScore; 
                
    public:
        Dealer();
        ~Dealer();
        void hit(Cards card);
        void winMoney(int money);
        void loseMoney(int money);
        bool getLose() const;
        void restart();
        void clearHand();
        void setLose();
        bool getWin() const;
        void setWin();
        void setMoney(int money);
        int getMoney();
        std::string getHand(int n, bool hidden);
        void calculateHandScore(bool hidden);
        int getHandScore() const;
        void setHiddenScore(Cards card);
        bool checkHidden() const;
        void setHidden(bool hidden);
        int getHiddenScore() const;
        void prntHand();
};


#endif /* DEALER_H */

