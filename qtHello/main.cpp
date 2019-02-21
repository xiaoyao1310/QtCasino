#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>

#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("BlackJack");
    w.resize(800, 600);
    w.show();

    bool ok = 0;
    int numPlayers = 1;
    while (!ok)
    {
        numPlayers = QInputDialog::getInt(&w, "Input number of Players", "1 - 7", 1, 1, 7, 1, &ok);
    }

    std::vector<std::string> names;
    for (int i = 0; i < numPlayers; i++)
    {
        names.push_back("Player" + std::to_string(i+1));
    }
    Game aGame(names, &w);
    aGame.Play();

    QObject::connect(&w, SIGNAL(buttonSignal()), &aGame, SLOT(Play()));
    QObject::connect(&w, SIGNAL(HitSignal()), &aGame, SLOT(Hit()));
    QObject::connect(&w, SIGNAL(NoHitSignal()), &aGame, SLOT(NoHit()));
    QObject::connect(&w, SIGNAL(NextPlayerSignal()), &aGame, SLOT(NextPlayer()));
    QObject::connect(&w, SIGNAL(menuSignal1()), &aGame, SLOT(Play()));

    return a.exec();
}
