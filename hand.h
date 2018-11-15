#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <vector>


class Hand{
   public:
        Hand();
        Hand(std::vector<Card>& hand);

        int numCards(){ return hand.size();}

        Card dealTopCard();
        Card showTopCard();
        std::vector<Card> dealAllCards();
        void addCard(Card c);
        void addCards(std::vector<Card> cards);
        void addCardToTop(Card c);
        void shuffleHand();

    protected:
        std::vector<Card> hand;

};
#endif
