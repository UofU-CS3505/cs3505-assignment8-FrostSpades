#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::processClick(int frameID, int x, int y) {

}
