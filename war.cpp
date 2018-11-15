#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"
#include "deck.h"


std::string displayTable(Hand& hand1, Hand& hand2, Hand& table1, Hand& table2);

int main(){
    bool autoplay; // Display option
    char selection;
    bool war = false;
    int round = 1;
    Deck deck(true); // Deck of cards
    Hand h1, h2; // Cards for each player
    Hand table1, table2; // Cards from each player on the table
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
        // Both players place cards on the table
        if (!war){
            std::cout << "############### Round " << std::to_string(round++) << " ###############" << std::endl;
            table1.addCardToTop(h1.dealTopCard());
            table2.addCardToTop(h2.dealTopCard());
        }
        // If there is a war, each player deals 4 more cards
        // IF THERE IS A WAR AND A PLAYER DOES NOT HAVE ENOUGH CARDS ONLY DEAL THAT MANY
        else{
            for (int num = 0; num < 4 && h1.numCards(); num++){
                table1.addCardToTop(h1.dealTopCard());
            }
            for (int num = 0; num < 4 && h2.numCards(); num++){
                table2.addCardToTop(h2.dealTopCard());
            }
        }

        std::cout << displayTable(h1, h2, table1, table2) << std::endl;
        war = false;
        if (table1.showTopCard() > table2.showTopCard()){
            h1.addCards(table1.dealAllCards());
            h1.addCards(table2.dealAllCards());
            std::cout << "Player 1 wins this round" << std::endl;
        }
        else if (table1.showTopCard() < table2.showTopCard()){
            h2.addCards(table1.dealAllCards());
            h2.addCards(table2.dealAllCards());
            std::cout << "Player 2 wins this round" << std::endl;
        }
        else{
            war = true;
            std::cout << "WAR!" << std::endl;
        }

        if (!autoplay){
            getchar();
        }
    }

    std::cout << "Player " << ((h1.numCards() == 52)?"1":"2") << " Won!" << std::endl;

}



std::string displayTable(Hand& hand1, Hand& hand2, 
                         Hand& table1, Hand& table2){
    std::string dispStr = "\tPlayer 1: \r\n";
    dispStr+="Cards in hand:" + std::to_string(hand1.numCards());
    dispStr+="\r\n";
    dispStr+="# cards on table:" + std::to_string(table1.numCards());
    dispStr+=", card in play: " + table1.showTopCard().toString();
    dispStr+="\r\n\r\n";

    dispStr += "\tPlayer 2: \r\n";
    dispStr+="Cards in hand:" + std::to_string(hand2.numCards());
    dispStr+="\r\n";
    dispStr+="# cards on table:" + std::to_string(table2.numCards());
    dispStr+=", card in play: " + table2.showTopCard().toString();
    dispStr+="\r\n";

    return dispStr;
}
