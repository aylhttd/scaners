#ifndef NUMBER_OF_ZAKLADKA_CHOISE_H
#define NUMBER_OF_ZAKLADKA_CHOISE_H

#include "mainwindow.h"

class change_size : public QDialog
{
    Q_OBJECT

public:
    explicit change_size(QWidget *parent = nullptr);
    ~change_size();

    bool is_this_will_be_random_game = false;
    bool is_this_will_be_prep_game = false;
    bool is_this_will_be_god_game = false;

    void closeEvent(QCloseEvent *event);

private slots:
    void OK_clicked();
    void Exit_clicked();

private:
    void keyPressEvent(QKeyEvent *event);
    QLineEdit *active;
    QLineEdit *passive;
};


#endif // NUMBER_OF_ZAKLADKA_CHOISE_H
