//
// Created by 24lwt on 27/05/2024.
//

#ifndef HAND_H
#define HAND_H

class Hand
{
public:
        std::vector<char> upCards = {};
        std::vector<char> downCards = {};

        int bet = 0;

        bool stand = false;
        bool blackjack = false;
        bool standoff = false;
        bool doubled = false;

        int insured = 0;



        int get_hand_total();
        void clear_hand();
        void show_downCards();
};


#endif //HAND_H
