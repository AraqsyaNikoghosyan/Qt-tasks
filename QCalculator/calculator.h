#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>


class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void numberClicked();
    void operatorClicked();
    void equalsClicked();
    void clearClicked();

private:
    QLineEdit *expr;
    QPushButton *clear;
    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *zero;
    QPushButton *dot;
    QPushButton *plus;
    QPushButton *minus;
    QPushButton *mul;
    QPushButton *div;
    QPushButton *equal;

    QString Operand1;
    QString Operand2;
    QString Operator;
    QString expression;


};

#endif // CALCULATOR_H
