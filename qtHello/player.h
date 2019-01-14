#ifndef PLAYER_H
#define PLAYER_H

#include "genericplayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");

    virtual ~Player();

    //if want another hit
    virtual bool IsHitting() const;

    //announce wins
    void Win() const;

    //annouce loses
    void Lose() const;

    //annouce pushes - tie
    void Push() const;
};

#endif // PLAYER_H
