#include <iostream>
#include <string>
#include <map>
#include <string>
#include "card.h"

const std::map<std::string, char> Card::values = {
            {"2",2},
            {"3",3},
            {"4",4},
            {"5",5},
            {"6",6},
            {"7",7},
            {"8",8},
            {"9",9},
            {"10",10},
            {"J",11},
            {"Q",12},
            {"K",13},
            {"A",14}
};

const std::map<Card::suitsEnum, char> Card::suits = {
    {Card::suitsEnum::CLUBS, 'C'},
    {Card::suitsEnum::HEARTS, 'H'},
    {Card::suitsEnum::SPADES, 'S'},
    {Card::suitsEnum::DIAMONDS, 'D'}
};

Card::Card(std::string rank, char suit):
    suit(suit),
    rank(rank){
    if (suit != 'C' && suit != 'H' && suit != 'S' && suit != 'D'){
        throw "Unkown suit"+suit;
    }
    try {
        values.at(rank);
    }
    catch (std::exception& e){
        std::cerr << "Unkown rank: "  << rank << std::endl;
        throw e;
    }
}

bool Card::operator>(const Card& other) const {
    return values.at(rank) > values.at(other.rank);
}
bool Card::operator<(const Card& other) const {
    return values.at(rank) < values.at(other.rank);
}
bool Card::operator==(const Card& other) const {
    return values.at(rank) == values.at(other.rank);
}

std::string Card::toString(){
    return rank+suit;
}


