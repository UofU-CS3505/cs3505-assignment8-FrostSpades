/**
 * Window representing the sprite editor.
 * Provides sprite editor functionality.
 *
 * @author Ethan Andrews
*/

#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QWidget>
#include "spriteanimation.h"
#include "tools.h"
#include "drawwindow.h"

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr);
    ~SpriteEditorWindow();
    DrawWindow* getDrawWindow();
    SpriteAnimation* getAnimationWindow();

private:
    Ui::SpriteEditorWindow *ui;
    Tool currentTool;

public slots:
    void processClick(int frameID, int x, int y);
    void setSpinbox(int newMaxValue);
signals:
    void frameSpinBoxChanged(int frameID);
    void sendClick(Tool tool, int frameID, int x, int y, int red, int green, int blue, int alpha);
    void saveButtonClicked();
    void updateDelayOfAnimation(int delay);
    void startMenuButtonClicked();
    void addFrame();
    void deleteCurrentFrame(int frameID);
    void setCurrentFrame(int newFrame);
private slots:
    void on_alphaSpinbox_valueChanged(int arg1);
    void on_greenSpinbox_valueChanged(int arg1);
    void on_blueSpinbox_valueChanged(int arg1);
    void on_redSpinbox_valueChanged(int arg1);
    void updatePreviewColor();
    void on_PenTool_clicked();
    void on_EraseTool_clicked();
    void on_saveButton_clicked();
    void on_startMenuButton_clicked();
    void on_addFrameButton_clicked();
    void on_frameSwitcher_valueChanged(int arg1);
    void on_deleteCurrentFrame_clicked();
    void on_horizontalSlider_sliderMoved(int position);
    void on_pushButton_clicked();
};

#endif // SPRITEEDITORWINDOW_H
