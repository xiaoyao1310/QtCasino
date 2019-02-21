#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QTextEdit>
#include <QDebug>
#include <QBoxLayout>
#include <QWidget>


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
    void showButtons(); // show 'Hit' 'No hit'
    void hideButtons();
    void showNextB(); // show button 'Next'
    void hideNextB();
    void showLineEdit(QString s);

    QTextEdit* m_tedt; // func ShowHand in House and Player need to access
    QTextEdit* m_tedt2;

protected slots:
    void onMyButtonClicked();
    void onMyButton2Clicked();
    void onMyButton3Clicked();
    void onMyButton4Clicked(); // 'Next'
    void menuAction1();
    void menuAction2();

signals:
    void buttonSignal();
    void HitSignal();
    void NoHitSignal();
    void NextPlayerSignal();
    void menuSignal1();
    void menuSignal2();

private:
    Ui::MainWindow *ui;

    QLabel* m_label;
    QLineEdit* m_edit; // show game result
    QPushButton* m_buttons[4]; // 'New' 'Hit' 'No Hit' 'Next'
    QHBoxLayout* m_hbl;
    QVBoxLayout* m_vbl;
    QVBoxLayout* m_topl; // top layout
    QWidget* m_widget; // central widget to set layout
};

#endif // MAINWINDOW_H
