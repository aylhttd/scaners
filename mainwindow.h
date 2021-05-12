#pragma once

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
#include <unordered_set>

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

//my includes
//#include "help.h"
//#include "about.h"
#include "graphic_window.h"

//namespaces
using namespace std;

//bool is_random_game_ = true;

static bool is_antennka_active = false;


class Pixmap : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Pixmap(const QPixmap &pix)
        : QObject(), QGraphicsPixmapItem(pix)
    {
        setCacheMode(DeviceCoordinateCache);
    }
    int height;
    int weight;
};

class CustomScene : public QGraphicsScene
{
private:

    bool is_item_needed;
public:
    list<Pixmap*> list_of_lamps;
    list<QPixmap*> list_of_l;
    Pixmap *item_lamps;
    CustomScene (bool flag = false) : QGraphicsScene(){
        //this->item_lamps = item;
        this->is_item_needed = flag;
    };

    void pushItem(Pixmap* item) {
        this->item_lamps = item;
        this->addItem(item);
    }

    double get_item_h()
    {
        return this->item_lamps->height;
    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        QGraphicsScene::mousePressEvent(event);
        if (this->is_item_needed) {
        if(!event->isAccepted()) {
            if(event->button() == Qt::LeftButton) {
                if (!is_antennka_active) {
                    this->removeItem(item_lamps);
                    this->list_of_l.clear();
                    this->list_of_lamps.clear();
                    qDebug() << "Custom scene clicked.";
                    QPixmap* full_lamps = new QPixmap();
                    full_lamps->load(":/new/prefix1/1lamp_A.png");
                    Pixmap *item_full_lamps = new Pixmap(*full_lamps);
                    //item_full_lamps->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
                    item_full_lamps->setPos(0, 0);
                    item_full_lamps->setFlag(QGraphicsItem::ItemIgnoresTransformations);
                    item_full_lamps->setVisible(1);
                    //item_full_lamps->setRotation(270);
                    item_full_lamps->setScale(0.63217);
                    this->pushItem(item_full_lamps);
                }
                else {
                    this->removeItem(item_lamps);
                    this->list_of_l.clear();
                    this->list_of_lamps.clear();
                    QPixmap* full_lamps = new QPixmap();
                    full_lamps->load(":/new/prefix1/1 lamp.png");
                    Pixmap *item_full_lamps = new Pixmap(*full_lamps);
                    //item_full_lamps->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
                    item_full_lamps->setPos(0, 190.92);
                    item_full_lamps->setFlag(QGraphicsItem::ItemIgnoresTransformations);
                    item_full_lamps->setVisible(1);
                    //item_full_lamps->setRotation(270);
                    item_full_lamps->setScale(0.6);
                    this->pushItem(item_full_lamps);
                }


            }
        }
        }
        is_antennka_active = !is_antennka_active;
    }
};

class myGraphicsView : public QGraphicsView
{

    Q_OBJECT

public:
    myGraphicsView(QGraphicsScene* scene) {
        //setDragMode(QGraphicsView::ScrollHandDrag);
        this->setScene(scene);
        this->scale(scale_koef, scale_koef);
    }

    /*void wheelEvent(QWheelEvent *event){
        const QGraphicsView::ViewportAnchor anchor = this->transformationAnchor();
        this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        int angle = event->angleDelta().y();
        qreal factor;

        if (angle > 0)
           factor = 1.1;
        else
           factor = 0.9;

        if ((scale_koef*factor > 0.5) & (scale_koef*factor < 1.5)) {
            this->scale(factor, factor);
            this->setTransformationAnchor(anchor);
            this->scale_koef*=factor;
        }
    }*/
    double get_scale_koef()
    {
        return scale_koef;
    }

private:
    double scale_koef = 0.42;
};

