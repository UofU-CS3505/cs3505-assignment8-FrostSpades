#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QLabel>

using namespace std;

namespace Ui {
class SpriteAnimation;
}

class SpriteAnimation : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteAnimation(QWidget *parent = nullptr);
    ~SpriteAnimation();

    void startAnimation();

private:
    Ui::SpriteAnimation *ui;
    QMap<int, QImage> ourFrames;
    int animationDelay;
    QTimer *timer;

    int currentIndex;

    QImage currentFrame() const;

protected:
    void paintEvent(QPaintEvent *event) override;




public slots:

    ///
    /// \brief updateFrames Model sendFrames signal, frame has been drawn on and needs to be updated in view.
    /// \param frames   All of the frames in the project.
    ///
    void updateFrames(std::vector<QImage> frameVector);

    ///
    /// \brief changeDelay  the delay of the fps in the animation has changed and needs to be updated.
    /// \param newDelay the new delay variable.
    ///
    void changeDelay(int newDelay);

    void paint();
};

#endif // SPRITEANIMATION_H
