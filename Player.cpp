/* 
 * File:   Player.cpp
 * Author: vince
 *
 * Created on April 6, 2019, 9:31 AM
 */
#include "Player.h"

Player::Player() {
    //Allocating a new hand and new money; set all the assertive parameters to false to begin with.
    hand = new Hand;
    money = new Money;
    lose = false;
    win = false;
    jack = false;
}

Player::~Player() {
    //clearing up memory.
    delete hand;
    delete money;
}

void Player::setWin() {
    //Player's win condition. 
    win = true;
    lose = false;
}

void Player::setName(std::string name) {
    //Set the player's name when the game begins.
    this->name = name;
}

void Player::setLose() {
    //Player's lose condition.
    lose = true;
    win = false;
}

bool Player::getLose() const {
    return lose;
}

std::string Player::getName() const {
    return name;
}

int Player::getMoney() const {
    return money->getBank();
}

void Player::setWager(int wager) {
    //If player requires a wager larger than he has in bank, wager will be set to an invalid number.
    if(wager > getMoney() || getMoney() == 0) {
        this->wager = 9999;
    }
    //If it is valid, set the wager and subtract from the bank it takes to make the wager.
    else {
        this->wager = wager;
        loseMoney(wager);
    }
}
      
int Player::getWager() const {
    return wager;
}

void Player::setMoney(int money) {
    this->money->setBank(money);
}

void Player::winMoney(int money) {
    this->money->winMoney(money);
}

void Player::loseMoney(int money) {
    //When player loses money, the bank is reduced. If it's potentially dropping below zero, aka broke, it is set to 0 instead.
    this->money->loseMoney(money);
    if(getMoney() < 0) {
        this->money->setBank(0);
    }
} 
void Player::allIn() {
    //All in condition. The whole bank is moved to make wager.
    setWager(money->getBank());
    setMoney(0);
}

void Player::hit(Cards card) {
    //A card is passed(from a deck in main) into the hand, which is a deque of type Cards.
    hand->drawCard(card);
} 

void Player::clearHand() {
    //clear up the hand if needed.
    hand->clear();
}

int Player::getHandScore() const {
    return handScore;
}

void Player::calculateHandScore() {
    //Calculating the hand score. It also asserts whether it is a BJ. If it is, BJ is set to true. If it is busted, the player automatically loses.
    hand->calculateScore();
    handScore = hand->getScore();
    if(handScore == 21) {
        setJack();
    }
    if(hand->getScore() > 21) {
        setLose();
    }
}

void Player::setJack() {
    jack = true;
}

bool Player::checkJack() const {
    return jack;
}

std::string Player::getHand(int n){
    return hand->getCard(n);
}

void Player::prntHand() {
    //Printing the hand. The if condition within the loop is to format the hand with the cute || which indicates a card.
    //When it is the end of the hand, || is print out otherwise. Hand score is also calculated. 
    std::cout << "The hand you got is |";
    for (int i = 0; i < hand->getHandCount(); i++) {
        std::cout << getHand(i);
        if(i != hand->getHandCount() - 1) {
            std::cout << "|, |";
        }
    }
    calculateHandScore();
    std::cout << "|. Score of hand is " << getHandScore() << ". ";
}

void Player::restart() {
    //When the game is restarted, it is necessary to set both of the conditions to 
    //false in order to pass the for loop.
    win = false;
    lose = false;
    jack = false;
    handScore = 0;
    clearHand();
}