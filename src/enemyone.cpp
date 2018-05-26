#include "enemyone.h"

EnemyOne::EnemyOne(int height) : GameObject(WINDOW_WIDTH + 20,
                                            height,
                                            ENEMY_ONE_WIDTH,
                                            ENEMY_ONE_HEIGHT)
{
    m_isAlive = true;
    m_isLinedUp = false;
    m_followPlayerCnt = 3;
    m_blasterCooldownCnt = 60;
}

EnemyOne::~EnemyOne()
{

}

Blasterbolt *EnemyOne::update(const QRect &ship, const int &gameSpeed)
{  
    m_isLinedUp = false;
    //Delays so the enemy won't line up or shoot too fast
    if (m_followPlayerCnt > 0)
        m_followPlayerCnt--;
    if (m_blasterCooldownCnt > 0)
        m_blasterCooldownCnt--;

    if (m_isAlive)
    {
        moveLeft(gameSpeed);
        //Try to line up with player to take a shot
        if (m_followPlayerCnt == 0)
        {
            if (m_body.y() + ENEMY_ONE_HEIGHT / 2 > ship.y() + (SHIP_HEIGHT / 2) + 5 && (m_body.x() > ship.x() + SHIP_WIDTH))
            {
                m_isLinedUp = false;
                moveUp();
            }
            else if (m_body.y() + ENEMY_ONE_HEIGHT / 2 < ship.y() + (SHIP_HEIGHT / 2) - 5 && (m_body.x() > ship.x() + SHIP_WIDTH))
            {
                m_isLinedUp = false;
                moveDown();
            }
            else
            {
                m_isLinedUp = true;
            }
            m_followPlayerCnt = 3;
        }

    }

    //If cooldown is finished and enemy is lined up with player, fire blaster bolt
    if (m_isLinedUp && m_blasterCooldownCnt == 0 && m_body.x() > ship.x() + SHIP_WIDTH)
    {
        m_blasterCooldownCnt = 60;
        return new Blasterbolt(m_body.x() - BLASTER_WIDTH,
                               m_body.y() + ENEMY_ONE_HEIGHT / 2 - BLASTER_HEIGHT / 2,
                               false,
                               gameSpeed + ENEMY_BLASTER_SPEED);
    }
    return nullptr;
}

void EnemyOne::moveRight(const int &gameSpeed)
{
    if (m_body.x() < 720)
        m_body.moveTo(m_body.x() + gameSpeed + ENEMY_ONE_SPEED, m_body.y());
}

void EnemyOne::moveLeft(const int &gameSpeed)
{
    if (m_body.x() + m_body.width() > -30)
        m_body.moveTo(m_body.x() - (gameSpeed + ENEMY_ONE_SPEED), m_body.y());
    else
        m_isAlive = false;
}

void EnemyOne::moveUp()
{
    if (m_body.y() > -30)
        m_body.moveTo(m_body.x(), m_body.y() - (1 + ENEMY_ONE_SPEED));
}

void EnemyOne::moveDown()
{
    if (m_body.y() < 800)
        m_body.moveTo(m_body.x(), m_body.y() + (1 + ENEMY_ONE_SPEED));
}

