#include "formwidget.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>
FormWidget::FormWidget(QWidget *parent = nullptr) : QWidget(parent)
{
    QVBoxLayout *mainLayout  = new QVBoxLayout(this);

    name = new QLineEdit();
    name->setPlaceholderText(QString("name"));
    surname = new QLineEdit();
    surname->setPlaceholderText(QString("surname"));
    age = new QLineEdit();
    age->setPlaceholderText(QString("age"));

    mainLayout -> addWidget(name);
    mainLayout -> addWidget(surname);
    mainLayout -> addWidget(age);

    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("background-color: green; color : white");
    connect(submitButton, &QPushButton::clicked, this, &FormWidget::submitted);
    mainLayout -> addWidget(submitButton);

}

void FormWidget::submitted() {
    if(name->text().trimmed() == "" || surname->text().trimmed() == "" || age->text().trimmed() == "") {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
    }
    else {
        QMessageBox::information(this, "Success", "Form submitted successfully.");
        name -> clear();
        surname -> clear();
        age -> clear();
    }
}

