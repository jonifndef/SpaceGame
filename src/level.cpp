#include "level.h"

//int Level::m_gameSpeed = 2;

Level::Level() : GameObject(0, 0, 900, 800)
{
    if (!m_texture.load("res/spacegame_background.png"))
        qDebug() << "Pixmap error in Level!";
    m_secondBody.setRect(m_body.width(), 0, 900, 800);
    m_isAlive = true;
    m_progress = 0;
}

Level::~Level()
{
    qDebug() << "Level destructor called!";
}

void Level::paint(QPainter &painter)
{
    painter.drawPixmap(m_body, m_texture);
    painter.drawPixmap(m_secondBody, m_texture);
}

void Level::update(QRect ship)
{
    this->moveLeft();

    if (m_body.x() + m_body.width() < 0)
        m_body.moveTo(m_secondBody.x() + m_secondBody.width(), 0);
    else if (m_secondBody.x() + m_secondBody.width() < 0)
    {
        m_secondBody.moveTo(m_body.x() + m_body.width(), 0);
        m_progress++;
    }

    //Update "game speed" based on the players position
    if (ship.x() > 0 && ship.x() < 120)
        m_gameSpeed = 2;
    else if (ship.x() > 120 && ship.x() < 450)
        m_gameSpeed = 3;
    else if (ship.x() > 450 && ship.x() < 800)
        m_gameSpeed = 4;
}

void Level::moveLeft()
{
    m_body.moveTo(m_body.x() - m_gameSpeed, m_body.y());
    m_secondBody.moveTo(m_secondBody.x() - m_gameSpeed, m_secondBody.y());
}
