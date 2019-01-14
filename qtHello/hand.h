#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>
#include <iterator>


class Hand
{
public:
    Hand();

    virtual ~Hand();

    //add a card to hand
    void Add(Card* pCard);

    //clear all cards in hand
    void Clear();

    //get total value by intelligently treating ace as 1 or 11
    int GetTotal() const;

protected:
    std::vector<Card*> m_cards;
};

#endif // HAND_H
