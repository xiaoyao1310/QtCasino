#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"
#include "mainwindow.h"
#include <QObject>
#include <QTextEdit>

#include <vector>
#include <string>
#include <time.h>

class Game : public QObject
{
    Q_OBJECT
public:
    Game(const std::vector<std::string>& names, MainWindow* pMw);

    ~Game();
public slots:
    void Play();

private:
    Deck m_deck;
    House m_house;
    std::vector<Player> m_players;

    MainWindow* m_window;
};

#endif // GAME_H
