#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <vector>


class Hand{
   public:
        /** Hand()
        * @brief Constructs an empty hand
        */
        Hand();

        /** Hand(std::vector<Card>& hand)
        * @brief Constructs a hand from a vector of card objects
        */
        Hand(std::vector<Card>& hand);

        /** numCards()
        * @brief How many cards are in the hand
        * @return an integer representing the size of the hand
        */
        int numCards(){ return hand.size();}

        /** dealTopCard()
        * @brief Removes the top card from the deck
        * @return the Card object that was at the top of the deck
        */
        Card dealTopCard();

        /** showTopCard()
        * @brief similar to dealTopCard, but does not remove the card
        * @return the Card object at the top of the hand
        */
        Card showTopCard();

        /** dealAllCards()
        * @brief removes all cards from the deck
        * @return a vector containing all the cards that were in the hand
        */
        std::vector<Card> dealAllCards();

        /** addCard(Card c)
        * @brief adds a Card object to the bottom of the hand
        * @param c Card object to be added
        */
        void addCard(Card c);

        /** addCards(std::vector<Card> cards)
        * @brief adds a vector of Card objects to the bottom of the deck, in order
        * @param cards vector of Card objects
        */
        void addCards(std::vector<Card> cards);

        /** addCardToTop(Card c)
        * @brief adds a card to the top of the hand
        * @param c Card object to add
        */
        void addCardToTop(Card c);

        /** shuffleHand
        * @brief shuffles the hand pseudo-randomly
        */
        void shuffleHand();

        /* showCardAt(int i)
        * @brief displays a card at the specified index. This will throw an out_of_range exception 
        *        index is out of range.
        * @param i index to get card from
        */
        Card showCardAt(int i);

    protected:
        // Hand object
        std::vector<Card> hand;

};
#endif
