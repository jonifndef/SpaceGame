#ifndef SPACEGAME_H
#define SPACEGAME_H

#include <QMainWindow>
#include <vector>
#include <QTimer.h>
#include <Windows.h>
#include <qdebug.h>
#include <random>
#include <time.h>
#include <QKeyEvent>
#include <QPushButton>

//.h files
//#include "level.h"
//#include "gameobject.h"
//#include "ship.h"
#include "ui_spacegame.h"
//#include "blasterbolt.h"
#include "defines.h"
//#include "enemyone.h"
#include "mainmenu.h"
#include "game.h"

namespace Ui {
class SpaceGame;
}

class SpaceGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpaceGame(QMainWindow *parent = 0);
    ~SpaceGame();
    void paintEvent(QPaintEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void update();
    void testSlot();

private:
    Ui::SpaceGame *ui;
    //std::vector<Blasterbolt*> m_blasterBolts;
    //std::vector<EnemyOne*> m_enemies;
    QTimer *m_timer;
    QTimer *m_flowTimer;
    //Level *m_level;
    //Ship m_ship;
    //Blasterbolt *m_enemyBlasterBolt;
    //Blasterbolt *m_shipBlasterBolt;
    MainMenu m_menu;
    Game m_game;

    //int m_readyToSpawnEnemyCnt;
    //int m_readyToFireCnt;
    void mainMenu();
    void startGame();
    void pauseGame();

    enum GameState { MAIN_MENU, PLAYING, PAUSED };
    GameState m_gameState;
};

#endif // SPACEGAME_H
