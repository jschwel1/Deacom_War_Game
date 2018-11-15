#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "hand.h"
#include <vector>
#include <string>



class Deck: public Hand {
    private:
    // list of ranks available in cards
    std::vector<std::string> ranks = {"2", "3", "4", 
                                      "5", "6", "7",
                                      "8", "9", "10",
                                      "J", "Q", "K", "A"};
    // list of suits available for cards
    std::vector<char> suits = {'C', 'H', 'S', 'D'};
    

    public:
        /** Deck(bool shuffled=true)
        * @brief Generates a standard deck of 52 cards
        * @param shuffled determines if the deck should be shuffled after it is generated
                          this is defaulted to true
        */
        Deck(bool shuffled=true);

        /** Card deal()
        * @brief deals the top card from the deck
        * @return the card from the top of the deck
        */
        Card deal();

        /** std::vector dealCards(int numCards)
        * @brief deals numCards cards from the top of the deck into a vector. This 
        *        removes them from the deck
        * @param numCards the number of cards to deal
        * @return a vector of Cards from to the top of the deck
        */
        std::vector<Card> dealCards(int numCards);

        /** Hand dealHand(int numCards)
        * @brief deals numCards cards directly into a Hand object
        * @param numCards number of cards to deal
        * @return Hand Hand object of cards from the top of the deck
        */
        Hand dealHand(int numCards);

        /** shuffleDeck()
        * @brief shuffles the deck pseudo-randomly
        */
        void shuffleDeck();

        /** int numCardsLeft()
        * @brief returns the number of cards left in the deck
        * @return the number of cards in the deck
        */
        int numCardsLeft();
};

#endif 
