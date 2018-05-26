#ifndef Level_H
#define Level_H

#include "gameObject.h"
#include "defines.h"
#include <qdebug.h>

class Level : public GameObject
{
public:
    Level();
    ~Level();

    void paint(QPainter &painter);
    void update(QRect ship);
    int getProgress() const { return m_progress; }
    int getGameSpeed() const { return m_gameSpeed; }
private:
    void moveLeft();

    int m_gameSpeed;
    int m_progress;
    QRect m_secondBody;
};

#endif // Level_H
