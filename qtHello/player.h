#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"
#include <QObject>

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");

    virtual ~Player();

    //if want another hit
    virtual bool IsHitting();

    //announce wins
    void Win() const;

    //annouce loses
    void Lose() const;

    //annouce pushes - tie
    void Push() const;

    //show cards on QTextEdit #2
    void ShowHand(MainWindow* pMw) const;

    void setHitFlagPos();
    void setHitFlagNeg();
    void setHitFlagZero();

private:
    int HitFlag = 0; // 1 for hit, -1 for no hit
};

#endif // PLAYER_H
