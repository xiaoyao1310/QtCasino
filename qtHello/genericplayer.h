#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include <iostream>
#include <string>
#include "hand.h"
#include "mainwindow.h"

#include <QTextEdit>

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");

    virtual ~GenericPlayer();

    // if keep hitting
    virtual bool IsHitting(MainWindow* pMw) const = 0;

    // if busted - total value great than 21
    bool IsBusted() const;

    //announce busts
    void Bust() const;

    //show hand
    virtual void ShowHand(MainWindow* pMw) const = 0;

    //show card image, called by ShowHand
    void ShowCard(QString& card, QTextEdit *&pTedt) const;

protected:
    std::string m_name;
};

#endif // GENERICPLAYER_H
