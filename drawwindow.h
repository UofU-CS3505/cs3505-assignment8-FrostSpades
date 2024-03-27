#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QWidget>

class DrawWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWindow(QWidget *parent = nullptr);

    void setPixel(int x, int y, int r, int g, int b, int alpha);
    void deletePixel(int x, int y);
    QColor getPixel(int x, int y);
    QImage getImageData();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QImage image;
    QColor currentColor;
    int scale; // Scale factor for pixels
    int size;  // size of image
public slots:
    void changeFrame(int ID);
    void updateFrames(QImage frames[]);
signals:
    void click(int frameID, int x, int y);
};

#endif // PIXELEDITORWIDGET_H
