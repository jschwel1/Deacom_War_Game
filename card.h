#ifndef CARD_H
#define CARD_H
#include <map>
#include <string>


class Card{
    public:
        /** Card(std::string, rank, char suit)
        * @brief Constructs a new Card object with a given suit and rank
        * @param rank string representation of the number or letter
        * @param suit char in {C,H,S,D} for {Clubs, Hearts, Spades, Diamonds}
        */
        Card(std::string rank, char suit);

        /** bool operator>(const Card& other) const
        *   bool operator>(const Card& other) const
        *   bool operator==(const Card& other) const
        * @brief Overrides the comparison operators to compare cards
        */
        bool operator>(const Card& other) const;
        bool operator<(const Card& other) const;
        bool operator==(const Card& other) const;

        /** std::string toString()
        @brief Generates a string representation of the card
        @return a string in the form rank+suit
        */
        std::string toString();

    private:
        // map of rank strings to their values in War
        static const std::map<std::string, char> values;
        // Enum of suits 
        enum class suitsEnum {CLUBS, HEARTS, SPADES, DIAMONDS};
        // Map of suitEnum to their char representations
        static const std::map<suitsEnum, char> suits;

        // Suit of the card object
        char suit;
        // Rank of the card object
        std::string rank;


};
#endif
