//
// Created by 24lwt on 27/05/2024.
//

#include "Table.h"
#include <cstdlib>

int Table::payout(Hand recipient)
{
        if(recipient.bust)
                return recipient.insured-recipient.bet;

        if(recipient.standoff)
                return 0;

        if(recipient.blackjack)
                return recipient.bet*1.5;

        return recipient.bet;

}

void Table::make_bets(int numHands, int currentWealth)
{
        Hand handDefault;
        int bet;
        int maxLoss = currentWealth;

        players.clear();

        for (int i = 0; i < numHands; ++i) {
                players.push_back(handDefault);
                std::cout << "Place bet for hand " << '1'+i << "\n";
                while(true){
                        std::cin >> bet;
                        if(maxLoss - bet >=0 && bet>=0){
                                maxLoss -= bet;
                                players[i].bet = bet;
                                break;
                        }
                        std::cout << "that bet would make you broke, have another bet:\n";
                }
        }

        for (int i = 0; i < players.size(); ++i) {
                if(players[i].bet < 2){
                        std::cout << "I\'ve noticed that hand " << '1'+i << " has a bet below the minimum\n";
                        std::cout << "this isn\'t allowed so ill remove that hand\n";
                        players.erase(players.begin()+i);
                }

        }


}

void Table::game_deal()
{
        dealer.upCards.push_back(Card::to_char(shoe.draw()));
        dealer.downCards.push_back(Card::to_char(shoe.draw()));

        for(int i=0; i<2; i++)
        {
                for(int j=0; j<players.size(); j++)
                {
                        players[j].upCards.push_back(
                                Card::to_char(
                                        shoe.draw()
                                        )
                                );
                }
        }

}

void Table::hit(Hand recipient)
{
        if(recipient.stand)
                return;

        recipient.upCards.push_back(
                Card::to_char(
                        shoe.draw()
                        )
                );
}

void Table::stand(Hand recipient)
{
        recipient.stand = true;
}

void Table::split(Hand recipient)
{
        if(recipient.stand)
                return;
        if(recipient.doubled)
                return;
        if(recipient.insured == 0)
                return;

        if(recipient.upCards.size() != 2)
                return;
        if(recipient.upCards[0] != recipient.upCards[1])
                return;

        Hand newHand;


        recipient.upCards.pop_back();
        newHand.upCards=recipient;

        recipient.upCards.push_back(
                Card::to_char(shoe.draw())
                );

        newHand.upCards.push_back(
                Card::to_char(shoe.draw())
                );

        players.push_back(newHand);
}

void Table::doubleDown(Hand recipient)
{
        if(recipient.doubled)
                return;
        if(recipient.insured)
                return;
        if(recipient.stand)
                return;

        if(9 <= recipient.get_hand_total() && recipient.get_hand_total() <= 11)
                recipient.bet *= 2;

        recipient.doubled = true;
}

void Table::insure(Hand recipient)
{
        if(recipient.stand)
                return;
        if(recipient.doubled)
                return;
        if(recipient.insured != 0)
                return;

        if(dealer.upCards[0] != 'A')
                return;

        recipient.insured = recipient.bet/2;
}


void Table::blackjack(Hand recipient)
{
        if(recipient.get_hand_total() != 21)
                return;

        if(recipient.upCards.size() != 2)
                return;

        recipient.blackjack = true;
        recipient.stand = true;
}

Table::Table(int numDecks)
{
        Deck shoe(false, numDecks);
        shoe.shuffle();
}
