#include "player.h"
#include <QMessageBox>

Player::Player(const std::string& name): GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting()
{
    if (HitFlag == 1) // Hit
        return true;
    else if (HitFlag == -1) // No hit
        return false;

    return false;
}

void Player::Win() const
{
    std::cout << m_name << " wins.\n";
}

void Player::Lose() const
{
    std::cout << m_name << " loses.\n";
}

void Player::Push() const
{
    std::cout << m_name << " pushes.\n";
}

void Player::ShowHand(MainWindow *pMw) const
{
    pMw->m_tedt2->clear();
    pMw->m_tedt2->insertHtml(QString::fromStdString(m_name));

    std::vector<Card*>::const_iterator pCard;
    if (!m_cards.empty())
    {
        for (pCard = m_cards.begin(); pCard != m_cards.end(); ++pCard)
        {
            QString card = (*pCard)->QstringType();
            ShowCard(card, pMw->m_tedt2);            
        }
        pMw->m_tedt2->insertHtml(QString::number(GetTotal()));
    }
}

void Player::setHitFlagPos()
{
    HitFlag = 1;
}

void Player::setHitFlagNeg()
{
    HitFlag = -1;
}

void Player::setHitFlagZero()
{
    HitFlag = 0;
}
