/* 
 * File:   DeckofCards.cpp
 * Author: vince
 *
 * Created on April 4, 2019, 4:15 PM
 */
#include "DeckofCards.h"

DeckofCards::DeckofCards() {
    //Seed random_shuffle()
    srand(time(0));
    
    cardsCount = CAPACITY;
    
    //Populate the deck with cards. Get their suits and values. Values are automatically converted in the constructor of Cards object.
    for (int i = 1; i <= 13; i++) {
        deck.push_back(Cards(i, "♣", false));
        deck.push_back(Cards(i, "♦", false));
        deck.push_back(Cards(i, "♥", false));
        deck.push_back(Cards(i, "♠", false));
    }
    
    shuffleDeck();
}

DeckofCards::~DeckofCards(){
    drainCards();
}
void DeckofCards::burn_a_Card() {
    //Function for buring a card.
    if (getCardsCount() > 0) {
        deck.pop_back();
        cardsCount--;
    }
    else {
        std::cout << "Burn failed. There is no card left in the deck!" << std::endl;
    }
}

void DeckofCards::shuffleDeck(){
    //Utilizing random_shuffle() to shuffle the deck of object Cards.
    std::random_shuffle(deck.begin(), deck.end());
}

void DeckofCards::drainCards(){
    //This stimulates ditching a deck and get a new deck, if necessary.
    while(!deck.empty()) {
        deck.pop_back();
    }
    
    cardsCount = 0;
}
Cards DeckofCards::deal(){
    //Whenever a card is dealt, the deck is shuffled once.
    shuffleDeck();
    //Check whether there are still cards left in the deck.
    assert(getCardsCount() > 0);
    
    if (getCardsCount() > 0) {
        return deck.at(cardsCount-1);
        cardsCount--;
    }
}

int DeckofCards::getCardsCount() const{
    return cardsCount;
}

void DeckofCards::prntDeck() {
    //Printing the deck. It only prints 6 cards per line. Width is set to be 20 and it is right aligned. If it has a specific rank,
    //print the letter of the rank, otherwise print the number.
    std::cout << "Printing the deck: " << std::endl << std::endl;
    for(int i = 1; i <= deck.size(); i++) {
        std::cout << std::setw(20) << std::right;
        if(deck.at(i-1).getRank()== 'J' || deck.at(i-1).getRank() == 'Q' || deck.at(i-1).getRank() == 'K' || deck.at(i-1).getRank() == 'A') {
            std::cout<< deck.at(i-1).getSuit() << deck.at(i-1).getRank();
        }
        else{
            std::cout << deck.at(i-1).getSuit() << deck.at(i-1).getValue();
        }
        if (i % 6 == 0 && i != 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "There are " << getCardsCount() << " Cards left in the deck." << std::endl << std::endl;   
}
