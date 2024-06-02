//
// Created by 24lwt on 27/05/2024.
//

#include<iostream>
#include <cstdlib>//for random function
#include "deck.h"
#include "Card.h"
#include "Table.h"
#include "Hand.h"

int main()
{
        const int numDecks = 8;
        int wealth = 10000;
        int minWealth = wealth


        Table Blackjack(numDecks);


        while(true){
                Blackjack.game_deal();


                break;
        }

        return 0;
}


/*
 * makes the blackjack game
 *
 *
 */

void displayGameState(Table game)
{
        std::vector<char> dealerCards = game.dealer.upCards;
        if(game.dealer.downCards.size() != 0)
                dealerCards.push_back('?');

        std::cout << "dealer's cards: ";
        for(int i = 0; i< dealerCards.size(); i++)
                std::cout << dealerCards[i] << " ";
        std::cout << "\n";

        for(int i = 0; i<game.players.size(); i++){
                std::cout << "hand " << '0'+i << "\'s  cards: ";
                for(int j=0; j<game.players[i].upCards.size(); j++)
                        std::cout << game.players[i].upCards[j] << " ";
                std::cout << std::endl;
        }

}