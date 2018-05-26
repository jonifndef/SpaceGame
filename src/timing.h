#ifndef TIMING_H
#define TIMING_H

#include <QTimer>

class Timing : public QObject
{
public:
    Timing();
    ~Timing();

    static int getShipFireCnt();
    static int getSpawnEnemyOneCnt();
    static int getEnemyOneFireCnt();
    static int getEnemyOneFollowPlayerCnt();

    static void getShipFireCnt(int cnt);
    static void getSpawnEnemyOneCnt(int cnt);
    static void getEnemyOneFireCnt(int cnt);
    static void getEnemyOneFollowPlayerCnt(int cnt);
private:

    QTimer *m_timer;
    static int m_shipFireCnt;
    static int m_spawnEnemyOneCnt;
    static int m_enemyOneFireCnt;
    static int m_enemyOneFollowPlayerCnt;
private slots:
    void timerISR();
};

#endif // TIMING_H
