/**
 * Window representing the sprite editor.
 * Provides sprite editor functionality.
 *
 * @author Ethan Andrews
*/

#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QWidget>
#include "tools.h"

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr);
    ~SpriteEditorWindow();

private:
    Ui::SpriteEditorWindow *ui;

public slots:
    void processClick(int frameID, int x, int y);
signals:
    void frameSpinBoxChanged(int frameID);
    void sendClick(Tool tool, int frameID, int x, int y);
    void saveButtonClicked();
    void updateDelayOfAnimation(int delay);
};

#endif // SPRITEEDITORWINDOW_H
