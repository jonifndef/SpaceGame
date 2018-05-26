#include "blasterbolt.h"

Blasterbolt::Blasterbolt(int xPos, int yPos, bool isFriendly, int gameSpeed) : GameObject(xPos, yPos, BLASTER_WIDTH, BLASTER_HEIGHT)
{
    m_isAlive = true;
    m_isFriendly = isFriendly;
    m_gameSpeed = gameSpeed;
}

Blasterbolt::~Blasterbolt()
{

}

void Blasterbolt::moveRight()
{
    if (m_body.x() < WINDOW_WIDTH + 10)
        m_body.moveTo(m_body.x() + BLASTER_SPEED, m_body.y());
    else
        m_isAlive = false;
}

void Blasterbolt::moveLeft()
{
    if (m_body.x() + m_body.width() > -5)
        m_body.moveTo(m_body.x() - (m_gameSpeed + ENEMY_BLASTER_SPEED), m_body.y());
    else
        m_isAlive = false;
}

void Blasterbolt::moveUp()
{

}

void Blasterbolt::moveDown()
{

}

void Blasterbolt::update(const int &gameSpeed)
{
    m_gameSpeed = gameSpeed;
    if (m_isAlive)
    {
        if (m_isFriendly)
            this->moveRight();
        else
            this->moveLeft();
    }
}

