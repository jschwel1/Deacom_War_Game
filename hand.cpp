#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "card.h"
#include "hand.h"


Hand::Hand(){
    // initialize random seed for shuffling
    std::srand(unsigned(std::time(nullptr)));
}

Hand::Hand(std::vector<Card>& h):
    hand(h){
    std::srand(unsigned(std::time(nullptr)));
}

Card Hand::dealTopCard(){
    Card c = hand.at(0);
    hand.erase(hand.begin());
    return c;
}

std::vector<Card> Hand::dealAllCards(){
    std::vector<Card> allCards(hand);
    hand.clear();
    return allCards;
}

Card Hand::showTopCard(){
    Card c = hand.at(0);
    return c;
}

void Hand::addCard(Card c){
    hand.push_back(c);
}

void Hand::addCards(std::vector<Card> cards){
    hand.insert(hand.end(), cards.begin(), cards.end());
}

void Hand::addCardToTop(Card c){
    hand.insert(hand.begin(), c);
}

void Hand::shuffleHand(){
    std::random_shuffle(hand.begin(), hand.end());
}

