#include "card.h"

Card::Card(rank r, suit s, bool ifu): m_rank(r), m_suit(s), m_isFaceUp(ifu)
{

}

int Card::GetValue() const
{
    // value is 0 if face down
    int value = 0;
    if (m_isFaceUp)
    {
        value = m_rank;
        if (value > 10)
            value = 10;
    }
    return value;
}

void Card::Flip()
{
    m_isFaceUp = !(m_isFaceUp);
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                            "J", "Q", "K"};
    const std::string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_isFaceUp)
    {
        os << RANKS[aCard.m_rank] << SUITS[aCard.m_suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}
