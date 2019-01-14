#ifndef HOUSE_H
#define HOUSE_H

#include "genericplayer.h"

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    virtual ~House();

    // if hitting - always hitting when no less than 16
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};

#endif // HOUSE_H
