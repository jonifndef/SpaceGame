#include "spacegame.h"
#include "ui_spacegame.h"

SpaceGame::SpaceGame(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::SpaceGame)
{
    ui->setupUi(this);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    //m_readyToSpawnEnemyCnt = 25 + rand() % 10;
    //m_readyToFireCnt = 5;
    //m_level = new Level(0, 0);

    //m_game = new Game();

    //m_timer for updating the game and all objects in it
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    //m_timer->start(16);

    //m_timer that is used to initiate a cooldown on the player shoot() function


    m_flowTimer = new QTimer(this);
    connect(m_flowTimer, SIGNAL(timeout()), this, SLOT(testSlot()));



    //m_flowTimer->start(80);

    srand(time(NULL));


    //m_gameState = MAIN_MENU;
    //m_menu = new MainMenu(this);


    startGame();
}

SpaceGame::~SpaceGame()
{
    delete ui;
}

void SpaceGame::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
    painter.setPen(Qt::white);

    switch (m_gameState)
    {
        case MAIN_MENU:
            m_menu.paint(painter);
            break;
        case PLAYING:
            m_game.paint(painter);
            break;
        case PAUSED:
            /*m_level->paint(painter);
            m_ship.paint(painter);

            for (int i = 0; i < m_blasterBolts.size(); i++)
                m_blasterBolts[i]->paint(painter);

            for (int i = 0; i < m_enemies.size(); i++)
                m_enemies[i]->paint(painter);
            break;*/
        default:
            break;
    }
}

void SpaceGame::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        if (m_gameState == PLAYING)
        {
            pauseGame();
        }
        else if (m_gameState == PAUSED)
        {
            startGame();
        }
    }
}

void SpaceGame::update()
{
    m_game.update();

    repaint();
}

void SpaceGame::testSlot()
{
    m_game.flowTimerOverflow();
}

void SpaceGame::mainMenu()
{

}

void SpaceGame::startGame()
{
    m_timer->start(16);
    m_flowTimer->start(80);
    m_gameState = PLAYING;
}

void SpaceGame::pauseGame()
{
    m_timer->stop();
    m_flowTimer->stop();
    m_gameState = PAUSED;
}
