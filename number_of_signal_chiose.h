#ifndef NUMBER_OF_SIGNAL_CHIOSE_H
#define NUMBER_OF_SIGNAL_CHIOSE_H

#include "mainwindow.h"


class number_of_signal_chiose : public QDialog
{
    Q_OBJECT

public:
    explicit number_of_signal_chiose(QWidget *parent = nullptr);
    ~number_of_signal_chiose();


    void closeEvent(QCloseEvent *event);

private slots:
    void OK_clicked();
    void Exit_clicked();

private:
    void keyPressEvent(QKeyEvent *event);
    QLineEdit *all;
};

#endif // NUMBER_OF_SIGNAL_CHIOSE_H
