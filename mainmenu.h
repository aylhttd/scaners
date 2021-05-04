#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include "number_of_zakladka_choise.h"

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    mainmenu(QWidget *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent  *mEvent);

private slots:
    void open_help_window() const;
    void open_about_window() const;
    void open_password_window();
    void open_game_window();
    void open_nelin_window();
    void open_scan_window();
    void open_con_window();
    void open_constr_window();
private:
    void keyPressEvent(QKeyEvent *event);

    ////
    myGraphicsView* view;
    QGraphicsScene* scene;
    ////

    bool is_password_true = false;
    QVBoxLayout *vbox;
    set<Pixmap *> set_of_main_menu_elements;
    QLabel *title;
    //QPushButton* _pass;
    //QPushButton *start_with_con;
    QPushButton *start_with_rand;
    QPushButton *start_with_nelin;
    QPushButton *start_with_scan;
    QPushButton *help_;
    QPushButton *about_;
    QPushButton *exit_;
};
#endif // MAINWINDOW_H
