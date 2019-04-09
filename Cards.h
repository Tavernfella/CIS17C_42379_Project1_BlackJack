/* 
 * File:   Cards.h
 * Author: vince
 *
 * Created on April 4, 2019, 10:48 AM
 */

#ifndef CARDS_H
#define CARDS_H
#include <string>
#include <assert.h>
#include <iostream>

class Cards {
    private:
        int value;
        char rank;
        std::string suit;
        bool hidden;
        
    public:    
        Cards();
        Cards(int value, std::string suit, bool hid_show);
        std::string getSuit() const;
        int getValue() const;
        bool isHidden() const;
        void setValue(int value);
        void setSuit(std::string suit);
        char getRank() const;
        void setRank(char rank);
        void setHidden(bool hid_show);
        std::string toString();
        enum rank {
            ACE = 1,
            JACK = 10,
            QUEEN = 10,
            KING = 10
        };     
        enum suit {
            SPADES,
            HEARTS,
            CLUBS,
            DIAMONDS
        };
};
#endif /* CARDS_H */

