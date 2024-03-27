#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpriteEditorWindow){
    ui->setupUi(this);
}

SpriteEditorWindow::~SpriteEditorWindow(){
    delete ui;
}

void SpriteEditorWindow::processClick(int frameID, int x, int y) {

}


void SpriteEditorWindow::on_alphaSpinbox_valueChanged(int arg1){

}


void SpriteEditorWindow::on_greenSpinbox_valueChanged(int arg1){

}


void SpriteEditorWindow::on_blueSpinbox_valueChanged(int arg1){

}


void SpriteEditorWindow::on_redSpinbox_valueChanged(int arg1){

}

void SpriteEditorWindow::changePreviewColor(int red, int green, int blue, int alpha){

    QString colorChange = QString("background: rgba(%1, %2, %3, %4)")
                              .arg(red)
                              .arg(green)
                              .arg(blue)
                              .arg(alpha);

    ui->colorPreview->setStyleSheet(colorChange);
}
