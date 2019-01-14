#include "player.h"

Player::Player(const std::string& name): GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const
{
    std::cout << m_name << ", do you want a hit? (Y/N):";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
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
