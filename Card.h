#ifndef CARD_H
#define CARD_H

class Card
{
public:
    static std::string to_string(int value);

    static char to_char(int value);

    // Spades
    static const int ACE_SPADES = 1;
    static const int TWO_SPADES = 2;
    static const int THREE_SPADES = 3;
    static const int FOUR_SPADES = 4;
    static const int FIVE_SPADES = 5;
    static const int SIX_SPADES = 6;
    static const int SEVEN_SPADES = 7;
    static const int EIGHT_SPADES = 8;
    static const int NINE_SPADES = 9;
    static const int TEN_SPADES = 10;
    static const int JACK_SPADES = 11;
    static const int QUEEN_SPADES = 12;
    static const int KING_SPADES = 13;

    // Diamonds
    static const int ACE_DIAMONDS = 14;
    static const int TWO_DIAMONDS = 15;
    static const int THREE_DIAMONDS = 16;
    static const int FOUR_DIAMONDS = 17;
    static const int FIVE_DIAMONDS = 18;
    static const int SIX_DIAMONDS = 19;
    static const int SEVEN_DIAMONDS = 20;
    static const int EIGHT_DIAMONDS = 21;
    static const int NINE_DIAMONDS = 22;
    static const int TEN_DIAMONDS = 23;
    static const int JACK_DIAMONDS = 24;
    static const int QUEEN_DIAMONDS = 25;
    static const int KING_DIAMONDS = 26;

    // Clubs
    static const int ACE_CLUBS = 27;
    static const int TWO_CLUBS = 28;
    static const int THREE_CLUBS = 29;
    static const int FOUR_CLUBS = 30;
    static const int FIVE_CLUBS = 31;
    static const int SIX_CLUBS = 32;
    static const int SEVEN_CLUBS = 33;
    static const int EIGHT_CLUBS = 34;
    static const int NINE_CLUBS = 35;
    static const int TEN_CLUBS = 36;
    static const int JACK_CLUBS = 37;
    static const int QUEEN_CLUBS = 38;
    static const int KING_CLUBS = 39;

    // Hearts
    static const int ACE_HEARTS = 40;
    static const int TWO_HEARTS = 41;
    static const int THREE_HEARTS = 42;
    static const int FOUR_HEARTS = 43;
    static const int FIVE_HEARTS = 44;
    static const int SIX_HEARTS = 45;
    static const int SEVEN_HEARTS = 46;
    static const int EIGHT_HEARTS = 47;
    static const int NINE_HEARTS = 48;
    static const int TEN_HEARTS = 49;
    static const int JACK_HEARTS = 50;
    static const int QUEEN_HEARTS = 51;
    static const int KING_HEARTS = 52;

    // Jokers
    static const int JOKER_BLACK = 53;
    static const int JOKER_RED = 54;

private:
    Card();

    static const std::string SUITS[];

};

#endif // CARD_H