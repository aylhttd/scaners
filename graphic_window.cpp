#include "graphic_window.h"

graphic_window::graphic_window(vector<pair<float, float> > *vec_of_graphik_of_second_formanta, QWidget *parent) : vec_of_graphik_of_second_formanta(vec_of_graphik_of_second_formanta)
{
    //window build
    QVBoxLayout *grid = new QVBoxLayout(this);

    QFont font_for_buttons("Times new roman", 14, QFont::Bold);
    QFont font_for_label("Times new roman", 18, QFont::ExtraBold);

    chartView_2th_formanta = new QChartView(this);
    chartView_2th_formanta->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    grid->addWidget(chartView_2th_formanta);

    QChart *chart_2th_formanta = new QChart();
    chart_2th_formanta->setTitle("Осцилограмма");
    chart_2th_formanta->setTitleFont(font_for_buttons);
    //chartView_2th_formanta->l

    this->series_2th_formanta = new QBarSeries(chart_2th_formanta);
    //this->series_3th_formanta = new QBarSeries(chart_2th_formanta);

    QBarSet *set = new QBarSet("№1 450-500 МГц");
    //добавление первых 50 отсчетов на график

    QStringList categories;

    //выборка второй форманты
    for(int i = 0; i < 51; ++i){
        categories << QString::number(this->vec_of_graphik_of_second_formanta->operator[](i).first);
        *set << this->vec_of_graphik_of_second_formanta->operator[](i).second;
    }

    //добавление второй форманты на график
    //series_2th_formanta->append(set);

    chart_2th_formanta->addSeries(series_2th_formanta);

    //добавление третьей форманты на график
    //series_3th_formanta->append(set_3th_formanta);
    //chart_2th_formanta->addSeries(series_3th_formanta);

    //настройка осей
    QFont font_for_axis("Times new roman", 8, QFont::Bold);
    axisX = new QBarCategoryAxis();
    axisX->setTitleFont(font_for_axis);
    axisX->append(categories);
    axisX->setRange("450", "500");
    this->_now_range_2th_command = make_pair(450, 500);
    chart_2th_formanta->setAxisX(axisX, series_2th_formanta);
    series_2th_formanta->attachAxis(axisX);

    this->axisY = new QValueAxis();
    this->axisY->setRange(0., 60.);
    _now_range_2th_command_y = make_pair(0., 60.);
    chart_2th_formanta->addAxis(this->axisY, Qt::AlignLeft);
    series_2th_formanta->attachAxis(this->axisY);

    //chart_2th_formanta->createDefaultAxes();
    chartView_2th_formanta->setChart(chart_2th_formanta);

    this->chartView_2th_formanta->chart()->update();

    this->setGeometry(x(), y(), 480, 320);
}

void graphic_window::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        this->close();
}

void graphic_window::wheelEvent(QWheelEvent *e)
{
    static int shit = 0;
    ++shit;
    if((shit % 2 == 1))
        return;
    if(e->delta() > 0)
    {
        if(this->_now_range_2th_command.second <= 5500){
            this->_now_range_2th_command = make_pair(this->_now_range_2th_command.first + 50, this->_now_range_2th_command.second + 50);
            //this->axisX->setRange(QString::number(this->_now_range_2th_command.first), QString::number(this->_now_range_2th_command.second));

            axisX->clear();
            series_2th_formanta->clear();

            //QBarSet *set_3th_formanta = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
            QBarSet *set = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
            QStringList categories;

            for(int i = this->_now_range_2th_command.first; i <= this->_now_range_2th_command.second; ++i){
                categories << QString::number(this->vec_of_graphik_of_second_formanta->operator[](i - 450).first);
                *set << this->vec_of_graphik_of_second_formanta->operator[](i - 450).second;
            }

            series_2th_formanta->append(set);
            //series_2th_formanta->append(set_3th_formanta);
            axisX->append(categories);
            axisX->setRange(QString::number(this->_now_range_2th_command.first), (QString::number(this->_now_range_2th_command.second)));

            this->chartView_2th_formanta->chart()->update();
        }

    }
    else
    {
        if(this->_now_range_2th_command.first >= 500){
            this->_now_range_2th_command = make_pair(this->_now_range_2th_command.first - 50, this->_now_range_2th_command.second - 50);
            //this->axisX->setRange(QString::number(this->_now_range_2th_command.first), QString::number(this->_now_range_2th_command.second));

            axisX->clear();
            series_2th_formanta->clear();

            //QBarSet *set_3th_formanta = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
            QBarSet *set = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
            QStringList categories;

            for(int i = this->_now_range_2th_command.first; i <= this->_now_range_2th_command.second; ++i){
                categories << QString::number(this->vec_of_graphik_of_second_formanta->operator[](i - 450).first);
                *set << this->vec_of_graphik_of_second_formanta->operator[](i - 450).second;
            }

            series_2th_formanta->append(set);
            //series_2th_formanta->append(set_3th_formanta);
            axisX->append(categories);
            axisX->setRange(QString::number(this->_now_range_2th_command.first), (QString::number(this->_now_range_2th_command.second)));

            this->chartView_2th_formanta->chart()->update();
        }
    }

}

void graphic_window::update_only(vector<pair<float, float> > *vec_of_graphik_of_second_formanta)
{
    this->vec_of_graphik_of_second_formanta = vec_of_graphik_of_second_formanta;

    axisX->clear();
    series_2th_formanta->clear();

    //QBarSet *set_3th_formanta = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
    QBarSet *set = new QBarSet(QString::number(this->_now_range_2th_command.first) + "-" + QString::number(this->_now_range_2th_command.second) + " МГц");
    QStringList categories;

    for(int i = this->_now_range_2th_command.first; i <= this->_now_range_2th_command.second; ++i){
        categories << QString::number(this->vec_of_graphik_of_second_formanta->operator[](i - 450).first);
        *set << this->vec_of_graphik_of_second_formanta->operator[](i - 450).second;
    }

    series_2th_formanta->append(set);
    //series_2th_formanta->append(set_3th_formanta);
    axisX->append(categories);
    axisX->setRange(QString::number(this->_now_range_2th_command.first), (QString::number(this->_now_range_2th_command.second)));

    this->chartView_2th_formanta->chart()->update();
}

graphic_window::~graphic_window()
{

}
