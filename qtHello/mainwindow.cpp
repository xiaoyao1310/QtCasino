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
    m_label->setText("label one");
    QStatusBar* sb = statusBar();
    sb->addWidget(m_label);

    m_tedt = new QTextEdit(this);
    m_tedt->move(80, 200);
    m_tedt->resize(500,200); //pukecard 105 * 150
    m_tedt->insertHtml("QTextEdit\n");
    QString imgDir = QCoreApplication::applicationDirPath() + "/pukeImage";
    imgDir += "/h1.jpg";
    imgDir.prepend("<img src=\"");
    imgDir.append("\"/>");      // <img src="dir"/>
    m_tedt->insertHtml(imgDir);
    m_tedt->setReadOnly(true);

    m_edit = new QLineEdit(this);
    if(m_edit != NULL)
    {
        m_edit->move(20, 80);
        m_edit->resize(150, 50);
        m_edit->setReadOnly(true);
    }

    m_buttons[0] = new QPushButton(this);
    if(m_buttons[0] != NULL)
    {
        m_buttons[0]->setText("Button 1");
        m_buttons[0]->move(20, 25);
        m_buttons[0]->resize(150, 50);
    }
    m_buttons[1] = new QPushButton(this);
    if(m_buttons[1] != NULL)
    {
        m_buttons[1]->setText("Button 2");
        m_buttons[1]->move(200, 25);
        m_buttons[1]->resize(150, 50);
    }

    connect(m_buttons[0], SIGNAL(clicked()), this, SLOT(onMyButtonClicked()));
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

    makeAction(action, "Single Player(S)", Qt::CTRL + Qt::Key_S);
    menu->addAction(action);
    makeAction(action, "Multi Player(M)", Qt::CTRL + Qt::Key_M);
    menu->addAction(action);
    mb->addMenu(menu);
}

void MainWindow::onMyButtonClicked()
{
    qDebug() << "onMyButtonClicked()";
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_label;
    delete m_edit;
    delete m_buttons[0];
    delete m_buttons[1];
    delete m_tedt;
}

