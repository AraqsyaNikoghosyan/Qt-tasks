#include "texteditor.h"
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QMenu>

textEditor::textEditor(QWidget *parent)
    : QWidget(parent)
{
    textEdit = new QTextEdit(this);

    menu = new QMenuBar(this);

    openAct = new QAction("open", this);
    connect(openAct, &QAction::triggered, this, &textEditor::openFile);
    menu -> addAction(openAct);

    saveAct = new QAction("save", this);
    connect(saveAct, &QAction::triggered, this, &textEditor::saveFile);
    menu -> addAction(saveAct);

    exitAct = new QAction("exit", this);
    connect(exitAct, &QAction::triggered, this, &textEditor::exit);
    menu -> addAction(exitAct);

}

void textEditor::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file.");
        }
    }
}
void textEditor::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not save file.");
        }
    }
}

void textEditor::exit() {
    qApp->exit();
}



