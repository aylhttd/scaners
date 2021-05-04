#ifndef GRAPHIC_WINDOW_H
#define GRAPHIC_WINDOW_H

//C++ includes
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <random>
#include <ctime>
#include <set>
#include <utility>
#include <iterator>

//QT includes
#include <QtWidgets/QtWidgets>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtCore/qstate.h>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QIntValidator>
#include <QCloseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QLogValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QTimer>
#include <QTime>
#include <QMovie>
#include <QRegExp>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QTextStream>
#include <QTextCodec>
#include <QFile>
#include <QPicture>

//namespaces
using namespace std;
using namespace QtCharts;

class graphic_window : public QDialog
{
    Q_OBJECT

public:
    graphic_window(vector<pair<float, float>>* vec_of_graphik_of_second_formanta, QWidget *parent = nullptr);
    ~graphic_window();

    vector<pair<float, float>>* vec_of_graphik_of_second_formanta;
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *e);
    void update_only(vector<pair<float, float>>* vec_of_graphik_of_second_formanta);

private:
    QBarSeries *series_2th_formanta;
    pair<int, int>  _now_range_2th_command = make_pair(-1, -1);
    pair<float, float>  _now_range_2th_command_y = make_pair(-1, -1);
    QBarCategoryAxis *axisX = nullptr;
    QValueAxis *axisY = nullptr;
    QChartView *chartView_2th_formanta = nullptr;

};

#endif // GRAPHIC_WINDOW_H
