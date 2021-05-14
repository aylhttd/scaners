#include "number_of_signal_chiose.h"

number_of_signal_chiose::number_of_signal_chiose(QWidget *parent) :
    QDialog(parent)
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

    QLabel *title = new QLabel("Выберите количество сигналов", this);
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

    all = new QLineEdit();
    all->setFont(font_for_label);
    all->setMaximumSize(380, 180);
    all->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    all->setValidator(new QIntValidator(2, 8, this));
    all->setStyleSheet("QLineEdit {    border: 2px solid gray;    border-radius: 10px;    padding: 0 8px;    background:  rgba(255, 255, 0, 120);    selection-background-color: rgba(255, 255, 0, 120);    }");
    all->setFont(font_for_label);
    //all->setAlignment(Qt::AlignLeft);
    all->setText("2");
    hbox->addWidget(all, Qt::AlignHCenter);

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
    connect(OK, &QPushButton::clicked, this, &number_of_signal_chiose::OK_clicked);
}

number_of_signal_chiose::~number_of_signal_chiose()
{

}

void number_of_signal_chiose::closeEvent(QCloseEvent *event)
{
    event->accept();
    this->parentWidget()->show();   //done
}

void number_of_signal_chiose::OK_clicked()
{
    if(this->all->text().toInt() > 8)
        this->all->setText("8");

    if(this->all->text().toInt() <= 1)
        this->all->setText("2");

    if(this->all->text()=="")
        this->all->setText("2");

    MainWindow* randome_game_ =  randome_game_ = new MainWindow(nullptr, (int)(QApplication::screens().at(0)->availableSize().width()-200)/64/0.42-1, (int)(QApplication::screens().at(0)->availableSize().height())/64/0.42, this->all->text().toInt(), true);
        //randome_game_->set_number_of_zakl(this->active->text().toInt(), this->passive->text().toInt());
        randome_game_->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
        randome_game_->setWindowTitle("ИГРА");
        randome_game_->showFullScreen();
        //randome_game_->showMaximized();
        randome_game_->setModal(true);
        this->close();
        randome_game_->exec();
        randome_game_->~MainWindow();
}

void number_of_signal_chiose::Exit_clicked()
{
    this->close();
}

void number_of_signal_chiose::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        this->close();

    if(event->key() == Qt::Key_Return){
        this->OK_clicked();
    }
}
