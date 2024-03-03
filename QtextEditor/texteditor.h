#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QMenuBar>
#include <QTextEdit>
#include <QAction>

class textEditor : public QWidget
{
    Q_OBJECT

public:
    textEditor(QWidget *parent = nullptr);

private slots:
    void openFile();
    void saveFile();
    void exit();

private:
    QMenuBar *menu;
    QTextEdit *textEdit;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
};
#endif // TEXTEDITOR_H
