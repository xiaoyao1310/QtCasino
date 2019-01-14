#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
               NINE, TEN, JACK, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    int GetValue() const;

    void Flip();

private:
    rank m_rank;
    suit m_suit;
    bool m_isFaceUp;
};

#endif // CARD_H
