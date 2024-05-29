//
// Created by 24lwt on 27/05/2024.
//

#ifndef TABLE_H
#define TABLE_H

#include "Hand.h"
#include "Card.h"
#include "deck.h"

class Table
{
    Hand dealer;
    Deck shoe;

    void game_deal();

    void hit(Hand recipient);
    void stand(Hand recipient);
    void split(Hand recipient);
    void doubleDown(Hand recipient);
    void


};


#endif //TABLE_H
