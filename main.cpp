/* 
 * File:   main.cpp
 * Author: vince
 *
 * Created on April 5, 2019, 12:47 PM
 */
#include "DeckofCards.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

void hitOrStand();
int main(int argc, char** argv) {
    //Variables of type char are to mostly hold the user's input to determine their choice as the game proceeds. They are declared 
    //outside of the for loop, which controls whether the player wants to start a new round. Boolean variables are either for breaking out
    //from for loops or determining whether they have the same handScore. On this term, they are "valid" and "draw" respectively.
    char again;
    string playerName;
    char seeRule; 
    char wager;
    char hitStand;
    bool valid = false;
    bool draw = false;
    
    //Create a new deck;
    DeckofCards* deck = new DeckofCards;
    //Print the whole deck and then shuffle it.
    deck->prntDeck();
    
    cout << endl << "Shuffling..." << endl;
    cout << "The deck has now been shuffled again. " << endl << endl;
    
    //Get the player's name and initiate the game. Create a new dealer object as well.
    cout << "Player, please enter your name: ";
    getline(cin, playerName);

    Player* player = new Player;
    player->setName(playerName);
    Dealer* dealer = new Dealer;

    //Interface of whether the player would like to see the rule of BlackJack before playing.
    cout << "Welcome to the game of Blackjack, " << player->getName() <<". Would you like to see the rule of the game?" << endl;
    cout << "Please enter Y for yes and N for no: "; 
    cin >> seeRule;

    //Use a while loop to validate the player's input.
    while(seeRule != 'N' && seeRule != 'Y' && seeRule != 'y' && seeRule != 'n') {
        cout << "Invalid choice. Please try again." << endl;
        cout << "Please enter Y for yes and N for no: "; 
        cin >> seeRule;
    }
    
    //Displaying the rule of the game if the player wants to see it; otherwise, jumps into the game.
    if (seeRule == 'Y' || seeRule == 'y') {
        do {
            cout << endl;
            cout << "How to Play Blackjack:" << endl;
            cout << "1. Make a bet from $1 to All In." << endl;
            cout << "2. The dealer will give you two cards and show one of his cards." << endl;
            cout << "3. You can double your bet anytime before you hit or stand." << endl;
            cout << "4. You have an option to add more cards by choosing 'HIT' but you lose automatically if your value of cards exceeds 21." << endl;
            cout << "5. Choose 'STAND' when you are ready to play the hand." << endl;
            cout << "6. The dealer will reveal his hidden card and will hit if they have 14 or lower or score lower than that of yours.";
            cout << " They will not hit if your hand is already busted." << endl;
            cout << "7. You win when the combined value of your cards is greater than that of the dealer." << endl;
            
            //They have the choice of seeing the rule for as many times as they want. i.e. to stay within the loop.
            cout << "Are you ready to play the game?" << endl;
            cout << "A.Play the game.        B.Review the rule again." << endl << endl << "Enter your choice:";
            cin >> seeRule;
            
            //Validating the input.
            while(seeRule != 'A' && seeRule != 'a' && seeRule != 'B' && seeRule != 'b') {
                cout << "Invalid choice. Please try again." << endl;
                cin >> seeRule;
            }
        }while (seeRule == 'B' || seeRule == 'b');
    }

    cout << endl <<  "Wish you a gambler's lucky streak, and enjoy the game of blackjack!" << endl;
    
    //This do-while loop below encompasses the main fabric of the game, namely every round of the game is an iteration if the player choose
    // to play for another round. The variable "again" of type char holds player's decision of whether he wants another round, and it thereafter 
    //asserts whether to reiterate. If the player doesn't want another round(again == 'N' or 'n'), the loop terminates, and the game is over.
    do {
        //Displaying player's initial bank amount if this is for the first time. Otherwise, get the money remaining. The syntax is the same, but
        //the output is worded differently just to differentiate the two scenarios. 
        if (again == 'Y' || again == 'y') {
            cout << "You have $" << player->getMoney() << " in your bank. " << endl;
        }
        else {
            //The case of first time here. The player has $800 to begin with. It is worth noting that the dealer has $1600 to start with.
            cout << "To begin with, you have $" << player->getMoney() << " in your bank. " << endl;
        }
        //Displaying the wager options. (Player cannot choose wager that is larger than what he has in the bank. This will be validated as it comes later.
        cout << endl << "A.$1     B.$5     C.$25     D.$50     E.$100     F.$500     G.ALL IN";
        cout << endl << endl << "Now, please enter a letter to choose your wager: ";
        cin >> wager;
        
        //Use a switch combined with a while loop to determine/validate the player's input. If the input is valid, the corresponding case sets up the
        //wager. If the input is invalid, or the wager is required on insufficient bank amount, the player stays within the while loop until he provides
        //a valid input.
        //Also, Variable "valid" of type bool asserts whether the input is valid. If it is not, none of the alphabetic case is met and it falls to default,
        //where it is the only place "valid" is set to false. In that case, the loop reiterates.
        while(!valid) {
            switch(wager) {
                case('a'):
                case('A'):
                    player->setWager(1);
                    valid = true;
                    break;
                case('b'):
                case('B'):
                    player->setWager(5);
                    valid = true;
                    break;
                case('c'):
                case('C'):
                    player->setWager(25);
                    valid = true;
                    break;
                case('d'):
                case('D'):
                    player->setWager(50);
                    valid = true;
                    break;
                case('e'):
                case('E'):
                    player->setWager(100);
                    valid = true;
                    break;
                case('f'):
                case('F'):
                    player->setWager(500);
                    valid = true;
                    break;
                case('g'):
                case('G'):
                    player->allIn();
                    //9999 is a pseudo number which indicates the required wager is invalid or bank amount is 0. Obviously, if it's 0, 
                    //the player cannot all in because he has nothing on the table.
                    if (player->getWager()!=9999) {
                        cout << "*****ALL IN!*****." << endl;
                    }
                    valid = true;
                    break;
                //default case: invalid input. Valid is false. OK. Try again!
                default:
                    valid = false;
            }
            //Likewise here. Display the wager if it is valid, or rebut it. 
            if (player->getWager()!=9999) {
                cout << "Your current wager is $" << player->getWager() << "." << endl;
            }
            else {
                cout << "***Insufficient money for this wager***" << endl;
                valid = false;
            }
            //Validating the player's input.
            if (!valid) {
                cout << "Invalid choice. Please try again." << endl;
                cout << endl << "A.$1     B.$5     C.$25     D.$50     E.$100     F.$500     G.ALL IN";
                cout << endl << endl << "Now, please enter the letter to choose your wager: ";
                cin >> wager;
            }
        }
        //After the loop, set the valid back to 'false' as it was so initialized for another possible round.
        valid = false;

        //Displaying both of their bank after making a wager. Dealer's is untouched, while player's is substracted from it
        //the bet he has to make.
        cout << "Player's bank: $" << player->getMoney() << endl;
        
        //The dealer's bank is $1600. Displayed here.
        cout << "Dealer's bank: $" << dealer->getMoney() << endl;
        
        //Burn a card before dealing a card; To begin with, each of them holds two cards in hand.
        deck->burn_a_Card();
        dealer->hit(deck->deal());
        deck->burn_a_Card();
        dealer->hit(deck->deal());

        //The dealer's hand is different in the sense that one of the card is unrevealed from the player, whereas the player has both of the two
        //cards on display. 
        cout << "Dealer's hand is |" << dealer->getHand(0, dealer->checkHidden()) << "|, |";
        dealer->calculateHandScore(dealer->checkHidden());
        dealer->setHidden(false);
        cout << dealer->getHand(1, dealer->checkHidden());
        cout << "|. Score of hand is " << dealer->getHiddenScore() << "." << endl;
        
        //Same here. Burn before deal;
        deck->burn_a_Card();
        player->hit(deck->deal());
        deck->burn_a_Card();
        player->hit(deck->deal());
        player->prntHand();
        
        //It is always player's turn first. Here comes the loop to determine what kind of hand he gets at the beginning, and what of that he ends
        //up getting.
        
        //If the player is lucky enough to hit a BlackJack with his starting hand, he doesn't go into the loop.
        if(player->checkJack()) {
            cout << "BLACKJACK!!" << endl;
            hitStand = 'W';
        }
        do {
            //Checking if the player gets BJ. If he does, he stays out of all of these conditions.
            if(!player->checkJack()) {
                //Hit or stand? If he chooses to hit, well give him a card. If he stands, his turn terminates and the dealer starts.
                cout << "Hit or stand?" << endl;
                cout << endl << "A.Hit         B.Stand" << endl;
                cin >> hitStand;
                
                //A switch to determine the input. 
                switch(hitStand) {
                    case('a'):
                    case('A'):
                        player->hit(deck->deal());
                        valid = true;
                        break;
                    case('b'):
                    case('B'):
                        valid = true;
                        break;
                    //Again, default case is met when the input meets none of the valid options.
                    default:
                       valid = false;
                }
            }
            //Validating the player's input.
            if(!valid) {
                cout << "Invalid choice. Please try again." << endl;
            }
            //Every time he decides to hit, displays his hand. 
            if(hitStand == 'A' || hitStand == 'a') {
                player->prntHand();
            }
         //The loop stimulates the process of hitting as long as he's not busted or decides to stand. Also, input has to be valid.
        }while((valid == false) || ((player->getHandScore() < 21) && (hitStand =='a' || hitStand == 'A')) );
        
        //Displays his stand with indication that he has chosen to stand.
        if(hitStand == 'b' || hitStand == 'B') {
            cout << "You chose stand. ";
            player->prntHand();
        }
        
        //Here, the assertion of the player's hand starts. If he's got over 21, he's busted. The money goes into dealer's bank, and the player loses.
        if(player->getHandScore() > 21) {
            player->setLose();
            cout << "Busted. You lose! " << endl;
            dealer->winMoney(player->getWager());
        }
        
        //Displays the dealer's hand regardless of what it is.
        dealer->prntHand();
        
        //If none of them has lost the game yet. In other words, the player survives the loop with possibly a BJ or a hand less than 21, 
        //the dealer must react to that and try to beat the player. This while loop entails a few strageties the dealer will adopt. 
        while(!player->getLose() && !dealer->getLose() && !draw) {
            //Case I: None of them has lost, and they didn't end up getting the same score.
            //The dealer will hit in order to bit the player, until he loses or wins.
            if(dealer->getHandScore() < player->getHandScore()) {
                dealer->hit(deck->deal());
                dealer->prntHand();
                //If the dealer busted, the player wins. The player recovers his bank amount and wins the wager. The dealer loses the wager.
                if(dealer->getHandScore() > 21) {
                    dealer->setLose();
                    cout << "You win!" << endl;
                    player->winMoney(2*player->getWager());
                    dealer->loseMoney(player->getWager());
                }
                //The dealer gets BJ and the player doesn't. The dealer wins. MOney goes to the dealer.
                else if((dealer->getHandScore() == 21) && (player->getHandScore() != 21)) {
                    dealer->setWin();
                    cout << "Dealer gets BLACKJACK!! You lose! Better luck next time:)" << endl;
                    dealer->winMoney(player->getWager());
                }
                //The dealer gets a beating hand. The player loses. Money goes to the dealer.
                else if(dealer->getHandScore() > player->getHandScore()) {
                    dealer->setWin();
                    cout << "You lose! Better luck next time:)" << endl;
                    dealer->winMoney(player->getWager());
                }
                //They both get 21. It's a draw. The player recovers his bank amount.
                else if((dealer->getHandScore() == 21) && (player->getHandScore() == 21)) {
                    draw = true;
                    cout << "You and the dealer both get BLACKJACK. **Draw**. This is a close one. Better luck next time:)" << endl; 
                    player->winMoney(player->getWager());
                }
            }
            //Case II: While hitting, the dealer finds that he gets the same score as that of the player. It could be a draw, but does he have a chance
            //to beat the player? The computer is too dumb to tell unless I tell him what to do. Well, I guess if the player's score is less than 15, it
            //is a good chance to hit and not gets busted, which beats the player. That's what the dealer is gonna do here. 
            else if((dealer->getHandScore() == player->getHandScore()) && (player->getHandScore() <= 14)) {
                //Hit and print hand.
                dealer->hit(deck->deal());
                dealer->prntHand();
                //The dealer loses with a busted score.
                if(dealer->getHandScore() > 21) {
                    dealer->setLose();
                    cout << "You win!" << endl;
                    player->winMoney(2*player->getWager());
                    dealer->loseMoney(player->getWager());
                }
                //He wins with a BJ.
                else if(dealer->getHandScore() == 21) {
                    dealer->setWin();
                    cout << "Dealer gets BLACKJACK!! You lose! Better luck next time:)" << endl;
                    dealer->winMoney(player->getWager());
                }
                //He wins with a better hand.
                else if(dealer->getHandScore() > player->getHandScore()) {
                    dealer->setWin();
                    cout << "You lose! Better luck next time:)" << endl;
                    dealer->winMoney(player->getWager());
                }
            }
            //If non of them gets BJ and they end up with same scores, it is a draw. 
            else if(dealer->getHandScore() == player->getHandScore()) {
                draw = true;
                cout << "**Draw**. This is a close one. Better luck next time:)" << endl; 
            //Nobody wins, nobody loses. Player gets his wager back into his bank.
                player->winMoney(player->getWager());
            }
        }
        
        //Set hidden to true and clear both of player's and dealer's hands, so if the player decides 
        // to go for another round, he will be getting a new hand. These are restart conditions.
        dealer->setHidden(true);
        dealer->restart();
        player->restart();
        valid = false;
        draw = false;
        //Check out their balance again.
        cout << endl << "Player's bank: $" << player->getMoney() << endl;
        cout << "Dealer's bank: $" << dealer->getMoney() << endl;
        
        //If the player doesn't have any money in his bank, he cannot play, the game terminates; vice versa, if he beats the player, the game terminates.
        if(player->getMoney() <= 0) {
            cout << "There's no money in your bank!! You lose:(" << endl;
            again = 'n';
        }
        else if(dealer->getMoney() <= 0) {
            cout << "There's no money in dealer's bank. You have won'em all! Nice job:)" << endl;
            again = 'n';
        }
        //If there's no card left in the deck, the game is over.
        else if(deck->getCardsCount() <= 0) {
            cout << "There's no card left in the deck! Game over." << endl;
        }
        //Asking whether the player wants another round.
        else {
            cout << "Another round?(Please enter a letter)" << endl;
            cout << "Y. Yes       N.No" << endl;
            cin >> again;
        }
        //Input validation for playing another round
        while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') {
            cout << "Invalid choice. Please try again." << endl;
            cout << "Another round? (Please enter a letter)" << endl;
            cout << "Y. Yes       N.No" << endl;
            cin >> again;
        }
    }while(again == 'Y' || again == 'y');
    
    cout << endl << "Thanks for playing!" << endl;
    
    //Clearing up memory allocation at the end. The game is over.
    delete deck;
    delete player;
    delete dealer;

    return 0;
}
