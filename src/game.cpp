#include "game.h"

Game::Game()
{
    m_readyToSpawnEnemyCnt = 25 + rand() % 10;
    m_readyToFireCnt = 5;
}

Game::~Game()
{

}

void Game::paint(QPainter &painter)
{
    m_level.paint(painter);
    m_ship.paint(painter);

    for (int i = 0; i < m_blasterBolts.size(); i++)
        m_blasterBolts[i]->paint(painter);

    for (int i = 0; i < m_enemies.size(); i++)
        m_enemies[i]->paint(painter);
}

void Game::update()
{
    m_level.update(m_ship.getBody());

    //Controls and shooting
    m_shipBlasterBolt = m_ship.update(m_readyToFireCnt);
    if (m_shipBlasterBolt != nullptr)
    {
        m_blasterBolts.push_back(m_shipBlasterBolt);
        m_readyToFireCnt = 5;
    }


    //Update and move all blasterbolts
    std::vector<Blasterbolt*>::iterator boltIt = m_blasterBolts.begin();
    while (boltIt != m_blasterBolts.end())
    {
        if ((*boltIt)->isAlive())
        {
            (*boltIt)->update(m_level.getGameSpeed());

            if (m_ship.didCollide((*boltIt)->getBody()))
            {
                (*boltIt)->destroy();
                qDebug() << "Ship hit by bolt!";
            }

            boltIt++;
        }
        else
        {
            delete *boltIt;
            boltIt = m_blasterBolts.erase(boltIt);
        }
    }

    //Update and move all enemies
    std::vector<EnemyOne*>::iterator enemyIt = m_enemies.begin();
    while (enemyIt != m_enemies.end())
    {
        if ((*enemyIt)->isAlive())
        {
            //For every enemy object, iterate through all blasterbolts and check if
            //anyone of them didCollide() with the currently checked enemy
            for (int i = 0; i < m_blasterBolts.size(); i++)
            {
                if ((*enemyIt)->didCollide(m_blasterBolts[i]->getBody()))
                {
                    (*enemyIt)->destroy();
                    m_blasterBolts[i]->destroy();
                }
            }

            if ((*enemyIt)->didCollide(m_ship.getBody()))
            {
                (*enemyIt)->destroy();
                qDebug() << "Ship hit!";
            }

            //Update enemies, and if they shoot, place blaserbolt in corresponging vector
            m_enemyBlasterBolt = (*enemyIt)->update(m_ship.getBody(), m_level.getGameSpeed());
            if (m_enemyBlasterBolt != nullptr)
                m_blasterBolts.push_back(m_enemyBlasterBolt);
            enemyIt++;
        }

        else
        {
            delete *enemyIt;
            enemyIt = m_enemies.erase(enemyIt);
        }
    }

    if (m_readyToSpawnEnemyCnt == 0)
    {
        EnemyOne *enemy = new EnemyOne(rand() % 770);
        m_enemies.push_back(enemy);
        m_readyToSpawnEnemyCnt = 25 + rand() % 10;
    }
}

void Game::flowTimerOverflow()
{
    if (m_readyToFireCnt > 0)
        m_readyToFireCnt--;

    if (m_readyToSpawnEnemyCnt > 0)
        m_readyToSpawnEnemyCnt--;
}
