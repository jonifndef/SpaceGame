#include "Ship.h"

Ship::Ship() : GameObject(122, 350, SHIP_WIDTH, SHIP_HEIGHT)
{
    m_isAlive = true;
}

Ship::~Ship()
{

}

Blasterbolt* Ship::update(int readyToFireCnt)
{
    //controls
    if (GetKeyState(VK_RIGHT) & 0x8000)
        moveRight();

    if (GetKeyState(VK_LEFT) & 0x8000)
        moveLeft();

    if (GetKeyState(VK_UP) & 0x8000)
        moveUp();

    if (GetKeyState(VK_DOWN) & 0x8000)
        moveDown();

    if (GetKeyState(VK_SPACE) & 0x8000 && readyToFireCnt == 0)
            return shoot();

    //if (GetKeyState(VK_ESCAPE) & 0x8000)

    return nullptr;
}

void Ship::moveRight()
{
    if (m_body.x() < WINDOW_WIDTH - m_body.width())
        m_body.moveTo(m_body.x() + SHIP_SPEED, m_body.y());
}

void Ship::moveLeft()
{
    if (m_body.x() > 5)
        m_body.moveTo(m_body.x() - SHIP_SPEED, m_body.y());
}

void Ship::moveUp()
{
    if (m_body.y() > 15)
        m_body.moveTo(m_body.x(), m_body.y() - SHIP_SPEED);
}

void Ship::moveDown()
{
    if (m_body.y() < 720)
        m_body.moveTo(m_body.x(), m_body.y() + SHIP_SPEED);
}

Blasterbolt* Ship::shoot()
{
    return new Blasterbolt(m_body.x() + SHIP_WIDTH,
                           m_body.y() + (SHIP_WIDTH / 2) - (BLASTER_HEIGHT / 2),
                           true,
                           BLASTER_SPEED);
}
