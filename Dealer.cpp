/* 
 * File:   Dealer.cpp
 * Author: vince
 *
 * Created on April 5, 2019, 6:38 PM
 */
#include "Dealer.h"

Dealer::Dealer() {
    hand = new Hand;
    money = new Money;  
    handScore = 0;
    hidden = true;
    win = false;
    lose = false;
    dealer.insert(std::pair<Hand*, Money*>(hand, money));
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->second->setBank(1600);
}

Dealer::~Dealer() {
    delete hand;
    delete money;
    dealer.clear();
}

int Dealer::getHandScore() const{
    return handScore;
}

std::string Dealer::getHand(int n, bool hidden) {
    if (hidden) {
        return "??";
    }
    
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    
    return m->first->getCard(n);
}

void Dealer::calculateHandScore(bool hidden) {
    if (hidden) {
        std::map<Hand*, Money*>::iterator m = dealer.begin();
        hiddenScore =  m->first->getCardValue(1);
    }
    
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->first->calculateScore();
    handScore = m->first->getScore();
}

void Dealer::hit(Cards card) {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->first->drawCard(card);
}

int Dealer::getMoney() {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    return m->second->getBank();
}

void Dealer::setMoney(int money) {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->second->setBank(money);
}
bool Dealer::checkHidden() const {
    return hidden;
}

void Dealer::setHidden(bool hidden) {
    this->hidden = hidden;
}

void Dealer::setHiddenScore(Cards card) {
    hiddenScore = card.getValue();
}

void Dealer::winMoney(int money) {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->second->winMoney(money);
}

void Dealer::loseMoney(int money) {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->second->loseMoney(money);
    if(getMoney() < 0) {
        m->second->setBank(0);
    }
}

void Dealer::prntHand() {
    std::cout << std::endl << "Dealer's hand is |";
    for (int i = 0; i < hand->getHandCount(); i++) {
        std::cout << getHand(i, checkHidden());
        if(i != hand->getHandCount() - 1) {
            std::cout << "|, |";
        }
    }
    calculateHandScore(checkHidden());
    std::cout << "|. Score of hand is " << getHandScore() << ". ";
}

void Dealer::clearHand() {
    std::map<Hand*, Money*>::iterator m = dealer.begin();
    m->first->clear();
}

int Dealer::getHiddenScore() const {
    return hiddenScore;
}

void Dealer::setLose() {
    lose = true;
    win = false;
}

bool Dealer::getLose() const {
    return lose;
}

bool Dealer::getWin() const {
    return win;
}

void Dealer::setWin() {
    win = true;
    lose = true;
}

void Dealer::restart() {
    //When the game is restarted, it is necessary to set both of the conditions to 
    //false in order to pass the for loop.
    win = false;
    lose = false;
    handScore = 0;
    clearHand();
}