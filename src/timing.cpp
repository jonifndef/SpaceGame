#include "timing.h"

Timing::Timing()
{
    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(timerISR()));
    m_timer->start(80);
}

Timing::~Timing()
{

}
