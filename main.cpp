#include "mainmenu.h"

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w(nullptr, (int)(QApplication::screens().at(0)->availableSize().width())/64/0.42-1, (int)(QApplication::screens().at(0)->availableSize().height()-125)/64/0.42);
    //w.setWindowFlags(Qt::FramelessWindowHint/* | Qt::WindowStaysOnTopHint*/);
    //w.showFullScreen();


    mainmenu w;
    w.setWindowTitle("FIELD DETECTOR");
    w.show();

    return a.exec();
}
