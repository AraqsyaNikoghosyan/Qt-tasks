#include "todolist.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>


todolist::todolist(QWidget *parent = nullptr)
    : QWidget (parent)
{
    //Q Horizontal Layout, Q Vertical Lyout
    QVBoxLayout *mainLayout  = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout();
    mainLayout -> addLayout(inputLayout);


    inputLine = new QLineEdit();
    inputLayout -> addWidget(inputLine);

    addButton = new QPushButton("Add");
    addButton->setStyleSheet("background-color: red; color : white");
    //CSS
    connect(addButton, &QPushButton::clicked, this, &todolist::addItem);
    inputLayout -> addWidget(addButton);
    //  connect(addButton, &QPushButton::clicked, this, &todolist::addItem);
    //1.sender, 2.sgnal, 3, receiver, 3,Slot , SIGNAL(clcicked(), SLOT())


    removeButton = new QPushButton("Remove");
    connect(removeButton, &QPushButton::clicked, this, &todolist::removeItem);
    mainLayout -> addWidget(removeButton);

    listOfTasks = new QListWidget();
    mainLayout -> addWidget(listOfTasks);
}


void todolist::addItem(){
    QString task = inputLine -> text().trimmed();
    listOfTasks -> addItem(task);
    inputLine -> clear();
}

void todolist::removeItem() {
    int row = listOfTasks->currentRow();
    if(row >= 0) {
        delete  listOfTasks -> takeItem(row);
    }
}
