#include "house.h"

House::House(const std::string& name): GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_cards.empty()))
        m_cards[0]->Flip();
    else
        std::cout << "No card to flip!\n";
}