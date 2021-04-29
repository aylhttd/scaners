#include "mainwindow.h"

MainWindow::MainWindow(QDialog *parent, int weight, int height, int active, int passive, bool is_this_rand_game) : QDialog(parent),  height_of_map(height), weight_of_map(weight)
{
    this->set_number_of_zakl(active, passive);
    this->setStyleSheet("background-color: lightGray;");

    this->gen = new std::mt19937(time(NULL));

    this->_timer = new QTimer();
    this->_timer->setTimerType(Qt::TimerType::CoarseTimer);
    connect(_timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    this->hbox = new QHBoxLayout(this);

    this->scene = new QGraphicsScene();
    this->scene_for_lights = new CustomScene(is_this_rand_game);
    this->view = new myGraphicsView(scene);


    if (!is_this_rand_game)
    {
        this->is_this_nelin_game = true;
        this->view_for_lights = new myGraphicsViewForLights(scene_for_lights, false);
    }

    if (is_this_rand_game)
    {
        this->is_this_rand_game = true;
        this->view_for_lights = new myGraphicsViewForLights(scene_for_lights, true);
    }

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view_for_lights->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_for_lights->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view_for_lights->setMaximumWidth(/*QApplication::screens().at(0)->availableSize().height()/10*/250);


    scene->setSceneRect(0, 0, 64 * (this->weight_of_map), 64 * (this->height_of_map));
    scene_for_lights->setSceneRect(0,0,250,QApplication::screens().at(0)->availableSize().height());


    hbox->addWidget(view);
    hbox->addWidget(view_for_lights);

    /*QPixmap* full_lamps = new QPixmap();
    full_lamps->load(":/new/prefix1/0lamps.png");
    Pixmap *item_full_lamps = new Pixmap(*full_lamps);
    //item_full_lamps->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
    item_full_lamps->setPos(90, 70);
    item_full_lamps->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    item_full_lamps->setVisible(1);
    //item_full_lamps->setRotation(270);
    item_full_lamps->setScale(0.6);
    this->scene_for_lights->addItem(item_full_lamps);*/

    //QString hui = "Найдено " + QString::fromStdString(to_string(this->map_of_finded_zakl.size())) + " из " + QString::fromStdString(to_string(this->map_of_all_zakl.size())) + " закладок";


    //QLabel counter;

    //scene_for_lights->addText("vadim")->setPos(10, 20);


    /*this->vec_of_pixmaps.resize(height);

    for(auto &obj : this->vec_of_pixmaps)
        obj.resize(weight);*/

    this->vec_of_zakl.resize(height);

    for(auto &obj : this->vec_of_zakl)
        obj.resize(weight, empty_);


    for(auto &obj : this->vec_lights)
        obj.resize(weight);

    this->generate_map();
    this->add_hero();
    this->add_zakl();

    if(this->is_this_nelin_game){
        //is_random_game_ = false;
        this->vec_of_powers.resize(this->height_of_map);

        for(auto obj : this->vec_of_powers)
            obj.resize(this->weight_of_map, make_pair(1, 1));

        QPixmap* f23 = new QPixmap();
        f23->load(":/new/prefix1/f23.png");
        Pixmap *item_23 = new Pixmap(*f23);
        item_23->setVisible(1);
        item_23->setScale(0.4);

        QPixmap* f20 = new QPixmap();
        f20->load(":/new/prefix1/2f0.png");
        Pixmap *item_20 = new Pixmap(*f20);
        item_20->setVisible(1);
        item_20->setScale(0.4);
        item_20->setPos(80, 80);

        QPixmap* f30 = new QPixmap();
        f30->load(":/new/prefix1/3f0.png");
        Pixmap *item_30 = new Pixmap(*f30);
        item_30->setVisible(1);
        item_30->setScale(0.4);
        item_30->setPos(142, 80);

        this->scene_for_lights->addItem(item_23);


        this->scene_for_lights->addItem(item_30);
        this->scene_for_lights->addItem(item_20);

        //размещай тут свои всратые текстуры, диман
    }


        QString cntr = "";
        for (int i =0; i<this->map_of_all_zakl.size(); ++i) {
            cntr+="◻ ";
            if (i%2)
                cntr+="\n";
        }
        this->counter_ooo->setPlainText(cntr);
        this->counter_ooo->setFont(QFont("Times new roman", 24, QFont::Bold));
        this->counter_ooo->setPos(100, 500);
        this->counter_ooo->update();
        this->scene_for_lights->addItem(counter_ooo);


}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

int MainWindow::generate_random_int_number(int min, int max) const
{
    std::uniform_int_distribution<> uid(min, max);
    if(min == max)
        return min;
    return uid(*this->gen);
}

void MainWindow::generate_map()
{
    int total_size_of_map = this->weight_of_map * this->height_of_map;

    QPixmap* kvadrat = new QPixmap();
    kvadrat->load(":/new/prefix1/kvadrat_1.png");

    for(int i = 0; i < this->height_of_map; ++i)
        for(int j = 0; j < this->weight_of_map; ++j){
            Pixmap *item_kvadrat = new Pixmap(*kvadrat);
            //this->vec_of_pixmaps[i][j] = item_kvadrat;
            item_kvadrat->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
            item_kvadrat->setPos(32. + 64. * (j), 32. + 64. * (i));
            scene->addItem(item_kvadrat);
        }
    //this->add_frames();
}

void MainWindow::add_hero()
{
    QPixmap* hero = new QPixmap();
    hero->load(":/new/prefix1/dot (1).png");

    this->_hero = new Hero(*hero);
    this->_hero->coordinate = make_pair(1, 1);
    _hero->setOffset(-hero->width()/2, -hero->height()/2);
    _hero->setPos(32., 32.);
    scene->addItem(_hero);
    this->add_frames();
}

void MainWindow::add_zakl()
{

    for(int i = 0; i < chislo_aktivnyx_zakladok; ++i){
        label:
        int height_of_this_zakl = this->generate_random_int_number(0, this->height_of_map - 1);
        int weight_of_this_zakl = this->generate_random_int_number(0, this->weight_of_map - 1);

        if((height_of_this_zakl == 0 || (weight_of_this_zakl == 0)) || map_of_all_zakl.find(make_pair(height_of_this_zakl, weight_of_this_zakl)) != map_of_all_zakl.end())
            goto label;


        map_of_all_zakl.insert(make_pair(make_pair(height_of_this_zakl, weight_of_this_zakl), active_));
        this->vec_of_zakl[height_of_this_zakl][weight_of_this_zakl] = active_;

        qDebug() << height_of_this_zakl << " " << weight_of_this_zakl;

    }

    for(int i = 0; i < chislo_passivnix_zakladok; ++i){
        label1:
        int height_of_this_zakl = this->generate_random_int_number(0, this->height_of_map - 1);
        int weight_of_this_zakl = this->generate_random_int_number(0, this->weight_of_map - 1);

        if((height_of_this_zakl == 0 || (weight_of_this_zakl == 0)) || map_of_all_zakl.find(make_pair(height_of_this_zakl, weight_of_this_zakl)) != map_of_all_zakl.end())
            goto label1;


        map_of_all_zakl.insert(make_pair(make_pair(height_of_this_zakl, weight_of_this_zakl), passiv_));
        this->vec_of_zakl[height_of_this_zakl][weight_of_this_zakl] = passiv_;

        qDebug() << height_of_this_zakl << " " << weight_of_this_zakl;
    }

}

bool MainWindow::is_coordinate_is_normal(pair<int, int> _coordinate) const
{
    if(_coordinate.first <= 0 || (_coordinate.second <= 0))
        return false;

    if(_coordinate.first > this->height_of_map || (_coordinate.second > this->weight_of_map))
        return false;

    return true;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Escape){
        QMessageBox::StandardButton mb = QMessageBox::question(this, "Внимание!", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No);

        if(mb == QMessageBox::No)
            return;
        else
            this->close();
    }
    /*if(!this->is_move_possible)
        return;*/

    vector<double> vec_of_power_active;
    vec_of_power_active.reserve(this->chislo_aktivnyx_zakladok);

    vector<double> vec_of_power_passive;
    vec_of_power_passive.reserve(this->chislo_passivnix_zakladok);

    //Z = 3*exp (-(((X-a).^2)/3 + ((Y-b).^2)/5)); active
    //Z = 3*exp (-((abs((X-a).*3) + (abs((Y-b).*5))))); passive
    //Z = 3* exp(-((X-a).^2+(Y-b).^2).^0.5); new passive

    if(event->key() == Qt::Key_W || event->key() == 0x0426){
         if(this->is_coordinate_is_normal(make_pair(this->_hero->coordinate.first - 1, this->_hero->coordinate.second))){
             this->_hero->setPos(this->_hero->pos().x(), this->_hero->pos().y() - 64.);

             QPixmap* kvadrat_blue = new QPixmap();
             kvadrat_blue->load(":/new/prefix1/kvadrat (1)Blue.png");

             Pixmap *item_kvadrat_blue = new Pixmap(*kvadrat_blue);
             item_kvadrat_blue->setOffset(-kvadrat_blue->width()/2, -kvadrat_blue->height()/2);
             item_kvadrat_blue->setPos(32. + 64. * (this->_hero->coordinate.second - 1), 32. + 64. * (this->_hero->coordinate.first - 1));

             scene->addItem(item_kvadrat_blue);

             this->_hero->update();
             this->_hero->coordinate = make_pair(this->_hero->coordinate.first - 1, this->_hero->coordinate.second);

             for(auto obj : this->map_with_red_squares){
                 scene->removeItem(obj.second);
                 scene->addItem(obj.second);
             }

             this->scene->removeItem(this->_hero);
             scene->addItem(this->_hero);

             for(auto &obj : this->map_of_all_zakl){
                if(obj.second == active_)
                     vec_of_power_active.push_back(3 * exp(-((pow(this->_hero->coordinate.first - obj.first.first, 2)) / 3 + (pow(this->_hero->coordinate.second - obj.first.second, 2)) / 5)));
                else
                     //vec_of_power_passive.push_back(3 * exp(-(abs((this->_hero->coordinate.first-obj.first.first) * 3) + (abs((this->_hero->coordinate.second-obj.first.second) * 5)))));
                    vec_of_power_passive.push_back(3 * exp(-(pow((pow((this->_hero->coordinate.first - obj.first.first),2) + pow(this->_hero->coordinate.second - obj.first.second,2)), 0.5))));

            }

             double max_of_active = *std::max_element(vec_of_power_active.begin(), vec_of_power_active.end());
             int lights_of_active = round(max_of_active / 3 * 9);

             double max_of_passive = *std::max_element(vec_of_power_passive.begin(), vec_of_power_passive.end());
             int lights_of_passive = round(max_of_passive / 3 * 9);

             if(this->is_this_rand_game)
                lights_of_active > lights_of_passive ? this->light_switch(lights_of_active) : this->light_switch(lights_of_passive);
             else
                 this->switch_formants(make_pair(lights_of_active, lights_of_passive));
             //this->light_switch( this->vec_lights[this->_hero->coordinate.first][this->_hero->coordinate.second]);
                //this->add_frames();

        }
    }

    if(event->key() == Qt::Key_A || event->key() == 0x0424){
        if(this->is_coordinate_is_normal(make_pair(this->_hero->coordinate.first, this->_hero->coordinate.second - 1))){
            this->_hero->setPos(this->_hero->pos().x() - 64., this->_hero->pos().y());

            QPixmap* kvadrat_blue = new QPixmap();
            kvadrat_blue->load(":/new/prefix1/kvadrat (1)Blue.png");

            Pixmap *item_kvadrat_blue = new Pixmap(*kvadrat_blue);
            item_kvadrat_blue->setOffset(-kvadrat_blue->width()/2, -kvadrat_blue->height()/2);
            item_kvadrat_blue->setPos(32. + 64. * (this->_hero->coordinate.second - 1), 32. + 64. * (this->_hero->coordinate.first - 1));

            scene->addItem(item_kvadrat_blue);

            this->_hero->update();
            this->_hero->coordinate = make_pair(this->_hero->coordinate.first, this->_hero->coordinate.second - 1);

            for(auto obj : this->map_with_red_squares){
                scene->removeItem(obj.second);
                scene->addItem(obj.second);
            }

            this->scene->removeItem(this->_hero);
            scene->addItem(this->_hero);

            for(auto &obj : this->map_of_all_zakl){
               if(obj.second == active_)
                    vec_of_power_active.push_back(3 * exp(-((pow(this->_hero->coordinate.first - obj.first.first, 2)) / 3 + (pow(this->_hero->coordinate.second - obj.first.second, 2)) / 5)));
               else
                    //vec_of_power_passive.push_back(3 * exp(-(abs((this->_hero->coordinate.first-obj.first.first) * 3) + (abs((this->_hero->coordinate.second-obj.first.second) * 5)))));
                    vec_of_power_passive.push_back(3 * exp(-(pow((pow((this->_hero->coordinate.first - obj.first.first),2) + pow(this->_hero->coordinate.second - obj.first.second,2)), 0.5))));
            }

            double max_of_active = *std::max_element(vec_of_power_active.begin(), vec_of_power_active.end());
            int lights_of_active = round(max_of_active / 3 * 9);

            double max_of_passive = *std::max_element(vec_of_power_passive.begin(), vec_of_power_passive.end());
            int lights_of_passive = round(max_of_passive / 3 * 9);

            if(this->is_this_rand_game)
               lights_of_active > lights_of_passive ? this->light_switch(lights_of_active) : this->light_switch(lights_of_passive);
            else
                this->switch_formants(make_pair(lights_of_active, lights_of_passive));
            //this->light_switch( this->vec_lights[this->_hero->coordinate.first][this->_hero->coordinate.second]);
                //this->add_frames();

        }
   }

    if(event->key() == Qt::Key_S || event->key() == 0x042b){
        if(this->is_coordinate_is_normal(make_pair(this->_hero->coordinate.first + 1, this->_hero->coordinate.second))){
            this->_hero->setPos(this->_hero->pos().x(), this->_hero->pos().y() + 64.);

            QPixmap* kvadrat_blue = new QPixmap();
            kvadrat_blue->load(":/new/prefix1/kvadrat (1)Blue.png");

            Pixmap *item_kvadrat_blue = new Pixmap(*kvadrat_blue);
            item_kvadrat_blue->setOffset(-kvadrat_blue->width()/2, -kvadrat_blue->height()/2);
            item_kvadrat_blue->setPos(32. + 64. * (this->_hero->coordinate.second - 1), 32. + 64. * (this->_hero->coordinate.first - 1));

            scene->addItem(item_kvadrat_blue);

            this->_hero->update();
            this->_hero->coordinate = make_pair(this->_hero->coordinate.first + 1, this->_hero->coordinate.second);

            for(auto obj : this->map_with_red_squares){
                scene->removeItem(obj.second);
                scene->addItem(obj.second);
            }

            this->scene->removeItem(this->_hero);
            scene->addItem(this->_hero);

            for(auto &obj : this->map_of_all_zakl){
               if(obj.second == active_)
                    vec_of_power_active.push_back(3 * exp(-((pow(this->_hero->coordinate.first - obj.first.first, 2)) / 3 + (pow(this->_hero->coordinate.second - obj.first.second, 2)) / 5)));
               else
                    //vec_of_power_passive.push_back(3 * exp(-(abs((this->_hero->coordinate.first-obj.first.first) * 3) + (abs((this->_hero->coordinate.second-obj.first.second) * 5)))));
                   vec_of_power_passive.push_back(3 * exp(-(pow((pow((this->_hero->coordinate.first - obj.first.first),2) + pow(this->_hero->coordinate.second - obj.first.second,2)), 0.5))));

           }

            double max_of_active = *std::max_element(vec_of_power_active.begin(), vec_of_power_active.end());
            int lights_of_active = round(max_of_active / 3 * 9);

            double max_of_passive = *std::max_element(vec_of_power_passive.begin(), vec_of_power_passive.end());
            int lights_of_passive = round(max_of_passive / 3 * 9);

            if(this->is_this_rand_game)
               lights_of_active > lights_of_passive ? this->light_switch(lights_of_active) : this->light_switch(lights_of_passive);
            else
                this->switch_formants(make_pair(lights_of_active, lights_of_passive));
            //this->light_switch( this->vec_lights[this->_hero->coordinate.first][this->_hero->coordinate.second]);
                //this->add_frames();

        }

   }

    if(event->key() == Qt::Key_D || event->key() == 0x0412){
        if(this->is_coordinate_is_normal(make_pair(this->_hero->coordinate.first, this->_hero->coordinate.second + 1))){
            this->_hero->setPos(this->_hero->pos().x() + 64., this->_hero->pos().y());

            QPixmap* kvadrat_blue = new QPixmap();
            kvadrat_blue->load(":/new/prefix1/kvadrat (1)Blue.png");

            Pixmap *item_kvadrat_blue = new Pixmap(*kvadrat_blue);
            item_kvadrat_blue->setOffset(-kvadrat_blue->width()/2, -kvadrat_blue->height()/2);
            item_kvadrat_blue->setPos(32. + 64. * (this->_hero->coordinate.second - 1), 32. + 64. * (this->_hero->coordinate.first - 1));

            scene->addItem(item_kvadrat_blue);

            this->_hero->update();
            this->_hero->coordinate = make_pair(this->_hero->coordinate.first, this->_hero->coordinate.second + 1);

            for(auto obj : this->map_with_red_squares){
                scene->removeItem(obj.second);
                scene->addItem(obj.second);
            }

            this->scene->removeItem(this->_hero);
            scene->addItem(this->_hero);

            for(auto &obj : this->map_of_all_zakl){
               if(obj.second == active_)
                    vec_of_power_active.push_back(3 * exp(-((pow(this->_hero->coordinate.first - obj.first.first, 2)) / 3 + (pow(this->_hero->coordinate.second - obj.first.second, 2)) / 5)));
               else
                    //vec_of_power_passive.push_back(3 * exp(-(abs((this->_hero->coordinate.first-obj.first.first) * 3) + (abs((this->_hero->coordinate.second-obj.first.second) * 5)))));
                   vec_of_power_passive.push_back(3 * exp(-(pow((pow((this->_hero->coordinate.first - obj.first.first),2) + pow(this->_hero->coordinate.second - obj.first.second,2)), 0.5))));
           }

            double max_of_active = *std::max_element(vec_of_power_active.begin(), vec_of_power_active.end());
            int lights_of_active = round(max_of_active / 3 * 9);

            double max_of_passive = *std::max_element(vec_of_power_passive.begin(), vec_of_power_passive.end());
            int lights_of_passive = round(max_of_passive / 3 * 9);

            if(this->is_this_rand_game)
               lights_of_active > lights_of_passive ? this->light_switch(lights_of_active) : this->light_switch(lights_of_passive);
            else
                this->switch_formants(make_pair(lights_of_active, lights_of_passive));
            //this->light_switch( this->vec_lights[this->_hero->coordinate.first][this->_hero->coordinate.second]);
                //this->add_frames();

        }
   }

   /*if(event->key() == Qt::Key_Return){
        if(this->_vibrannaya_kletka.first == -1 || (this->_vibrannaya_kletka.second == -1))
            return;



            if(this->map_of_all_zakl.find(_vibrannaya_kletka) != this->map_of_all_zakl.end()){
                if(this->map_of_all_zakl.find(_vibrannaya_kletka)->second == passiv_)
                    QMessageBox::warning(this, "Поздравляю, вы нашли закладку!", "Поздравляю, вы нашли пассивную закладку!");
                else
                    QMessageBox::warning(this, "Поздравляю, вы нашли закладку!", "Поздравляю, вы нашли активную закладку!");
                this->close();
                return;
            }
            else{
                this->col_vo_popytok = this->col_vo_popytok - 1;
                if(col_vo_popytok == 0){
                    QMessageBox::warning(this, "Мимо!", "Вы проиграли, попробуйте еще раз!");
                    this->close();
                    return;
                }
                QMessageBox::warning(this, "Мимо!", "Число оставшихся попыток: " + QString::number(this->col_vo_popytok));
            }
        }*/

   vec_of_power_active.clear();
   vec_of_power_passive.clear();
}

