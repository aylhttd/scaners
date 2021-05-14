#include "mainmenu.h"

mainmenu::mainmenu(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("background-color: lightGrey;");

    //vbox = new QVBoxLayout(this);

    QGridLayout* gl = new QGridLayout(this);
    gl->setSpacing(16);
    //vbox->setContentsMargins(250, 15, 250, 50);
    //vbox->setSpacing(50);

    QFont font_for_buttons("Times new roman", 14, QFont::Bold);

    QFont font_for_label("Times new roman", 24, QFont::ExtraBold);

    title = new QLabel("", this);
    title->setFont(font_for_label);
    title->setScaledContents(true);
    QPixmap* title_pixmap = new QPixmap();
    title_pixmap->load(":/new/prefix1/field_detector_logo.png");
    title->setPixmap(*title_pixmap);
    //title->setMinimumSize(768, 256);
    //title->setMaximumSize(768, 256);
    //title->resize(title_pixmap->size());
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    gl->addWidget(title, 0, 0, 1, 3);

    start_with_rand = new QPushButton("", this);
    start_with_rand->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    start_with_rand->setCursor(QCursor(Qt::PointingHandCursor));
    start_with_rand->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    start_with_rand->setFont(font_for_buttons);
    //start_with_rand->setMinimumSize(256, 256);
    //start_with_rand->setMaximumSize(256, 256);
    start_with_rand->setIcon(QIcon(":/new/prefix1/full_lamps.png"));
    start_with_rand->setIconSize(QSize(192,192));
    gl->addWidget(start_with_rand, 1, 0, 1, 1);
    //vbox->addWidget(start_with_rand);

    start_with_nelin = new QPushButton("", this);
    start_with_nelin->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    start_with_nelin->setCursor(QCursor(Qt::PointingHandCursor));
    start_with_nelin->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    start_with_nelin->setFont(font_for_buttons);
    //start_with_nelin->setMinimumSize(256, 256);
    //start_with_nelin->setMaximumSize(256, 256);
    start_with_nelin->setIcon(QIcon(":/new/prefix1/full_for_button.png"));
    start_with_nelin->setIconSize(QSize(192,192));
    gl->addWidget(start_with_nelin, 1, 1, 1, 1);
    //vbox->addWidget(start_with_nelin);

            start_with_scan = new QPushButton("", this);
            start_with_scan->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            start_with_scan->setCursor(QCursor(Qt::PointingHandCursor));
            start_with_scan->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
            start_with_scan->setFont(font_for_buttons);
            //start_with_scan->setMinimumSize(256, 256);
            //start_with_scan->setMaximumSize(256, 256);
            start_with_scan->setIcon(QIcon(":/new/prefix1/bashenki.png"));
            start_with_scan->setIconSize(QSize(192,192));
            gl->addWidget(start_with_scan, 1, 2, 1, 1);
            //vbox->addWidget(start_with_scan);

    /*start_with_prep = new QPushButton("Режим с преподавателем", this);
    start_with_prep->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    start_with_prep->setCursor(QCursor(Qt::PointingHandCursor));
    start_with_prep->setStyleSheet("QPushButton {     background-color: rgba(0, 85, 0, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    start_with_prep->setFont(font_for_buttons);
    vbox->addWidget(start_with_prep);*/

    /*start_with_settings = new QPushButton("Настраиваемый режим", this);
    start_with_settings->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    start_with_settings->setCursor(QCursor(Qt::PointingHandCursor));
    start_with_settings->setStyleSheet("QPushButton {     background-color: rgba(0, 85, 0, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    start_with_settings->setFont(font_for_buttons);
    vbox->addWidget(start_with_settings);*/

    /*_pass = new QPushButton("Разблокировка режимов преподавателя", this);
    _pass->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    _pass->setCursor(QCursor(Qt::PointingHandCursor));
    _pass->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    _pass->setFont(font_for_buttons);
    vbox->addWidget(_pass);*/

    help_ = new QPushButton("", this);
    help_->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    help_->setCursor(QCursor(Qt::PointingHandCursor));
    help_->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    help_->setFont(font_for_buttons);
    //help_->setMinimumSize(256, 256);
    //help_->setMaximumSize(256, 256);
    help_->setIcon(QIcon(":/new/prefix1/vopr.png"));
    help_->setIconSize(QSize(192,192));
    gl->addWidget(help_, 2, 0, 1, 1);
   // vbox->addWidget(help_);

    about_ = new QPushButton("", this);
    about_->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    about_->setCursor(QCursor(Qt::PointingHandCursor));
    about_->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;  font: bold 26px;   min-width: 10em;     padding: 6px}");
    about_->setFont(font_for_buttons);
    //about_->setMinimumSize(256, 256);
    //about_->setMaximumSize(256, 256);
    about_->setIcon(QIcon(":/new/prefix1/ab.png"));
    about_->setIconSize(QSize(192,192));
    gl->addWidget(about_, 2, 1, 1, 1);
    //vbox->addWidget(about_);

    exit_ = new QPushButton("", this);
    exit_->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    exit_->setCursor(QCursor(Qt::PointingHandCursor));
    exit_->setStyleSheet("QPushButton {      background-color: rgba(0, 0, 0, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");
    exit_->setFont(font_for_buttons);
    //exit_->setMinimumSize(256, 256);
    //exit_->setMaximumSize(256, 256);
    exit_->setIcon(QIcon(":/new/prefix1/dver.png"));
    exit_->setIconSize(QSize(192,192));
    gl->addWidget(exit_, 2, 2, 1, 1);
    //vbox->addWidget(exit_);

    connect(exit_, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(help_, &QPushButton::clicked, this, &mainmenu::open_help_window);
    connect(about_, &QPushButton::clicked, this, &mainmenu::open_about_window);
    connect(start_with_rand, &QPushButton::clicked, this, &mainmenu::open_game_window);
    connect(start_with_nelin, &QPushButton::clicked, this, &mainmenu::open_nelin_window);
    connect(start_with_scan, &QPushButton::clicked, this, &mainmenu::open_scan_window);
    //connect(start_with_settings, &QPushButton::clicked, this, &mainmenu::open_constr_window);
    //connect(_pass, &QPushButton::clicked, this, &mainmenu::open_password_window);
    //connect(start_with_con, &QPushButton::clicked, this, &mainmenu::open_con_window);

    this->setMinimumSize(800, 544);
    //this->showMaximized();
}

