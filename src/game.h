#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <vector>
#include <QObject>

#include "level.h"
#include "blasterbolt.h"
#include "enemyone.h"
#include "ship.h"
#include "gameobject.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    ~Game();
    void update();
    void paint(QPainter &painter);
    void flowTimerOverflow();

//public slots:
//    void flowTimerOverflow();

private:
    std::vector<Blasterbolt*> m_blasterBolts;
    std::vector<EnemyOne*> m_enemies;
    Level m_level;
    Ship m_ship;
    Blasterbolt *m_enemyBlasterBolt;
    Blasterbolt *m_shipBlasterBolt;

    int m_readyToSpawnEnemyCnt;
    int m_readyToFireCnt;
};
#endif // GAME_H