void MainWindow::mousePressEvent(QMouseEvent *mEvent)
{
    /*if(this->_pix_chaged_cell != nullptr){
        scene->removeItem(this->_pix_chaged_cell);
        this->_pix_chaged_cell->hide();
        this->_pix_chaged_cell = nullptr;
    }*/

    if(mEvent->windowPos().x() < this->view->width())
    {

    auto temp = make_pair(this->view->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).x(), this->view->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).y());   //i dont now how it working, but it working!
    temp = make_pair(temp.first-64*this->view->get_scale_koef(), temp.second-64*this->view->get_scale_koef());
    this->_vibrannaya_kletka = make_pair(floor(temp.second / 64) + 1, floor(temp.first / 64) + 1);

    if(this->_vibrannaya_kletka.first <= -1 || (this->_vibrannaya_kletka.second <= -1) || (this->_vibrannaya_kletka.first - 1 > this->height_of_map) || (this->_vibrannaya_kletka.second - 1 > this->weight_of_map))
        return;

    if(this->map_of_all_zakl.find(this->_vibrannaya_kletka) == this->map_of_all_zakl.end())
        return;

    QPixmap* red_square = new QPixmap();
    red_square->load(":/new/prefix1/kvadrat (1).png");  //загрузка красного квадрата в png

    this->_pix_chaged_cell = new Pixmap(*red_square);
    this->_pix_chaged_cell->setOffset(-red_square->width()/2, -red_square->height()/2);
    this->_pix_chaged_cell->setPos((this->_vibrannaya_kletka.second - 1) * 64. + 32., 64. * (this->_vibrannaya_kletka.first - 1) + 32.);
    scene->addItem(this->_pix_chaged_cell);

    map_of_finded_zakl.insert(make_pair(this->_vibrannaya_kletka, (this->map_of_all_zakl.find(this->_vibrannaya_kletka)->second)));

    this->map_with_red_squares.insert(make_pair(this->_vibrannaya_kletka, this->_pix_chaged_cell));

    QString cntr = "";
    for (int i = 0; i<map_of_finded_zakl.size(); ++i) {
        cntr += "◼ ";
        if(i%2)
            cntr += "\n";
    }
    for (int i = map_of_finded_zakl.size(); i<map_of_all_zakl.size(); ++i) {
        cntr += "◻ ";
        if(i%2)
            cntr += "\n";
    }


    this->counter_ooo->setPlainText(cntr);
    //this->counter_ooo->setPos(100, this->scene_for_lights->get_item_h()+10);
    this->counter_ooo->update();

    if(map_of_finded_zakl.size() == this->map_of_all_zakl.size()){
        QMessageBox::warning(this, "Поздравляю, вы нашли закладку!", "Поздравляю, вы нашли все закладки!");
        this->close();
    }
    }
    else
    {
        auto tmp = make_pair(this->view_for_lights->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).x(), this->view_for_lights->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).y());
        int bl1=0;

    }

}

