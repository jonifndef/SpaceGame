#ifndef ENEMY_ONE_H
#define ENEMY_ONE_H

#include "ship.h"
#include "defines.h"
#include "blasterbolt.h"
#include "level.h"
#include <chrono>
#include <iostream>

class EnemyOne : public GameObject
{
public:
    EnemyOne(int height);
    ~EnemyOne();
    Blasterbolt* update(const QRect &ship, const int &gameSpeed);

private:
    void moveRight(const int &gameSpeed);
    void moveLeft(const int &gameSpeed);
    void moveUp();
    void moveDown();

    int m_followPlayerCnt;
    int m_blasterCooldownCnt;
    bool m_isLinedUp;
};

#endif // ENEMY_ONE_H
