#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include <string>
#include "hand.h"

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");

    virtual ~GenericPlayer();

    // if keep hitting
    virtual bool IsHitting() const = 0;

    // if busted - total value great than 21
    bool IsBusted() const;

    //announce busts
    void Bust() const;

protected:
    std::string m_name;
};

#endif // GENERICPLAYER_H
