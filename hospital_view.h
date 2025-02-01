#ifndef HOSPITAL_VIEW_H
#define HOSPITAL_VIEW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "hopital.h"
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include "arduino.h"
namespace Ui {
class hospital_view;
}

class hospital_view : public QMainWindow
{
    Q_OBJECT

public:
    explicit hospital_view(QWidget *parent = nullptr);
    ~hospital_view();

    void showStatistics();

private slots:
    void on_ADD_clicked();

    void on_SHOW_clicked();

    void on_reset_2_clicked();

    void on_suppression_clicked();

    void on_MODIFY_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();

    void on_tri_phone_clicked();

    void on_tri_adresse_clicked();

    void on_tri_capacity_clicked();

    void on_tri_speciality_clicked();

    void on_tri_nbr_clicked();

    void on_tri_date_clicked();

    void on_PDF_clicked();

    void on_calendar_clicked();

    void on_EXCEL_clicked();

    void on_SEARCH_2_clicked();

    void on_ON_clicked();

    void on_OFF_clicked();

     void update_label();


     void on_tabWidget_currentChanged(int index);

private:
    Ui::hospital_view *ui;
    HOPITAL H;
    QCustomPlot *specialityChart;
        QCustomPlot *capacityChart;
QPieSeries* generateSpecialitiesData();
QPieSeries* generateCapacityData();
QByteArray data; // variable contenant les données reçues

   Arduino A; // objet temporaire
};

#endif // HOSPITAL_VIEW_H
