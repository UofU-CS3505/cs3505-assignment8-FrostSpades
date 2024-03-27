#include "drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent)
    : QWidget(parent)
{
    size = 8;
    setMouseTracking(true);
    resize(320, 320); // Set initial size to size X size
    image = QImage(size, size, QImage::Format_ARGB32);
    scale = 320 / size;
    image.fill(Qt::blue);   // Fill with transparent initially
    currentColor = Qt::red; // Default color set to red
}

void DrawWindow::setPixel(int x, int y, int r, int g, int b, int alpha)
{
    if (x >= 0 && x < size && y >= 0 && y < size) {
        QRgb color = qRgba(r, g, b, alpha);
        image.setPixel(x, y, color);
        update(); // Update widget to reflect changes
    }
}

void DrawWindow::deletePixel(int x, int y)
{
    if (x >= 0 && x < size && y >= 0 && y < size) {
        image.setPixel(x, y, qRgba(255, 255, 255, 0)); // Set pixel to transparent
        update();                                      // Update widget to reflect changes
    }
}

QColor DrawWindow::getPixel(int x, int y)
{
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return QColor(image.pixel(x, y));
    }
    return QColor(); // Return null color if out of bounds
}

QImage DrawWindow::getImageData()
{
    return image.copy(); // Return a copy to avoid direct manipulation of internal data
}

void DrawWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        int x = event->position().x() / scale; // Adjust coordinates for scaled image
        int y = event->position().y() / scale;
        setPixel(x,
                 y,
                 currentColor.red(),
                 currentColor.green(),
                 currentColor.blue(),
                 currentColor.alpha());
    } else if (event->button() == Qt::RightButton) {
        int x = event->position().x() / scale;
        int y = event->position().y() / scale;
        deletePixel(x, y);
    }
}

void DrawWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->position().x() / scale; // Adjust coordinates for scaled image
    int y = event->position().y() / scale;
    if (event->buttons() & Qt::LeftButton) {
        setPixel(x,
                 y,
                 currentColor.red(),
                 currentColor.green(),
                 currentColor.blue(),
                 currentColor.alpha());
    } else if (event->buttons() & Qt::RightButton) {
        deletePixel(x, y);
    }
}

void DrawWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, image.scaled(QSize(320, 320))); // Scale image to fit widget size
}

void DrawWindow::changeFrame(int ID) {

}

void DrawWindow::updateFrames(std::vector<QImage>& frames) {

}
