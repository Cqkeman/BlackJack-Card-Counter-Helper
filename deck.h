#ifndef DECK_H
#define DECK_H

#include <vector>

class Deck
{
public:
    Deck(bool hasJokers_ = false, int decks_ = 1);
    void shuffle();
    void rebuild();
    void burn();
    int draw();
    bool has_jokers();
    int get_decks();
    int get_deck_size();
    int get_remaining();

private:
    void initialize();
    bool hasJokers;
    int decks, deckSize;
    std::vector<int> cards, discard;

};

#endif //DECK_H