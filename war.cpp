#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"
#include "deck.h"

// Uncomment this line to print out the contents of each player's hand and pile
//#define SHOW_CARDS

/** std::string displayTable(Hand& hand1, Hand& hand2, Hand& pile1, Hand& pile2, Hand& table1, Hand& table2)
* @brief: This function is passed both players' hands, piles, and table-piles and prints them out to show 
*         what's on the table and how many cards are in each player's hand.
* @param hand1 Hand object for player 1's hand
* @param hand2 Hand object for player 2's hand
* @param pile1 Hand object for player 1's pile of won cards
* @param pile2 Hand object for player 2's pile of won cards
* @param table1 Hand object for player 1's cards current in play on the table
* @param table1 Hand object for player 1's cards current in play on the table
**/
std::string displayTable(Hand& hand1, Hand& hand2, Hand& pile1, Hand& pile2, Hand& table1, Hand& table2);

int main(){
    bool autoplay;          // Display option
    char selection;
    bool war = false;       // Determines if there was a tie in the previous round
    int round = 1;          // Counts how many rounds were played
    Deck deck(true);        // Deck of cards
    Hand h1, h2;            // Cards for each player
    Hand table1, table2;    // Cards from each player on the table
    Hand pile1, pile2;      // Cards won by each player before being before
                            // going back into the player's hand
    h1 = deck.dealHand(26); // Deal out half the cards to each player
    h2 = deck.dealHand(26); // 

    // Get the user's display choice
    std::cout << "Press " << std::endl << "<1> for autoplay" << std::endl <<  "<2> for one round at a time" << std::endl;
    std::cin >> selection;
    autoplay = (selection == '1');
    if (!autoplay){
        std::cout << "Press <enter> to cycle though each round" << std::endl;
        getchar();
    }
   
    // Game ends when one player runs out of cards
    while(h1.numCards() && h2.numCards()){ 
#ifdef SHOW_CARDS
        std::cout << "P1: ";
        for (int i = 0; i < h1.numCards(); i++){
            std::cout << h1.showCardAt(i).toString() << ", ";
        }
        std::cout << " | ";
        for (int i = 0; i < pile1.numCards(); i++){
            std::cout << pile1.showCardAt(i).toString() << ", ";
        }
 
        std::cout << std::endl;
        std::cout << "P2: ";
        for (int i = 0; i < h2.numCards(); i++){
            std::cout << h2.showCardAt(i).toString() << ", ";
        }
        std::cout << " | ";
        for (int i = 0; i < pile2.numCards(); i++){
            std::cout << pile2.showCardAt(i).toString() << ", ";
        }
        std::cout << std::endl;
#endif
        // Both players place cards on the table
        if (!war){
            std::cout << "############### Round " << std::to_string(round++) << " ###############" << std::endl;
            table1.addCardToTop(h1.dealTopCard());
            table2.addCardToTop(h2.dealTopCard());
        }
        // If there is a war, each player deals 4 more cards
        else{
            for (int num = 0; num < 4 && h1.numCards(); num++){
                table1.addCardToTop(h1.dealTopCard());
                if (h1.numCards()==0 && pile1.numCards()>0){
                    pile1.shuffleHand();
                    h1.addCards(pile1.dealAllCards());
                }
            }
            for (int num = 0; num < 4 && h2.numCards(); num++){
                table2.addCardToTop(h2.dealTopCard());
                if (h2.numCards()==0 && pile2.numCards()>0){
                    pile2.shuffleHand();
                    h2.addCards(pile2.dealAllCards());
                }
            }

        }

        std::cout << displayTable(h1, h2, pile1, pile2, table1, table2) << std::endl;

        // Determine winner or tie
        war = false;
        if (table1.showTopCard() > table2.showTopCard()){
            pile1.addCards(table1.dealAllCards());
            pile1.addCards(table2.dealAllCards());
            std::cout << "Player 1 wins this round" << std::endl;
        }
        else if (table1.showTopCard() < table2.showTopCard()){
            pile2.addCards(table1.dealAllCards());
            pile2.addCards(table2.dealAllCards());
            std::cout << "Player 2 wins this round" << std::endl;
        }
        else{
            war = true;
            std::cout << "WAR!" << std::endl;
        }

        // If a player ran out of cards in their hand, but still
        // has some in their piles, shuffle the winning pile and put
        // it back in their hand.
        if (h1.numCards()==0 && pile1.numCards()>0){
            pile1.shuffleHand();
            h1.addCards(pile1.dealAllCards());
        }
        if (h2.numCards()==0 && pile2.numCards()>0){
            pile2.shuffleHand();
            h2.addCards(pile2.dealAllCards());
        }

        // Wait to continue
        if (!autoplay){
            getchar();
        }
    }

    // Display the winner
    std::cout << "Player " << ((h1.numCards()+pile1.numCards() == 52)?"1":"2") << " Won!" << std::endl;

}



std::string displayTable(Hand& hand1, Hand& hand2, 
                         Hand& pile1, Hand& pile2,
                         Hand& table1, Hand& table2){
    std::string dispStr = "\tPlayer 1: \r\n";
    dispStr+="Cards in hand:" + std::to_string(hand1.numCards()+pile1.numCards());
    dispStr+="\r\n";
    dispStr+="# cards on table:" + std::to_string(table1.numCards());
    dispStr+=", card in play: " + table1.showTopCard().toString();
    dispStr+="\r\n\r\n";

    dispStr += "\tPlayer 2: \r\n";
    dispStr+="Cards in hand:" + std::to_string(hand2.numCards()+pile2.numCards());
    dispStr+="\r\n";
    dispStr+="# cards on table:" + std::to_string(table2.numCards());
    dispStr+=", card in play: " + table2.showTopCard().toString();
    dispStr+="\r\n";

    return dispStr;
}
