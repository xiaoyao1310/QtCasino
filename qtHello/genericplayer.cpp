#include "genericplayer.h"
#include <QString>
#include <QCoreApplication>


GenericPlayer::GenericPlayer(const std::string& name): m_name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
    std::cout << m_name << " busts.\n";
}

std::string GenericPlayer::getName() const
{
    return m_name;
}

void GenericPlayer::ShowCard(QString &card, QTextEdit* &pTedt) const
{
    pTedt->insertHtml("-\n");
    QString imgDir = QCoreApplication::applicationDirPath() + "/pukeImage/";
    imgDir += card;
    imgDir.prepend("<img src=\"");
    imgDir.append("\"/>");      // <img src="imgDir"/>
    //qDebug() << imgDir;
    pTedt->insertHtml(imgDir);
    pTedt->setReadOnly(true);
}

// console edition output, for test use
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_name << ":\t";

    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_cards.empty())
    {
        for (pCard = aGenericPlayer.m_cards.begin(); pCard != aGenericPlayer.m_cards.end(); ++pCard)
            os << *(*pCard) << "\t";

        if (aGenericPlayer.GetTotal() != 0)
            std::cout << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else
        os << "<empty>";

    return os;
}
