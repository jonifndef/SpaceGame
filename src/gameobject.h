#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <qpainter.h>
#include <qpixmap.h>
#include "defines.h"

class Ship;
class GameObject
{
public:
    GameObject();
    GameObject(int xPos, int yPos, int width, int height);
    virtual ~GameObject() {}
    virtual void paint(QPainter &painter) {painter.drawRect(m_body);}
    virtual void destroy() { m_isAlive = false; }
    virtual bool didCollide(const QRect &other) const;
    virtual bool isAlive() const { return m_isAlive; }
    virtual QRect getBody() const { return m_body; }

protected:
    QRect m_body;
    QPixmap m_texture;
    bool m_isAlive;
    int m_health;
};

#endif // GAMEOBJECT_H