void MainWindow::slotTimerAlarm()
{

}

void MainWindow::light_switch(int level)
{


    for(auto* obj : scene_for_lights->list_of_lamps){
        this->scene_for_lights->removeItem(obj);
        delete obj;
    }
    scene_for_lights->list_of_lamps.clear();

    for(auto* obj : scene_for_lights->list_of_l)
        delete obj;

    scene_for_lights->list_of_l.clear();

    int length_of_signal = 100;

    if(is_antennka_active) {
    QPixmap* lamps = new QPixmap();
        switch (level) {
        case 0:
            //this->scene_for_lights->
            Beep(250, length_of_signal);
            lamps->load(":/new/prefix1/1lamp_A.png");
            break;
        case 1:
            Beep(280, length_of_signal);
            lamps->load(":/new/prefix1/1lamp_A.png");
            break;
        case 2:
            Beep(310, length_of_signal);
            lamps->load(":/new/prefix1/2lamps_A.png");
            break;
        case 3:
            Beep(340, length_of_signal);
            lamps->load(":/new/prefix1/3lamps_A.png");
            break;
        case 4:
            Beep(370, length_of_signal);
            lamps->load(":/new/prefix1/4lamps_A.png");
            break;
        case 5:
            Beep(400, length_of_signal);
            lamps->load(":/new/prefix1/5lamps_A.png");
            break;
        case 6:
            Beep(430, length_of_signal);
            lamps->load(":/new/prefix1/6lamps_A.png");
            break;
        case 7:
            Beep(460, length_of_signal);
            lamps->load(":/new/prefix1/7lamps_A.png");
            break;
        case 8:
            Beep(490, length_of_signal);
            lamps->load(":/new/prefix1/8lamps_A.png");
            break;
        case 9:
            Beep(520, length_of_signal);
            lamps->load(":/new/prefix1/9lamps_A.png");
            break;
        default:
            lamps->load(":/new/prefix1/1lamps_A.png");
            break;
        }




        //auto* x = this->item;
        this->item = new Pixmap(*lamps);
        //item_full_lamps->setOffset(-kvadrat->width()/2, -kvadrat->height()/2);
        this->item->setPos(0,0);
        //item_lamps->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        this->item->setVisible(1);
        this->item->setScale(0.6);
        //item_lamps->setRotation(270);
        this->scene_for_lights->pushItem(this->item);
        /*if(this->item != x)
            this->scene_for_lights->removeItem(x);*/

        scene_for_lights->list_of_lamps.push_back(this->item);
        scene_for_lights->list_of_l.push_back(lamps);
}
        //delete x;
}

