#include "drawingwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>

DrawingWidget::DrawingWidget(QWidget *parent) : QWidget(parent), shape(0), isDrawing(false) {
    lineButton = new QPushButton("Line", this);
    connect(lineButton, &QPushButton::clicked, this, &DrawingWidget::setLineShape);

    rectButton = new QPushButton("Rectangle", this);
    connect(rectButton, &QPushButton::clicked, this, &DrawingWidget::setRectangleShape);

    lineButton->move(10, 10);
    rectButton->move(10, 40);

    // Set the size of the drawing area
    setFixedSize(800, 600);
}

void DrawingWidget::setLineShape() {
    shape = 0;
    isDrawing = false;
    update();
}

void DrawingWidget::setRectangleShape() {
    shape = 1;
    isDrawing = false;
    update();
}

void DrawingWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
        isDrawing = true;
    }
}

void DrawingWidget::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && isDrawing) {
        endPos = event->pos();
        update();
    }
}

void DrawingWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isDrawing) {
        if (shape == 0)
            lineShapes.append(QLine(startPos, endPos));
        else if (shape == 1)
            rectShapes.append(QRect(startPos, endPos).normalized());

        isDrawing = false;
        update();
    }
}

void DrawingWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (const QLine &line : lineShapes)
        painter.drawLine(line);

    for (const QRect &rect : rectShapes)
        painter.drawRect(rect);

    if (isDrawing && shape == 0) {
        painter.setPen(Qt::gray);
        painter.drawLine(startPos, endPos);
    }

    else if (isDrawing && shape == 1) {
        painter.setPen(Qt::gray);
        painter.drawRect(QRect(startPos, endPos).normalized());
    }
}
