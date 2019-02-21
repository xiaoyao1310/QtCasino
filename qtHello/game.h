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

    void RemoveCard();
    void ShowResult();
    Player* GetCurrent();

public slots:
    void Play();    
    void Hit();
    void NoHit();
    bool NextPlayer(); // false if last player

signals:
    void HitCurrent(); // to current player
    void NoHitCurrent();

private:
    Deck m_deck;
    House m_house;
    std::vector<Player*> m_players;
    unsigned m_current; //active player, =0 if no player

    MainWindow* m_window;
};

#endif // GAME_H
