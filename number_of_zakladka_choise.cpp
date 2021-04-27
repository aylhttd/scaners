#include "number_of_zakladka_choise.h"

change_size::change_size(QWidget *parent) : QDialog(parent)
{

    this->setStyleSheet("background-color: lightGray;");

    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();

    hbox->setAlignment(Qt::AlignHCenter);

    hbox->setSpacing(50);
    hbox->setContentsMargins(10, 10, 10, 10);
    vbox->setContentsMargins(50, 150, 50, 150);
    vbox->setSpacing(50);

    QFont font_for_buttons("Times new roman", 28, QFont::Bold);
    QFont font_for_label("Times new roman", 28, QFont::ExtraBold);

    QLabel *title = new QLabel("Выберите количество активных и пассивных закладок", this);
    title->setMaximumSize(1600, 160);
    title->setMinimumSize(800, 80);
    title->setFont(font_for_buttons);
    title->setScaledContents(true);
    /*QPixmap* title_pixmap = new QPixmap();
    title_pixmap->load(":/new/random_game_textures/new/random_game_textures/yakarta.png");  //загрузка красного квадрата в png*/
    //title->setPixmap(*title_pixmap);
    //title->resize(title_pixmap->size());
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addWidget(title, 0, Qt::AlignHCenter | Qt::AlignVCenter);



    active = new QLineEdit();
    active->setFont(font_for_label);
    active->setMaximumSize(380, 180);
    active->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    active->setValidator(new QIntValidator(1, 5, this));
    active->setStyleSheet("QLineEdit {    border: 2px solid gray;    border-radius: 10px;    padding: 0 8px;    background:  rgba(255, 255, 0, 120);    selection-background-color: rgba(255, 255, 0, 120);    }");
    active->setFont(font_for_label);
    //active->setAlignment(Qt::AlignLeft);
    active->setText("2");
    hbox->addWidget(active, Qt::AlignHCenter);

    passive = new QLineEdit();
    passive->setFont(font_for_label);
    passive->setMaximumSize(380, 180);
    passive->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    passive->setValidator(new QIntValidator(1, 5, this));
    passive->setStyleSheet("QLineEdit {    border: 2px solid gray;    border-radius: 10px;    padding: 0 8px;    background:  rgba(255, 255, 0, 120);    selection-background-color: rgba(255, 255, 0, 120);    }");
    passive->setFont(font_for_label);
    //passive->setAlignment(Qt::AlignLeft);
    passive->setText("2");
    hbox->addWidget(passive, Qt::AlignHCenter);

    vbox->addLayout(hbox);

    QPushButton *OK = new QPushButton("ОК", this);
    OK->setMinimumSize(500, 180);
    OK->setMaximumSize(600, 240);
    OK->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    OK->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     padding: 6px}");
    OK->setCursor(QCursor(Qt::PointingHandCursor));
    OK->setFont(font_for_buttons);
    vbox->addWidget(OK, 2, Qt::AlignHCenter);

    /*QPushButton *Exit = new QPushButton("Назад", this);
    Exit->setMinimumSize(500, 180);
    Exit->setMaximumSize(600, 240);
    Exit->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    Exit->setStyleSheet("QPushButton {      background-color: rgba(0, 0, 0, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    Exit->setCursor(QCursor(Qt::PointingHandCursor));
    Exit->setFont(font_for_buttons);
    vbox->addWidget(Exit, 3);

    connect(Exit, &QPushButton::clicked, this, &change_size::Exit_clicked);*/
    connect(OK, &QPushButton::clicked, this, &change_size::OK_clicked);
}

change_size::~change_size()
{
}

void change_size::closeEvent(QCloseEvent *event)
{
    event->accept();
    this->parentWidget()->show();   //done
}

void change_size::OK_clicked()
{
    //OK clicked        TODO

    if(this->active->text().toInt() > 10 || (this->active->text().toInt() < 0))
        this->active->setText("5");

    if(this->passive->text().toInt() > 10 || (this->passive->text().toInt() < 0))
        this->passive->setText("5");

    if(this->active->text()=="")
        this->active->setText("1");

    if(this->passive->text()=="")
        this->passive->setText("1");

    /*if(this->passive->text().toInt() != this->active->text().toInt()){
        QMessageBox::warning(this, "Повторите ввод!", "Количество закладок должно быть целым числом");
        return;*/

    /*if(this->passive->text().toInt() != this->active->text().toInt()){
        QMessageBox::warning(this, "Повторите ввод!", "Количество закладок должно быть больше 0");
        return;
    }*/


    //w.showMaximized();
    if(this->is_this_will_be_random_game){
        auto* randome_game_ = new MainWindow(nullptr, (int)(QApplication::screens().at(0)->availableSize().width()-250)/64/0.42-1, (int)(QApplication::screens().at(0)->availableSize().height())/64/0.42, this->active->text().toInt(), this->passive->text().toInt());
        //randome_game_->set_number_of_zakl(this->active->text().toInt(), this->passive->text().toInt());
        randome_game_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        randome_game_->setWindowTitle("ИГРА");
        randome_game_->showFullScreen();
        //randome_game_->showMaximized();
        randome_game_->setModal(true);
        this->close();
        randome_game_->exec();

        /*MainWindow w(nullptr, (int)(QApplication::screens().at(0)->availableSize().width())/64/0.42-1, (int)(QApplication::screens().at(0)->availableSize().height()-125)/64/0.42);
        w.setWindowFlags(Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
        w.showFullScreen();*/
    }

    /*if(this->is_this_will_be_prep_game){
        auto* prepod_game_ = new prepod_game(this, this->passive->text().toInt(), this->active->text().toInt());
        prepod_game_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        prepod_game_->setWindowTitle("Игра с преподавателем");
        //prepod_game_->showMaximized();
        prepod_game_->showFullScreen();
        prepod_game_->setModal(true);
        this->close();
        prepod_game_->exec();
    }

    if(this->is_this_will_be_god_game){
        auto* god_game_ = new nastr_game(this, this->passive->text().toInt(), this->active->text().toInt());
        god_game_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        god_game_->setWindowTitle("Настраиваемая игра");
        god_game_->showFullScreen();
        //god_game_->showMaximized();
        god_game_->setModal(true);
        this->close();
        god_game_->exec();
    }*/
}

void change_size::Exit_clicked()
{
    this->close();
}

void change_size::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        this->close();

    if(event->key() == Qt::Key_Return){
        this->OK_clicked();
    }
}
