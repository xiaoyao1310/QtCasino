#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <QDebug>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // called by construct func
    void makeAction(QAction*& action, QString text, int key);
    void initMenu(QMenuBar* mb);


    QTextEdit* m_tedt; // func ShowHand in Game and Deck need access
    QTextEdit* m_tedt2;

protected slots:
    void onMyButtonClicked();
    void onMyButton2Clicked();

signals:
    void buttonSignal();

private:
    Ui::MainWindow *ui;


    QLabel* m_label;
    QLineEdit* m_edit;
    QPushButton* m_buttons[2];
};

#endif // MAINWINDOW_H