class myGraphicsViewForLights : public QGraphicsView
{
    Q_OBJECT
public:
    myGraphicsViewForLights(CustomScene* scene, bool flag) {
        //setDragMode(QGraphicsView::ScrollHandDrag);


      if(flag) {
        QPixmap* full_lamps = new QPixmap();
        full_lamps->load(":/new/prefix1/1 lamp.png");
        Pixmap *item_full_lamps = new Pixmap(*full_lamps);
        //item_full_lamps->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
        item_full_lamps->setPos(0, 190.92);
        item_full_lamps->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        item_full_lamps->setVisible(1);
        //item_full_lamps->setRotation(270);
        item_full_lamps->setScale(0.6);
        //scene->list_of_l.push_back(full_lamps);
        //scene->list_of_lamps.push_back(item_full_lamps);
        scene->pushItem(item_full_lamps);
      }
      this->setScene(scene);
    }

};
//              kostil'//

//              kostil'
class Hero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Hero(const QPixmap &pix)
        : QObject(), QGraphicsPixmapItem(pix)
    {
        setCacheMode(DeviceCoordinateCache);
        //this->mo->setFileName(":/new/random_game_textures/new/random_game_textures/Animation.gif");
    }

    pair<int, int> coordinate;
};
//              kostil'//


enum type_of_zakladka{passiv_, active_, empty_};
enum type_of_fluctuation{bluetooth_, _5g_, _4g_, _3g_, GPS_, radio_, GLONASS_};

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QDialog *parent = nullptr, int weight = 100, int height = 100, int active = 3, int passive = 3, bool is_this_rand_game = true);
    MainWindow(QDialog *parent = nullptr, int weight = 100, int height = 100, int all = 3, bool shit = true);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent * event);
    int generate_random_int_number(int min, int max) const;
    void generate_map();
    void add_hero();
    void add_zakl();
    bool is_coordinate_is_normal(pair<int, int> _coordinate) const;
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *mEvent);
    void light_switch(int level);
    void switch_formants(pair<int, int> kol_of_second_formant_and_third_formant_lights);
    void add_frames();
    bool set_number_of_zakl(int active, int passive);
    //bool eventFilter(QObject *obj, QEvent *event);
    QString get_counter_ooo();

    bool is_this_nelin_game = false;
    bool is_this_rand_game = false;

    Hero* _hero;
    int height_of_map;
    int weight_of_map;
    int col_vo_popytok = 3;
    Pixmap* _pix_chaged_cell = nullptr;
    pair<int, int> _vibrannaya_kletka = make_pair(-1, -1);
    QTimer* _timer;
    bool is_move_possible = true;

    //for scaners
    void generate_scaners_ist(int number);
    void refresh_graph();
    void generate_graphik_perems();
    void add_concret_fluct_second_formanta(int start, int length, float power_of_fluct);

    int number_of_sign;
    map<pair<int, int>, pair<type_of_fluctuation, float>> map_of_all_sign;
    map<pair<int, int>, float> finded_signal;
    vector<pair<float, float>>* vec_of_graphik_of_second_formanta;
    bool is_this_scan_game = false;
    bool is_this_first_push_button = true;

    graphic_window* _potomok;


protected slots:
    void slotTimerAlarm();

protected:


    QGraphicsTextItem* counter_ooo = new QGraphicsTextItem("");
    QString cntr;

    int chislo_aktivnyx_zakladok;
    int chislo_passivnix_zakladok;

    QHBoxLayout* hbox;
    myGraphicsView* view;
    myGraphicsViewForLights* view_for_lights;
    QGraphicsScene* scene;
    CustomScene* scene_for_lights;

    map<pair<int, int>, type_of_zakladka> map_of_all_zakl;
    map<pair<int, int>, type_of_zakladka> map_of_finded_zakl;
    vector<vector<type_of_zakladka>> vec_of_zakl;
    vector<vector<int>> vec_lights;

    vector<vector<pair<int, int>>> vec_of_powers;

    map<pair<int, int>, Pixmap*>  map_with_red_squares;



    Pixmap * item;

    //vector<vector<Pixmap*>> vec_of_pixmaps;
    std::mt19937* gen;
};