void MainWindow::switch_formants(pair<int, int> kol_of_second_formant_and_third_formant_lights)
{
    for(auto* obj : scene_for_lights->list_of_lamps){
        this->scene_for_lights->removeItem(obj);
        delete obj;
    }
    scene_for_lights->list_of_lamps.clear();

    for(auto* obj : scene_for_lights->list_of_l)
        delete obj;

    scene_for_lights->list_of_l.clear();

    //scene_for_lights->removeItem(scene_for_lights->item_lamps);

    int length_of_signal = 100;

    QPixmap* second_formant = new QPixmap();
    QPixmap* third_formant = new QPixmap();

        switch (kol_of_second_formant_and_third_formant_lights.first) {
        case 0:
            //this->scene_for_lights->
            //Beep(250, length_of_signal);
            second_formant->load(":/new/prefix1/2f0.png");
            break;
        case 1:
            //Beep(280, length_of_signal);
            second_formant->load(":/new/prefix1/2f1.png");
            break;
        case 2:
            //Beep(310, length_of_signal);
            second_formant->load(":/new/prefix1/2f2.png");
            break;
        case 3:
            //Beep(340, length_of_signal);
            second_formant->load(":/new/prefix1/2f3.png");
            break;
        case 4:
            //Beep(370, length_of_signal);
            second_formant->load(":/new/prefix1/2f4.png");
            break;
        case 5:
            //Beep(400, length_of_signal);
            second_formant->load(":/new/prefix1/2f5.png");
            break;
        case 6:
            //Beep(430, length_of_signal);
            second_formant->load(":/new/prefix1/2f6.png");
            break;
        case 7:
            //Beep(460, length_of_signal);
            second_formant->load(":/new/prefix1/2f7.png");
            break;
        case 8:
            //Beep(490, length_of_signal);
            second_formant->load(":/new/prefix1/2f8.png");
            break;
        case 9:
            //Beep(520, length_of_signal);
            second_formant->load(":/new/prefix1/2f9.png");
            break;
        default:
            second_formant->load(":/new/prefix1/2f1.png");
            break;
        }

        switch (kol_of_second_formant_and_third_formant_lights.second) {
        case 0:
            //this->scene_for_lights->
            //Beep(250, length_of_signal);
            third_formant->load(":/new/prefix1/3f0.png");
            break;
        case 1:
            //Beep(280, length_of_signal);
            third_formant->load(":/new/prefix1/3f1.png");
            break;
        case 2:
            //Beep(310, length_of_signal);
            third_formant->load(":/new/prefix1/3f2.png");
            break;
        case 3:
            //Beep(340, length_of_signal);
            third_formant->load(":/new/prefix1/3f3.png");
            break;
        case 4:
            //Beep(370, length_of_signal);
            third_formant->load(":/new/prefix1/3f4.png");
            break;
        case 5:
            //Beep(400, length_of_signal);
            third_formant->load(":/new/prefix1/3f5.png");
            break;
        case 6:
            //Beep(430, length_of_signal);
            third_formant->load(":/new/prefix1/3f6.png");
            break;
        case 7:
            //Beep(460, length_of_signal);
            third_formant->load(":/new/prefix1/3f7.png");
            break;
        case 8:
            //Beep(490, length_of_signal);
            third_formant->load(":/new/prefix1/3f8.png");
            break;
        case 9:
            //Beep(520, length_of_signal);
            third_formant->load(":/new/prefix1/3f9.png");
            break;
        default:
            third_formant->load(":/new/prefix1/3f1.png");
            break;
        }

        auto beep = max(kol_of_second_formant_and_third_formant_lights.first, kol_of_second_formant_and_third_formant_lights.second);
        /*switch (beep) {
        case 0:
            //this->scene_for_lights->
            Beep(250, length_of_signal);
            break;
        case 1:
            Beep(280, length_of_signal);
            break;
        case 2:
            Beep(310, length_of_signal);
            break;
        case 3:
            Beep(340, length_of_signal);
            break;
        case 4:
            Beep(370, length_of_signal);
            break;
        case 5:
            Beep(400, length_of_signal);
            break;
        case 6:
            Beep(430, length_of_signal);
            break;
        case 7:
            Beep(460, length_of_signal);
            break;
        case 8:
            Beep(490, length_of_signal);
            break;
        case 9:
            Beep(520, length_of_signal);
            break;
        default:
            break;
        }*/

        auto item_second = new Pixmap(*second_formant);
        item_second->setPos(80,80);
        item_second->setVisible(1);
        item_second->setScale(0.4);
        scene_for_lights->addItem(item_second);

        scene_for_lights->list_of_lamps.push_back(item_second);
        scene_for_lights->list_of_l.push_back(second_formant);

        auto item_third = new Pixmap(*third_formant);
        item_third->setPos(142,80);
        item_third->setVisible(1);
        item_third->setScale(0.4);
        scene_for_lights->addItem(item_third);

        scene_for_lights->list_of_lamps.push_back(item_third);
        scene_for_lights->list_of_l.push_back(third_formant);
}

