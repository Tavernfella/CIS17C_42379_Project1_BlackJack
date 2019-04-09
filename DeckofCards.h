/* 
 * File:   DeckofCards.h
 * Author: vince
 *
 * Created on April 4, 2019, 10:33 AM
 */

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "Cards.h"
#include <iostream>
#include <vector> //Utilized vector to contain Cards to form a deck
#include <algorithm> //Utilized random_shuffle() to shuffle the deck
#include <iomanip> //Required for formatting output
#include <ctime> //Required for time()
#include <cstdlib> //Required for srand()

class DeckofCards {
    private:
        std::vector<Cards> deck;
        const int CAPACITY = 52; //Max number in a deck of BJ
        int cardsCount;
        
    public:
        DeckofCards();  
        ~DeckofCards();
        void shuffleDeck();
        void drainCards();
        Cards deal();
        int getCardsCount() const;
        void burn_a_Card();
        void prntDeck();
};


#endif /* DECKOFCARDS_H */

