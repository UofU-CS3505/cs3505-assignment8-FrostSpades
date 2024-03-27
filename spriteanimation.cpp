#include "spriteanimation.h"
#include "ui_spriteanimation.h"

SpriteAnimation::SpriteAnimation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpriteAnimation)
{
    ui->setupUi(this);
}

SpriteAnimation::~SpriteAnimation()
{
    delete ui;
}

void SpriteAnimation::updateFrames(QImage frames[]) {

}

void SpriteAnimation::changeDelay(int newDelay) {

}
