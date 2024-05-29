//
// Created by 24lwt on 27/05/2024.
//

#include "deck.h"
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

Deck::Deck(bool hasJokers_, int decks_)
        : hasJokers(hasJokers_), decks(decks_)
{
    if (hasJokers)
        deckSize = 54;
    else
        deckSize = 52;

    initialize();

}

void Deck::initialize()
{
    // Clear vectors
    cards.clear();
    discard.clear();

    // Populate vectors
    for (int i = 1; i <= (54 * decks); i++)
    {
        int faceValue = i;

        while (faceValue > 54)
            faceValue -= 54;

        // If specified to have no jokers, skip adding jokers
        if (hasJokers || faceValue != 53 && faceValue != 54)
            cards.push_back(i);
        else if (faceValue == 53 || faceValue == 54)
            continue;

    }

}

// Randomly shuffle the deck
void Deck::shuffle()
{
    srand(time(NULL));
    random_shuffle(cards.begin(), cards.end());

}

// Regenerate deck
void Deck::rebuild()
{
    initialize();

}

void Deck::burn()
{
    int drawnCard = cards.at(0);


    cards.erase(cards.begin());
    discard.push_back(drawnCard);

}

// Returns card from top of deck, then discards it
int Deck::draw()
{
    int drawnCard = cards.at(0);

    burn();
    return drawnCard;

}

bool Deck::has_jokers()
{
    return hasJokers;

}

int Deck::get_decks()
{
    return decks;

}

int Deck::get_deck_size()
{
    return deckSize;

}

int Deck::get_remaining()
{
    return cards.size();

}