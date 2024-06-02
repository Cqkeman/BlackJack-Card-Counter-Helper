#include <math.h>
#include <sstream>
#include "Card.h"

using namespace std;

Card::Card()
{
        // dust
}

const string Card::SUITS[] = {"Spades", "Diamonds", "Clubs", "Hearts"};

// Returns string representation of numerical card value
std::string Card::to_string(int value)
{
        if (value == 53)
                return "Black Joker";

        if (value == 54)
                return "Red Joker";

        // Determine suit and value
        int card = (value % 13 == 0) ? 13 : value % 13;
        int suit = (int) floor((double) value / 13.25);
        string cardName = "";

        switch (card)
        {
                case 1:
                        cardName = "Ace";
                        break;

                case 11:
                        cardName = "Jack";
                        break;

                case 12:
                        cardName = "Queen";
                        break;

                case 13:
                        cardName = "King";
                        break;

                default:
                        stringstream ss;
                        ss << card;
                        cardName = ss.str();
                        break;

        }

        return cardName.append(" of ").append(SUITS[suit]);

}

char Card::to_char(int value)
{
        int card = (value % 13 == 0) ? 13 : value % 13;
        int suit = (int) floor((double) value / 13.25);

        char cardChar;

        switch (card) {
                case 1:
                        cardChar = 'A';
                        break;
                case 10:
                        cardChar = 'X';
                        break;

                case 11:
                        cardChar = 'J';
                        break;

                case 12:
                        cardChar = 'Q';
                        break;

                case 13:
                        cardChar = 'K';
                        break;

                default:
                        cardChar = '0' + card;
                        break;
        }

        return cardChar;

}