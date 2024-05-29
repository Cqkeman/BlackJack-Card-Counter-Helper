//
// Created by 24lwt on 27/05/2024.
//

#include <iostream>
#include<vector>
#include "Hand.h"

using namespace std;

int Hand::get_hand_total()
{
    int total = 0;
    int softness = 0;

    for(int i = 0; i< upCards.size(); ++i)
    {
        switch(upCards[i])
        {
            case'A':
                total +=11;
                softness++
                break;
            case'K':
                total +=10;
                break;
            case'Q':
                total +=10;
                break;
            case'J':
                total +=10;
                break;
            case'T':
                total +=10;
                break;
            case'9':
                total +=9;
                break;
            case'8':
                total +=8;
                break;
            case'7':
                total +=7;
                break;
            case'6':
                total +=6;
                break;
            case'5':
                total +=5;
                break;
            case'4':
                total +=4;
                break;
            case'3':
                total +=3;
                break;
            case'2':
                total +=2;
                break;
        }

    }

    while(softness>0 && total>21)
    {
        total -=10;
        softness--;
    }

    return total;
}

void Hand::clear_hand()
{
    upCards.clear();
    upCards.shrink_to_fit();

    downCards.clear();
    downCards.shrink_to_fit();

}

void Hand::show_downCards()
{
    for(int i = 0; i<downCards.size(); ++i)
        upCards.push_back(downCards[i]);
}
