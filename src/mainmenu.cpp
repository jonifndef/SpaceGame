#include "mainmenu.h"

MainMenu::MainMenu(QMainWindow *context)
{
    if (!m_background.load("res/spacegame_background.png"))
        qDebug() << "Pixmap error in mainMenu!";

    m_gameTitle = new QLabel("SPACE GAME", context);
    QFont font("Helvetica", 22, 3, false);
    font.setBold(true);
    m_gameTitle->setFont(font);
    m_gameTitle->setStyleSheet("QLabel { background-color : red; color : blue; }");

    //m_gameTitle->setAttribute(Qt::WA_TranslucentBackground);
    //m_gameTitle->setWindowFlags(Qt::FramelessWindowHint);
    m_gameTitle->setGeometry(QRect(280, 90, 190, 70));

    m_newGameButton = new QPushButton("NEW GAME", context);
    m_newGameButton->setGeometry(QRect(280, 180, 190, 70));

    connect(m_newGameButton, SIGNAL(clicked(bool)), context, SLOT(newGame()));
}

MainMenu::~MainMenu()
{

}

void MainMenu::paint(QPainter &painter)
{
    painter.drawPixmap(0, 0, m_background);
}

void MainMenu::newGame()
{
    qDebug() << "New game pressed!";
}