void MainWindow::add_frames() {

    if((this->_hero->coordinate.first==1) || (this->_hero->coordinate.first==this->weight_of_map-1) || (this->_hero->coordinate.second==1) || (this->_hero->coordinate.second==this->height_of_map-1))
    {
    QPixmap* kvadrat = new QPixmap();
    kvadrat->load(":/new/prefix1/kvadrat_1.png");

    QPixmap* frame = new QPixmap();
    frame->load(":/new/prefix1/frame.png");

    for(int i = 0; i < this->height_of_map; ++i) {
        Pixmap *item_frame = new Pixmap(*frame);    //L
        //this->vec_of_pixmaps[i][j] = item_kvadrat;
        item_frame->setOffset(-frame->width()/2, -frame->height()/2);
        item_frame->setPos(32. + 64. * (0) - 8, 32. + 64. * (i));
        scene->addItem(item_frame);

        Pixmap *item_frame_right = new Pixmap(*frame);  //R
        //this->vec_of_pixmaps[i][j] = item_kvadrat;
        item_frame_right->setOffset(-frame->width()/2, -frame->height()/2);
        item_frame_right->setRotation(180);
        item_frame_right->setPos(32. + 64. * (weight_of_map-1) + 8, 32. + 64. * (i));
        scene->addItem(item_frame_right);

    }

    for(int i = 0; i < this->weight_of_map; ++i) {
        Pixmap *item_frame = new Pixmap(*frame);    //V
        //this->vec_of_pixmaps[i][j] = item_kvadrat;
        item_frame->setRotation(90);
        item_frame->setOffset(-frame->width()/2, -frame->height()/2);
        item_frame->setPos(32. + 64. * (i), 32. + 64. * (0) - 8);
        scene->addItem(item_frame);

        Pixmap *item_frame_right = new Pixmap(*frame);  //N
        //this->vec_of_pixmaps[i][j] = item_kvadrat;
        item_frame_right->setOffset(-frame->width()/2, -frame->height()/2);
        item_frame_right->setRotation(270);
        item_frame_right->setPos(32. + 64. * (i), 32. + 64. * (height_of_map-1) + 8);
        scene->addItem(item_frame_right);

    }
    }


}

bool MainWindow::set_number_of_zakl(int active, int passive)
{
    if ((active<0)||(passive<0))
        return false;
    else
       {
        this->chislo_aktivnyx_zakladok=active;
        this->chislo_passivnix_zakladok=passive;
    }
    return true;
}

