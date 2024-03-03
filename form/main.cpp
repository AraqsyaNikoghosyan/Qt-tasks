#include "formwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *p = nullptr;
    FormWidget w(p);
    w.show();
    return a.exec();
}
