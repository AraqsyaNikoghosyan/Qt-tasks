#include "mainwindow.h"
#include  "todolist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *p = nullptr;
    todolist obj(p);

 //   todolist obj();
    obj.show();
    return a.exec();
}
