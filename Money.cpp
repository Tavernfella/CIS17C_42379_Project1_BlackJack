/* 
 * File:   Money.cpp
 * Author: vince
 *
 * Created on April 5, 2019, 3:37 PM
 */
#include "Money.h"

Money::Money() {
    //Initialize the bank to be $800. However, for the dealer, it is manually reset to $1600.
    setBank(800);
    setBet(50);
}

void Money::setBank(int bank) {
    this->bank = bank;
}

void Money::winMoney(int chip) {
    bank += chip;
}

void Money::loseMoney(int chip) {
    //when money is lost. When it goes below 0, take 0 instead.
    bank -= chip;
    
    if (bank < 0) {
        bank = 0;
    }
}

int Money::getBank() const {
    return bank;
}

int Money::getBet() const {
    return bet;
}

void Money::setBet(int bet) {
    this->bet = bet;
}