#include "player.h"
#include <QMessageBox>

Player::Player(const std::string& name): QObject(nullptr), GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting()
{
    // console edition
    /*
    std::cout << m_name << ", do you want a hit? (Y/N):";   
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
    */

    // messsagebox edition
    /*
    QMessageBox hitBox(pMw);
    hitBox.setWindowTitle("Choice");
    hitBox.setText("Wanna hit?");
    hitBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if (hitBox.exec() == QMessageBox::Yes)
        return true;
    return false;
    */

    // qbutton editon
    //setHitFlagZero();
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
