#include "digitalclock.h"
#include <QTime>

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setDigitCount(8);
    setSegmentStyle(QLCDNumber::Flat);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::updateDisplay);
    timer->start(1000);
    updateDisplay();
}

DigitalClock::~DigitalClock()
{
}

void DigitalClock::updateDisplay()
{
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("hh:mm:ss");
    display(timeString);
}
