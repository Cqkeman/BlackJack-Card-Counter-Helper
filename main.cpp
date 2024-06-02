//
// Created by 24lwt on 27/05/2024.
//

#include<iostream>
#include <cstdlib>//for random function
#include "deck.h"
#include "Card.h"
#include "Table.h"
#include "Hand.h"

void displayGameState(Table game);

int main()
{
        const int numDecks = 8;
        int wealth = 10000;
        int numHands = 0;


        Table Blackjack(numDecks);


        while(true){


                std::cout<< "how many hands do you want to play?\n";
                std::cin >> numHands;

                Blackjack.make_bets(numHands, wealth);

                Blackjack.game_deal();

                displayGameState(Blackjack);
                char playerIN;

                for(Hand plyr : Blackjack.players)
                        Blackjack.blackjack(plyr);


                for (int i = 0; i < Blackjack.players.size(); ++i) {

                        if(Blackjack.players[i].stand) {
                                std::cout << "Player " << '1' + i << " has stood\n";
                                continue;
                        }
                        if(Blackjack.players[i].bust) {
                                std::cout << "Player " << '1'+i << " has busted\n";
                                continue;
                        }

                        std::cout << "what would like to do with hand " << i+1 << "\n";
                        std::cout << "H : hit\n S : stand\n";



                        if(Blackjack.players[i].upCards[0]==Blackjack.players[i].upCards[1])
                                std::cout << "s : split\n";

                        if(9 <= Blackjack.players[i].get_hand_total()
                        && Blackjack.players[i].get_hand_total() <= 11
                        && !Blackjack.players[i].doubled)

                                std::cout << "D : double\n";
                        if(Blackjack.dealer.upCards[0] == 'A'
                        && Blackjack.players[i].insured == 0)
                                std::cout << "I : insure\n";


                        std::cin >> playerIN;
                        switch (playerIN){
                                case'H':
                                        Blackjack.hit(Blackjack.players[i]);
                                        std::cout << "you pulled a "<< Blackjack.players[i].upCards.back() << " \n";
                                        if(Blackjack.players[i].get_hand_total() >21){
                                                std::cout << "oof, u busted\n";
                                                Blackjack.players[i].bust = true;
                                        }

                                        break;
                                case 'S':
                                        Blackjack.stand(Blackjack.players[i]);
                                        break;
                                case 's':
                                        Blackjack.split(Blackjack.players[i]);
                                        std::cout << "hand " << '1'+i << " drew ";
                                        std::cout << Blackjack.players[i].upCards.back() << "\n";
                                        std::cout << "hand " << '2'+i << " drew ";
                                        std::cout << Blackjack.players[i+1].upCards.back() << "\n";
                                        break;
                                case 'D':
                                        Blackjack.doubleDown(Blackjack.players[i]);
                                        std::cout << "hand " << '1'+i << "\'s bet has";
                                        std::cout << " been doubled to " << Blackjack.players[i].bet;
                                        break;

                                case 'I':
                                        Blackjack.insure( Blackjack.players[i]);
                                        std::cout << "hand " << '1'+i << "\'s bet has been insured for";
                                        std::cout << Blackjack.players[i].insured << "\n";
                                        break;
                                default:
                                        std::cout << "That isn\'t a valid option, try again\n";
                                        i--;
                                        break;
                        }
                }



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
        if(!game.dealer.downCards.empty())
                dealerCards.push_back('?');

        std::cout << "dealer's cards: ";
        for(char dealerCard : dealerCards)
                std::cout << dealerCard << " ";
        std::cout << "\n";

        for(int i = 0; i<game.players.size(); i++){
                std::cout << "hand " << '1'+i << "\'s  cards: ";
                for(char upCard : game.players[i].upCards)
                        std::cout << upCard << " ";

                std::cout << "\n hand " << '1'+i << " bet: " << game.players[i].bet;

                std::cout << "\n";
        }

}