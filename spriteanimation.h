#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <QWidget>

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

private:
    Ui::SpriteAnimation *ui;
    QMap<int, QImage> ourFrames;
    int animationDelay;
    QTimer *timer;






public slots:

    ///
    /// \brief updateFrames Model sendFrames signal, frame has been drawn on and needs to be updated in view.
    /// \param frames   All of the frames in the project.
    ///
    void updateFrames(QMap<int, QImage> frames);

    ///
    /// \brief changeDelay  the delay of the fps in the animation has changed and needs to be updated.
    /// \param newDelay the new delay variable.
    ///
    void changeDelay(int newDelay);
};

#endif // SPRITEANIMATION_H
