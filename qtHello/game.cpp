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
    m_current = 1;
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

Player* Game::GetCurrent()
{
    if (m_current <= m_players.size())
    {
        return m_players[m_current - 1];
    }
    else
        return NULL;
}

void Game::Play()
{
    RemoveCard();

    // clear last game result
    QString blank("");
    m_window->showLineEdit(blank);

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

    m_players[0]->ShowHand(m_window);

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

    QString qsWin, qsLose, qsPush;
    if (m_house.IsBusted())
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!((*pPlayer)->IsBusted()))
            {
                (*pPlayer)->Win();
                qsWin += QString::fromStdString((*pPlayer)->getName() + "- ");
            }
        }
        m_window->showLineEdit(qsWin + "Won!");
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
                    qsWin += QString::fromStdString((*pPlayer)->getName() + "- ");
                }
                else if ((*pPlayer)->GetTotal() < m_house.GetTotal())
                {
                    (*pPlayer)->Lose();
                    qsLose += QString::fromStdString((*pPlayer)->getName() + "- ");
                }
                else
                {
                    (*pPlayer)->Push();
                    qsPush += QString::fromStdString((*pPlayer)->getName() + "- ");
                }
            }
        }

        QString qsResult;
        if (!qsWin.isEmpty())
            qsResult += (qsWin + "Won! ");
        if (!qsLose.isEmpty())
            qsResult += (qsLose + "Lost! ");
        if (!qsPush.isEmpty())
            qsResult += (qsPush + "Pushed! ");
        m_window->showLineEdit(qsResult);
    }
    m_window->hideButtons();
    //RemoveCard();
}

bool Game::NextPlayer()
{
    if (m_current < m_players.size())
    {
        m_current++;
        Player* pPlayer = GetCurrent();
        pPlayer->ShowHand(m_window);
        m_window->showButtons();
        m_window->hideNextB();
        return true;
    }
    else
    {
        ShowResult();
        return false; // already last player
    }
}

void Game::Hit()
{
    Player* pPlayer = GetCurrent();
    if (pPlayer)
    {
        pPlayer->setHitFlagPos();
        pPlayer->ShowHand(m_window);
        m_deck.AdditionalCards(*pPlayer, m_window);
        pPlayer->setHitFlagZero();
        pPlayer->ShowHand(m_window);

        if (pPlayer->IsBusted())
        {
            QString s = QString::fromStdString(pPlayer->getName() + " Busted!");
            m_window->showLineEdit(QString(s));
            m_window->hideButtons();
            m_window->showNextB();
        }
    }
    //emit HitCurrent();
}

void Game::NoHit()
{
    Player* pPlayer = GetCurrent();
    if (pPlayer)
    {
        pPlayer->setHitFlagNeg();
        pPlayer->ShowHand(m_window);
        m_deck.AdditionalCards(*pPlayer, m_window);
        pPlayer->setHitFlagZero();

        m_window->hideButtons();
        m_window->showNextB();
    }
    //emit NoHitCurrent();
}
