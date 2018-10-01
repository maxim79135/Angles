#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
#include "game.h"


namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

    void setGame(Game* game);

private:
    Ui::View *ui;
    Game* game;
    QPoint mousePosition;
    QPoint realMousePosition;
    QColor backGroundcolorOne;
    QColor backGroundcolorTwo;
    QColor chekercolorOne;
    QColor chekercolorTwo;

protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pbPlay_clicked();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_actionDefault_triggered();

    void on_action1_2_triggered();

    void on_action2_2_triggered();

    void on_action3_2_triggered();

    void on_action1_3_triggered();

    void on_action2_3_triggered();

    void on_action3_3_triggered();

    void on_actionInfo_triggered();

    void on_pbStop_clicked();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void hideTextLabel();

    void on_actionApp_triggered();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // VIEW_H
