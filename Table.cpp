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

void Table::game_deal()
{
        dealer.upCards.push_back(
                Card::to_char(
                        shoe.draw()
                        )
                );

        dealer.downCards.push_back(
                Card::to_char(
                        shoe.draw()
                        )
                );

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

        if(8 <= recipient.get_hand_total() <= 11)
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
