#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpriteEditorWindow){
    ui->setupUi(this);

    currentTool = pen;

}

SpriteEditorWindow::~SpriteEditorWindow(){
    delete ui;
}

DrawWindow* SpriteEditorWindow::getDrawWindow(){
    return ui->DrawWidget;
}

SpriteAnimation* SpriteEditorWindow::getAnimationWindow(){
    return ui->spriteAnimationWidg;
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

void SpriteEditorWindow::on_FillTool_clicked()
{
    currentTool = fillTool;
}


void SpriteEditorWindow::on_saveButton_clicked()
{
    emit saveButtonClicked();
}


void SpriteEditorWindow::on_startMenuButton_clicked()
{
    emit startMenuButtonClicked();
}

void SpriteEditorWindow::on_addFrameButton_clicked()
{
    ui->frameSwitcher->setMaximum(ui->frameSwitcher->maximum() + 1);

    emit addFrame();
}


void SpriteEditorWindow::on_frameSwitcher_valueChanged(int newFrame)
{
    emit setCurrentFrame(newFrame);
}


void SpriteEditorWindow::on_deleteCurrentFrame_clicked()
{
    int currentFrame = ui->frameSwitcher->value() - 1;

    if(ui->frameSwitcher->maximum() != 1){
        ui->frameSwitcher->setMaximum(ui->frameSwitcher->maximum() - 1);
    }

    if (currentFrame == 0) {
        emit setCurrentFrame(1);
    }
    else {
        ui->frameSwitcher->setValue(currentFrame);
        emit setCurrentFrame(currentFrame);
    }

    emit deleteCurrentFrame(currentFrame);
}

void SpriteEditorWindow::setSpinbox(int newMaxValue){
    ui->frameSwitcher->setMaximum(newMaxValue);
    ui->leftSwitchSpinbox->setMaximum(newMaxValue);
    ui->rightSwitchSpinbox->setMaximum(newMaxValue);
}

void SpriteEditorWindow::on_horizontalSlider_sliderMoved(int position)
{
    emit updateDelayOfAnimation(position);
}



void SpriteEditorWindow::on_switchFramesButton_clicked()
{
    emit swapFrames(ui->leftSwitchSpinbox->value()-1, ui->rightSwitchSpinbox->value()-1);
}


