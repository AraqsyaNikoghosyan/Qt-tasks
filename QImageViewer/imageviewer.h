#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void rotateClockwise();

private:
    void createActions();
    void createMenus();
    void updateImage();

    QLabel *imageLabel;
    QPixmap pixmap;
};

#endif // IMAGEVIEWER_H
