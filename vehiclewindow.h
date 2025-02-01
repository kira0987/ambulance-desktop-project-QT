#ifndef VEHICLEWINDOW_H
#define VEHICLEWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "vehicule.h"
#include <QtCharts>
namespace Ui {
class VehicleWindow;
}

class VehicleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VehicleWindow(QWidget *parent = nullptr);
    ~VehicleWindow();

private slots:
    void on_ADD_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

    void on_DELETE_MATRICULE_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pdf_clicked();

    void on_recherche_clicked();

    void on_sendMessageButton_clicked();

    void on_trier_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_tabBarClicked(int index);


private:

    Ui::VehicleWindow *ui;
    Vehicule Vb;
    QChartView *m_pieChartView; // new member variable for chart
};

#endif // VEHICLEWINDOW_H