void mainmenu::mousePressEvent(QGraphicsSceneMouseEvent  *mEvent)
{
    //this->view->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).x(), this->view->mapToScene(mEvent->windowPos().x(), mEvent->windowPos().y()).y();
}

void mainmenu::open_help_window() const
{
    /*help* _help_window = new help();
    _help_window->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    _help_window->setWindowTitle("Помощь");
    _help_window->setMinimumSize(480, 320);
    _help_window->show();*/
}

void mainmenu::open_about_window() const
{
    /*auto dialog_for_about = new about();
    dialog_for_about->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    dialog_for_about->setWindowTitle("О программе");
    dialog_for_about->setMinimumSize(480, 320);
    dialog_for_about->setMaximumSize(480, 320);
    dialog_for_about->setModal(true);
    dialog_for_about->exec();*/

    /*MainWindow w(nullptr, (int)(QApplication::screens().at(0)->availableSize().width())/64/0.42-1, (int)(QApplication::screens().at(0)->availableSize().height()-125)/64/0.42);
    w.setWindowFlags(Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
    w.showFullScreen();*/
}

void mainmenu::open_password_window()
{
    /*if(this->is_password_true)
        return;

    auto password_dialog_ = new password_dialog();
    password_dialog_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    password_dialog_->setWindowTitle("Вход в режим с преподавателем");
    password_dialog_->showFullScreen();
    password_dialog_->exec();

    if(password_dialog_->is_password_true){
        this->is_password_true = true;
        _pass->setStyleSheet("QPushButton {     background-color: rgba(0, 85, 0, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;     font: bold 26px;     min-width: 10em;     padding: 6px}");

        start_with_prep->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;  font: bold 26px;   min-width: 10em;     padding: 6px}");
        start_with_settings->setStyleSheet("QPushButton {     background-color: rgba(170, 85, 255, 100);     border-style: outset;     border-width: 2px;	border-radius: 10px;     border-color: rgb(85, 0, 127);     min-width: 10em;     padding:12px;} QPushButton:hover {     background-color:rgba(170, 0, 0, 100);     border-style: outset;     border-width: 2px;     border-radius: 10px;  font: bold 26px;   min-width: 10em;     padding: 6px}");
    }*/

}

void mainmenu::open_scan_window()
{
    auto change_size_ = new number_of_signal_chiose(this);
    change_size_->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    change_size_->setWindowTitle("Выберете количество сигналов");
    change_size_->showFullScreen();
}

void mainmenu::open_game_window()
{
    auto change_size_ = new change_size(this);
    change_size_->is_this_will_be_random_game = true;
    change_size_->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    change_size_->setWindowTitle("Выберете количество закладок");
    change_size_->showFullScreen();    
}

void mainmenu::open_nelin_window()
{
    auto change_size_ = new change_size(this);
    change_size_->is_this_will_be_nelin_game = true;
    change_size_->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    change_size_->setWindowTitle("Выберете количество закладок");
    change_size_->showFullScreen();
}

void mainmenu::open_con_window()
{
    /*QString full_fname = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "" , (tr("*.bin")));

    if(full_fname.size() == 0)
        return;

    QFile in(full_fname);
    if(!in.open(QFile::ReadOnly)){
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    QByteArray array;
    QDataStream instream(&in);
    instream >> array;

    QString instr_ = QTextCodec::codecForMib(106)->toUnicode(array);
    string instr = instr_.toStdString();

    int weight = std::count(instr.begin(), instr.end(), '}');

    string now_line = instr.substr(1, instr.find("}") - 1); //взятая "строка" целиком

    int height = std::count(now_line.begin(), now_line.end(), ']');

    in.close();

    auto con_game_ = new con_game(this, weight - 2, height - 2, full_fname);
    con_game_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
    con_game_->setWindowTitle("Режим с конфигурацией");
    con_game_->showFullScreen();*/
}

void mainmenu::open_constr_window()
{
   /* if(!this->is_password_true)
        return;

    auto change_size_ = new change_size(this);
    change_size_->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    change_size_->setWindowTitle("Выберете размер карты");
    change_size_->showFullScreen();
    change_size_->is_this_will_be_god_game = true;*/


}

void mainmenu::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        this->close();
}
