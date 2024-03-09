#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);
    ~DigitalClock();

private slots:
    void updateDisplay();

private:
    QTimer *timer;
};

#endif // DIGITALCLOCK_H
