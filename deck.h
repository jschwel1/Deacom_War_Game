#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "hand.h"
#include <vector>
#include <string>


class Deck: public Hand {
    private:
    std::vector<std::string> ranks = {"2", "3", "4", 
                                      "5", "6", "7",
                                      "8", "9", "10",
                                      "J", "Q", "K", "A"};
    std::vector<char> suits = {'C', 'H', 'S', 'D'};
    

    public:
        Deck(bool shuffled=true);
        Card deal();
        std::vector<Card> dealCards(int numCards);
        Hand dealHand(int numCards);
        void shuffleDeck();
        int numCardsLeft();


};

#endif 
