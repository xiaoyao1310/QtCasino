#ifndef DECK_H
#define DECK_H

#include <QTextEdit>
#include <random>
#include "genericplayer.h"


class Deck : public Hand
{
public:
    Deck();
    
    virtual ~Deck();
    
    //create a standard deck of 52 cards
    void Populate();
    
    void Shuffle();
    
    //deal one card to a hand
    void Deal(Hand& aHand);
    
    //give additional card
    void AdditionalCards(GenericPlayer& aGenericPlayer, MainWindow* &pMw);
};

#endif // DECK_H
