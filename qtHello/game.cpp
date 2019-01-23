#include "game.h"

Game::Game(const std::vector<std::string>& names, MainWindow* pMw)
{
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
        m_players.push_back(new Player(*pName));

    //seed a random number generator
    srand(static_cast<unsigned>(time(0)));
    m_deck.Populate();
    m_deck.Shuffle();
    m_window = pMw;

    //QObject::connect(this, SIGNAL(HitCurrent()), m_players[0], SLOT(setHitFlagPos()));
    //QObject::connect(this, SIGNAL(NoHitCurrent()), m_players[0], SLOT(setHitFlagNeg()));
}

Game::~Game()
{
    for (auto i = m_players.begin(); i != m_players.end(); i++)
    {
        delete *i;
    }
    delete m_window;
}

void Game::RemoveCard()
{
    std::vector<Player*>::iterator pPlayer;
    // remove everyone's cards
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        (*pPlayer)->Clear();
    m_house.Clear();
}

void Game::Play()
{
    RemoveCard();
    // deal initial 2 cards
    std::vector<Player*>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        // deal two cards in the beginning
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
            m_deck.Deal(*(*pPlayer));

        m_deck.Deal(m_house);
    }

    // hide house's first card
    m_house.FlipFirstCard();
    m_house.ShowHand(m_window);

    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        (*pPlayer)->ShowHand(m_window);
    }
    m_window->showButtons();
}

void Game::ShowResult()
{
    std::vector<Player*>::iterator pPlayer;

    // reveal house's first card
    m_house.FlipFirstCard();

    std::cout << std::endl << m_house;
    m_house.ShowHand(m_window);

    // deal additional cards to house
    while (m_house.GetTotal() <= 16)
    {
        m_deck.AdditionalCards(m_house, m_window);
    }

    if (m_house.IsBusted())
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!((*pPlayer)->IsBusted()))
            {
                (*pPlayer)->Win();
                QString s = QString::fromStdString((*pPlayer)->getName() + " Won!");
                m_window->showLineEdit(QString(s));
            }
        }
    }
    else
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!((*pPlayer)->IsBusted()))
            {
                if ((*pPlayer)->GetTotal() > m_house.GetTotal())
                {
                    (*pPlayer)->Win();
                    QString s = QString::fromStdString((*pPlayer)->getName() + " Won!");
                    m_window->showLineEdit(QString(s));
                }
                else if ((*pPlayer)->GetTotal() < m_house.GetTotal())
                {
                    (*pPlayer)->Lose();
                    QString s = QString::fromStdString((*pPlayer)->getName() + " Lost!");
                    m_window->showLineEdit(QString(s));
                }
                else
                {
                    (*pPlayer)->Push();
                    QString s = QString::fromStdString((*pPlayer)->getName() + " Pushed!");
                    m_window->showLineEdit(QString(s));
                }
            }
        }
    }
    m_window->hideButtons();
    //RemoveCard();
}

void Game::Hit()
{
    std::vector<Player*>::iterator pPlayer;
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        (*pPlayer)->setHitFlagPos();
        (*pPlayer)->ShowHand(m_window);
        m_deck.AdditionalCards(*(*pPlayer), m_window);
        (*pPlayer)->setHitFlagZero();
        (*pPlayer)->ShowHand(m_window);

        if ((*pPlayer)->IsBusted())
        {
            m_window->hideButtons();
        }
    }
    //emit HitCurrent();
}

void Game::NoHit()
{
    std::vector<Player*>::iterator pPlayer;
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        (*pPlayer)->setHitFlagNeg();
        (*pPlayer)->ShowHand(m_window);
        m_deck.AdditionalCards(*(*pPlayer), m_window);
        (*pPlayer)->setHitFlagZero();
    }
    //emit NoHitCurrent();
    ShowResult();
}
