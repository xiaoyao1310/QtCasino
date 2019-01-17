#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"
#include "mainwindow.h"
#include <QTextEdit>


#include <vector>
#include <string>
#include <time.h>

class Game
{
public:
    Game(const std::vector<std::string>& names, MainWindow* pMw);

    ~Game();

    void Play();

private:
    Deck m_deck;
    House m_house;
    std::vector<Player> m_players;

    MainWindow* m_window;
};

#endif // GAME_H
