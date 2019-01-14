#include "hand.h"

Hand::Hand()
{
    m_cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card *pCard)
{
    m_cards.push_back(pCard);
}

void Hand::Clear()
{
    std::vector<Card*>::iterator iter = m_cards.begin();
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    m_cards.clear();
}

int Hand::GetTotal() const
{
    if (m_cards.empty())
        return 0;
    // all face down
    else if (m_cards[0]->GetValue() == 0)
        return 0;

    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        total += (*iter)->GetValue();

    // if contains Ace
    bool containsAce = false;
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
            containsAce = true;
    }

    // if has Ace and total is low enough, treat Ace as 11
    if (containsAce && total <= 11)
        total += 10;

    return total;
}
