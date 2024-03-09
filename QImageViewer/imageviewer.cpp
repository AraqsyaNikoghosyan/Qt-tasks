#include "imageviewer.h"
#include <QFileDialog>
#include <QMenuBar>
#include <QFileInfo>

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
{
    imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignCenter);
    setCentralWidget(imageLabel);

    createActions();
    createMenus();
}

ImageViewer::~ImageViewer()
{
}

void ImageViewer::createActions()
{
    QAction *openAction = new QAction("&Open...", this);
    connect(openAction, &QAction::triggered, this, &ImageViewer::openImage);

    QAction *zoomInAction = new QAction("Zoom In", this);
    connect(zoomInAction, &QAction::triggered, this, &ImageViewer::zoomIn);

    QAction *zoomOutAction = new QAction("Zoom Out", this);
    connect(zoomOutAction, &QAction::triggered, this, &ImageViewer::zoomOut);

    QAction *rotateClockwiseAction = new QAction("Rotate Clockwise", this);
    connect(rotateClockwiseAction, &QAction::triggered, this, &ImageViewer::rotateClockwise);

    addAction(openAction);
    addAction(zoomInAction);
    addAction(zoomOutAction);
    addAction(rotateClockwiseAction);
}

void ImageViewer::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&Open...", this, &ImageViewer::openImage);

    QMenu *viewMenu = menuBar()->addMenu("&View");
    viewMenu->addAction("Zoom In", this, &ImageViewer::zoomIn);
    viewMenu->addAction("Zoom Out", this, &ImageViewer::zoomOut);
    viewMenu->addAction("Rotate Clockwise", this, &ImageViewer::rotateClockwise);
}

void ImageViewer::openImage()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (imagePath.isEmpty())
        return;

    pixmap.load(imagePath);
    updateImage();
}

void ImageViewer::zoomIn()
{
    pixmap = pixmap.scaled(pixmap.width() * 1.1, pixmap.height() * 1.1, Qt::KeepAspectRatio);
    updateImage();
}

void ImageViewer::zoomOut()
{
    pixmap = pixmap.scaled(pixmap.width() * 0.9, pixmap.height() * 0.9, Qt::KeepAspectRatio);
    updateImage();
}

void ImageViewer::rotateClockwise()
{
    pixmap = pixmap.transformed(QTransform().rotate(90));
    updateImage();
}

void ImageViewer::updateImage()
{
    imageLabel->setPixmap(pixmap);
}
