#ifndef FORMWIDGET_H
#define FORMWIDGET_H

#include <iostream>
#include <QLineEdit>
#include <QPushButton>

class FormWidget : public QWidget
{
    Q_OBJECT

public:
    FormWidget(QWidget *parent);

private slots:
    void submitted();

private:
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *age;
    QPushButton *submitButton;

};
#endif // FORMWIDGET_H
