//
// Created by 24lwt on 27/05/2024.
//

#ifndef TABLE_H
#define TABLE_H

#include "Hand.h"
#include "Card.h"
#include "deck.h"
#include <iostream>
#include <vector>

class Table
{
public:

        Hand dealer;

        std::vector<Hand> players = {};

        Deck shoe;

        int payout(Hand recipient);

        void game_deal();

        void hit(Hand recipient);

        void stand(Hand recipient);

        void split(Hand recipient);

        void doubleDown(Hand recipient);

        void insure(Hand recipient);

        void blackjack(Hand recipient);
};


/*
 * table fn docs:
 *
 * payout(recipient)
 *      pays out a hand object based on bet, insurance, blakcjack, standoff and bust
 *      payout is conducted even if someone loses as it returns a negative value
 *
 * game_deal()
 *      deals dealers cards, then deals each hand in the players vector
 *      does not reset the players hands
 *
 * hit(recipient)
 *      checks not stood
 *
 *      adds a card to the player's hand
 *      does not recalculate player total
 *
 * stand(recipient)
 *      sets recipient.stand to true
 *
 * split
 *      checks no invalid options
 *
 *      checks if both cards of recipient are the same and their hand has two cards
 *      if yes, it makes a new Hand object and appends it to the back of the
 *      players vector
 *
 * doubleDown(recipient)
 *      checks no invalid options
 *
 *      checks if hand total is 9, 10, or 11, then if that is true
 *      it doubles the bet and sets doubled to true so it can't be done again or split
 *
 */

#endif //TABLE_H
