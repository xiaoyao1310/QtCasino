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
    void showButtons();
    void hideButtons();
    void showLineEdit(QString s);

    QTextEdit* m_tedt; // func ShowHand in House and Player need to access
    QTextEdit* m_tedt2;

protected slots:
    void onMyButtonClicked();
    void onMyButton2Clicked();
    void onMyButton3Clicked();

signals:
    void buttonSignal();
    void HitSignal();
    void NoHitSignal();

private:
    Ui::MainWindow *ui;

    QLabel* m_label;
    QLineEdit* m_edit;
    QPushButton* m_buttons[3]; // 'New' 'Hit' 'No Hot'
};

#endif // MAINWINDOW_H
