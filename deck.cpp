#include "deck.h"
#include <iostream>

Deck::Deck(bool shuffled):
    Hand(){
    for (auto& suit: suits){
        for (auto& rank: ranks){
            Card c(rank, suit);
            addCard(c);
        }
    }
    if (shuffled) shuffleDeck();
}

Card Deck::deal(){
    return dealTopCard();
}

std::vector<Card> Deck::dealCards(int numCards){
   std::vector<Card> cards = *(new std::vector<Card>(hand.begin(), hand.begin()+numCards));
   hand.erase(hand.begin(), hand.begin()+numCards);
   return cards;
}

Hand Deck::dealHand(int numCards){
    std::vector<Card> v = dealCards(numCards);
    return Hand(v);
}

void Deck::shuffleDeck(){
    shuffleHand();
}

int Deck::numCardsLeft(){
    return hand.size();
}
