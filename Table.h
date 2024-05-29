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

        std::vector<Hand> players;

        Deck shoe;

        void game_deal();

        void hit(Hand recipient);
        void stand(Hand recipient);
        void split(Hand recipient);
        void doubleDown(Hand recipient);
};


#endif //TABLE_H
