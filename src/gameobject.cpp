#include "gameobject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(int xPos, int yPos, int width, int height) : m_body(xPos, yPos, width, height)
{

}

//void GameObject::update()
//{
//
//}
//
//void GameObject::update(QRect rect)
//{
//
//}

bool GameObject::didCollide(const QRect &other) const
{
    if ((m_body.x() <= other.x() + other.width() &&
         m_body.x() + m_body.width() >= other.x()) &&
        (m_body.y() <= other.y() + other.height() &&
         m_body.y() + m_body.height() >= other.y()))
        return true;
    return false;
}
