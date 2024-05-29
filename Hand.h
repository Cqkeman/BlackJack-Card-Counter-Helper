//
// Created by 24lwt on 27/05/2024.
//

#ifndef HAND_H
#define HAND_H

class Hand
{
public:
    std::vector<char> upCards;
    std::vector<char> downCards;

    int get_hand_total();
    void clear_hand();
    void show_downCards();


};


#endif //HAND_H
