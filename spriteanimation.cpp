#include "spriteanimation.h"
#include "ui_spriteanimation.h"

SpriteAnimation::SpriteAnimation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpriteAnimation)
{
    ui->setupUi(this);
    animationDelay = 10;

}

SpriteAnimation::~SpriteAnimation()
{
    delete ui;
}

void SpriteAnimation::updateFrames(QMap<int, QImage> frames) {
    ourFrames.swap(frames);
}

void SpriteAnimation::changeDelay(int newDelay) {
    animationDelay = newDelay;
}
