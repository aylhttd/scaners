#include "help_window.h"
#include "ui_help_window.h"

help_window::help_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_window)
{
    ui->setupUi(this);
}

help_window::~help_window()
{
    delete ui;
}
