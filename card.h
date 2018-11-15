#ifndef CARD_H
#define CARD_H
#include <map>
#include <string>


class Card{
    public:
        Card(std::string rank, char suit);
        bool operator>(const Card& other) const;
        bool operator<(const Card& other) const;
        bool operator==(const Card& other) const;
        std::string toString();

    private:
        static const std::map<std::string, char> values;
        enum class suitsEnum {CLUBS, HEARTS, SPADES, DIAMONDS};
        static const std::map<suitsEnum, char> suits;

        char suit;
        std::string rank;


};
#endif
