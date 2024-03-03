#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QList>

class QPushButton;

class DrawingWidget : public QWidget {
    Q_OBJECT
public:
    explicit DrawingWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void setLineShape();
    void setRectangleShape();

private:
    int shape;
    bool isDrawing;
    QPoint startPos;
    QPoint endPos;

    QList<QLine> lineShapes;
    QList<QRect> rectShapes;

    QPushButton *lineButton;
    QPushButton *rectButton;
};

#endif // DRAWINGWIDGET_H
