#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Window1");
    w.resize(800, 600);
    w.show();

    std::vector<std::string> names;
    names.push_back("GM");
    Game aGame(names, &w);
    aGame.Play();

    /*
    QMessageBox quit(&w);
    quit.setText("quit?");
    quit.setStandardButtons(QMessageBox::Yes);
    if (quit.exec() == QMessageBox::Yes)
       qDebug() << "QUIT";
    */
    return a.exec();


    /*
    std::cout << "\t\t Welcome to BlackJack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "How many players? (1 - 7):";
        std::cin >> numPlayers;
    }

    std::vector<std::string> names;
    std::string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << std::endl;

    // game loop
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        std::cout << "\n Do you want to Play again? (y/n): ";
        std::cin >> again;
    }

    return 0;
    */
}
