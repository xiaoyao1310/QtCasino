#include "house.h"

House::House(const std::string& name): GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting()
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

void House::ShowHand(MainWindow* pMw) const
{
    pMw->m_tedt->clear();
    pMw->m_tedt->insertHtml(QString::fromStdString(m_name));

    std::vector<Card*>::const_iterator pCard;
    if (!m_cards.empty())
    {
        for (pCard = m_cards.begin(); pCard != m_cards.end(); ++pCard)
        {
            QString card = (*pCard)->QstringType();
            ShowCard(card, pMw->m_tedt);
        }
    }
}
