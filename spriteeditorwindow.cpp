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

    int red = ui->redSpinbox->value();
    int green = ui->greenSpinbox->value();
    int blue = ui->blueSpinbox->value();
    int alpha = ui->alphaSpinbox->value();

    emit sendClick(currentTool, frameID, x, y, red, green, blue, alpha);
}


void SpriteEditorWindow::on_alphaSpinbox_valueChanged(int arg1){
    updatePreviewColor();
}


void SpriteEditorWindow::on_greenSpinbox_valueChanged(int arg1){
    updatePreviewColor();
}


void SpriteEditorWindow::on_blueSpinbox_valueChanged(int arg1){
    updatePreviewColor();
}


void SpriteEditorWindow::on_redSpinbox_valueChanged(int arg1){
    updatePreviewColor();
}

void SpriteEditorWindow::updatePreviewColor(){

    QString colorChange = QString("background: rgba(%1, %2, %3, %4)")
                              .arg(ui->redSpinbox->value())
                              .arg(ui->greenSpinbox->value())
                              .arg(ui->blueSpinbox->value())
                              .arg(ui->alphaSpinbox->value());

    ui->colorPreview->setStyleSheet(colorChange);
}

void SpriteEditorWindow::on_PenTool_clicked()
{
    currentTool = pen;
}


void SpriteEditorWindow::on_EraseTool_clicked()
{
    currentTool = eraser;
}

