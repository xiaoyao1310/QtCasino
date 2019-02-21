#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* mb = menuBar();
    initMenu(mb);

    m_label = new QLabel(this);
    m_label->setText("Black Jack(1.0)");
    QStatusBar* sb = statusBar();
    sb->addWidget(m_label);

    m_tedt = new QTextEdit(this);
    m_tedt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_tedt->setMinimumSize(700,200); //pukecard 105 * 150
    m_tedt->setReadOnly(true);

    m_tedt2 = new QTextEdit(this);
    m_tedt2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_tedt2->setMinimumSize(700,200);
    m_tedt2->setReadOnly(true);

    m_edit = new QLineEdit(this);
    if(m_edit != NULL)
    {
        m_edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_edit->setMinimumSize(600, 50);
        m_edit->setReadOnly(true);
    }

    m_buttons[0] = new QPushButton(this);
    if(m_buttons[0] != NULL)
    {
        m_buttons[0]->setText("New");
        m_buttons[0]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_buttons[0]->setMinimumSize(150, 50);
        m_buttons[0]->setMaximumSize(200, 60);
    }
    m_buttons[1] = new QPushButton(this);
    if(m_buttons[1] != NULL)
    {
        m_buttons[1]->setText("Hit");
        m_buttons[1]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_buttons[1]->setMinimumSize(150, 50);
    }
    m_buttons[2] = new QPushButton(this);
    if(m_buttons[2] != NULL)
    {
        m_buttons[2]->setText("No Hit");
        m_buttons[2]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_buttons[2]->setMinimumSize(150, 50);
    }
    m_buttons[3] = new QPushButton(this);
    if(m_buttons[3] != NULL)
    {
        m_buttons[3]->setText("Next");
        m_buttons[3]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        m_buttons[3]->setMinimumSize(150, 50);
        m_buttons[3]->setMaximumSize(200, 60);
    }

    m_hbl = new QHBoxLayout();
    m_hbl->setSpacing(40);
    m_hbl->addWidget(m_buttons[0]);
    m_hbl->addWidget(m_buttons[1]);
    m_hbl->addWidget(m_buttons[2]);
    m_hbl->addWidget(m_buttons[3]);

    m_vbl = new QVBoxLayout();
    m_vbl->setSpacing(40);
    m_vbl->addWidget(m_edit);
    m_vbl->addWidget(m_tedt);
    m_vbl->addWidget(m_tedt2);

    m_topl = new QVBoxLayout();
    m_topl->setSpacing(60);
    m_topl->addLayout(m_hbl);
    m_topl->addLayout(m_vbl);

    m_widget = new QWidget();
    m_widget->setLayout(m_topl);
    setCentralWidget(m_widget);

    hideButtons();
    hideNextB();

    connect(m_buttons[0], SIGNAL(clicked()), this, SLOT(onMyButtonClicked()));
    connect(m_buttons[1], SIGNAL(clicked()), this, SLOT(onMyButton2Clicked()));
    connect(m_buttons[2], SIGNAL(clicked()), this, SLOT(onMyButton3Clicked()));
    connect(m_buttons[3], SIGNAL(clicked()), this, SLOT(onMyButton4Clicked()));
}

void MainWindow::makeAction(QAction *&action, QString text, int key)
{
    action = new QAction(text, NULL);
    action->setShortcut(QKeySequence(key));
}

void MainWindow::initMenu(QMenuBar *mb)
{
    QMenu* menu = new QMenu("Game(&G)");
    QAction* action = NULL;
    QAction* action2 = NULL;

    makeAction(action, "New Game(N)", Qt::CTRL + Qt::Key_N);
    menu->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(menuAction1()));
    makeAction(action2, "Quit(Q)", Qt::CTRL + Qt::Key_Q);
    menu->addAction(action2);
    connect(action2, SIGNAL(triggered()), this, SLOT(menuAction2()));
    mb->addMenu(menu);
}

void MainWindow::onMyButtonClicked()
{
    qDebug() << "onMyButtonClicked()";
    emit buttonSignal();
}

void MainWindow::onMyButton2Clicked()
{
    qDebug() << "Button2";\
    emit HitSignal();
}

void MainWindow::onMyButton3Clicked()
{
    qDebug() << "Button3";
    emit NoHitSignal();
}

void MainWindow::onMyButton4Clicked()
{
    qDebug() << "Button4";
    emit NextPlayerSignal();
}

void MainWindow::menuAction1()
{
    qDebug() << "menuAction1";
    emit menuSignal1();
}

void MainWindow::menuAction2()
{
    qDebug() << "menuAction2";
    //emit menuSignal2();
    close();
}

void MainWindow::showButtons()
{
    m_buttons[1]->setVisible(true);
    m_buttons[2]->setVisible(true);
}

void MainWindow::hideButtons()
{
    m_buttons[1]->setVisible(false);
    m_buttons[2]->setVisible(false);
}

void MainWindow::showNextB()
{
    m_buttons[3]->setVisible(true);
}

void MainWindow::hideNextB()
{
    m_buttons[3]->setVisible(false);
}

void MainWindow::showLineEdit(QString s)
{
    m_edit->clear();
    m_edit->insert(s);
}

MainWindow::~MainWindow()
{
    delete m_widget;
    delete m_topl;
    delete m_vbl;
    delete m_hbl;

    delete m_buttons[3];
    delete m_buttons[2];
    delete m_buttons[1];
    delete m_buttons[0];
    delete m_edit;

    delete m_tedt2;
    delete m_tedt;
    delete m_label;

    delete ui;
}

