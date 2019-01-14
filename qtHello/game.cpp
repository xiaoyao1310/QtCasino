#include "game.h"

Game::Game(const std::vector<std::string>& names)
{
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
        m_players.push_back(Player(*pName));

    //seed a random number generator
    srand(static_cast<unsigned>(time(0)));
    m_deck.Populate();
    m_deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    // deal initial 2 cards
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
            m_deck.Deal(*pPlayer);

        m_deck.Deal(m_house);
    }

    // hide house's first card
    m_house.FlipFirstCard();

    // display players' hand
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        m_deck.AdditionalCards(*pPlayer);

    // reveal house's first card
    m_house.FlipFirstCard();
    std::cout << std::endl << m_house;

    // deal additional cards to house
    m_deck.AdditionalCards(m_house);

    if (m_house.IsBusted())
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
                pPlayer->Win();
        }
    }
    else
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                if (pPlayer->GetTotal() > m_house.GetTotal())
                    pPlayer->Win();
                else if (pPlayer->GetTotal() < m_house.GetTotal())
                    pPlayer->Lose();
                else
                    pPlayer->Push();
            }
        }
    }

    // remove everyone's cards
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        pPlayer->Clear();
    m_house.Clear();
}

