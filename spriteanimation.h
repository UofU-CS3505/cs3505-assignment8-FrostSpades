#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <QWidget>

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

public slots:
    void updateFrames(QImage frames[]);
    void changeDelay(int newDelay);
};

#endif // SPRITEANIMATION_H
