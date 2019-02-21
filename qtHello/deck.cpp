#include "deck.h"
#include <algorithm>

Deck::Deck()
{
    m_cards.reserve(52);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
            Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
    }
}

void Deck::Shuffle()
{
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::Deal(Hand &aHand)
{
    if (!m_cards.empty())
    {
        aHand.Add(m_cards.back());
        m_cards.pop_back();
    }
    else
    {
        std::cout << "Out of cards. New cards generated.";
        Populate();
        Shuffle();
    }
}

void Deck::AdditionalCards(GenericPlayer &aGenericPlayer, MainWindow*& pMw)
{
    std::cout << std::endl;
    
    if (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);

        std::cout << aGenericPlayer << std::endl;
        aGenericPlayer.ShowHand(pMw);

        if (aGenericPlayer.IsBusted())
            aGenericPlayer.Bust();
    }
}
