#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>

class todolist : public QWidget
{
    Q_OBJECT
public:
  //c  todolist();
    todolist(QWidget * parent );

private slots:
    void addItem();
    void removeItem();

private:
    QPushButton* addButton;
    QPushButton *removeButton;
    QLineEdit *inputLine;
    QListWidget *listOfTasks;
};

#endif // TODOLIST_H
