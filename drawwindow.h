#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QWidget>

namespace Ui {
class DrawWindow;
}

class DrawWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();

private:
    Ui::DrawWindow *ui;

public slots:
    void updateImages(QImage frames[]);

signals:
    void click(int ID, int x, int y);
};

#endif // DRAWWINDOW_H
