#ifndef BLASTERBOLT_H
#define BLASTERBOLT_H

#include "gameObject.h"
#include "defines.h"
#include <qdebug.h>

class Blasterbolt : public GameObject
{
public:
    Blasterbolt(int xPos, int yPos, bool isFriendly, int speed);
    ~Blasterbolt();
    void update(const int &gameSpeed);

private:
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    int m_gameSpeed;
    bool m_isFriendly;
};

#endif // BLASTERBOLT_H
