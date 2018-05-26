#ifndef SHIP_H
#define SHIP_H
#include "gameobject.h"
#include "blasterbolt.h"
#include "defines.h"
#include <Windows.h>

class Ship : public GameObject
{
public:
    Ship();
    ~Ship();

    Blasterbolt* update(int readyToFireCnt);
    Blasterbolt* shoot();
private:
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};
#endif // SHIP_H
