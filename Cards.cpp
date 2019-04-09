/* 
 * File:   Cards.cpp
 * Author: vince
 *
 * Created on April 4, 2019, 1:02 PM
 */
#include "Cards.h"

Cards::Cards(int value, std::string suit, bool hid_show) { 
    //The constructor sets a specific rank. If it is not one of the four specific rank, it is set to 'N'.
    //Set value and suit.
    setRank('N');
    setValue(value);
    setSuit(suit);
    setHidden(hid_show);
}

int Cards::getValue() const{
    return value;
}

bool Cards::isHidden() const {
    return hidden;
}

std::string Cards::getSuit() const {
    return suit;
}

void Cards::setValue(int value) {
    //Assert whether the value is valid.
    assert(value >= 1 && value <= 13);
    
    //Use a switch to convert the specific numerical value to a rank.
    switch (value) {
        case(1):
            this->value = ACE;
            setRank('A');
            break;
        case (11):
            this->value = JACK;
            setRank('J');
            break;
        case (12):
            this->value = QUEEN;
            setRank('Q');
            break;
        case (13):
            this->value = KING;
            setRank('K');
            break;
        default:
            this->value = value;
    }
}

void Cards::setRank(char rank) {
    this->rank = rank;
}

char Cards::getRank() const {
    return rank;
}

void Cards::setHidden(bool hid_show){
    //to check whether a card is hidden. This is one of the foundation features of the class
    hidden = hid_show;
}

void Cards::setSuit(std::string suit) {    
    this->suit = suit;
}

std::string Cards::toString() {
    //Create a toString() function for Cards class, which stimulates the one of the features of JAVA.
    //The main intention here is to return a string that represents the card when a Cards object is created.
    std::string retval;
    
    retval = getSuit();
    
    //Return the suit. Also, if it is one of the four specific rank, append the letter other than a number.
    if(getRank()== 'J' || getRank() == 'Q' || getRank() == 'K' || getRank() == 'A') {
        retval += getRank();
    }
    else {
        //Utilizing to_string() here
        retval += std::to_string(getValue());
    }

    return retval;
}