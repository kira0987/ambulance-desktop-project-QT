#include "vehiclewindow.h"
#include "ui_vehiclewindow.h"
#include "vehicule.h"
#include <QMessageBox>
#include <QPainter>
#include "hospital_view.h"
#include <QPixmap>
#include <QApplication>
#include <QTextDocument>
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QIntValidator>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPageLayout>
#include <QPageSize>
#include <QtCharts/QPieSeries>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QChartView>
#include <QtSql/QSqlQueryModel>
#include <QtCharts/QChart>
#include <QtPrintSupport/QPrinter>
#include <QDateEdit>
#include <QDateTime>
#include <QDate>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>



VehicleWindow::VehicleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VehicleWindow)
{

    ui->setupUi(this);
    ui->tableView->setModel(Vb.afficher());
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

}
VehicleWindow::~VehicleWindow()
{
    //delete ui;
}



void VehicleWindow::on_ADD_clicked()
{
    int carburant=ui->lineEdit_carburant->text().toInt();
    QString matricule=ui->lineEdit_matricule->text();
    QString type=ui->lineEdit_type->text();
    QString equipement=ui->lineEdit_equipement->text();

    Vehicule V(matricule,type,equipement,carburant);
    bool test = V.ajouter();
    ui->tableView->setModel(Vb.afficher());
    if(test)
    {
        ui->tableView->setModel(Vb.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Ok to continue."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





void VehicleWindow::on_updateButton_clicked()
{
    int carburant=ui->lineEdit_carburant->text().toInt();
    QString matricule=ui->lineEdit_matricule->text();
    QString type=ui->lineEdit_type->text();
    QString equipement=ui->lineEdit_equipement->text();

    Vehicule V(matricule,type,equipement,carburant);
    bool test = V.update();
    ui->tableView->setModel(Vb.afficher());
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("UPDATE"),
                    QObject::tr("UPDATE successful.\n"
                                "Click Ok to continue."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("OBJECT ALREADY IN DATABASE"),
                    QObject::tr("UPDATE failed.\n "), QMessageBox::Ok);
}


void VehicleWindow::on_deleteButton_clicked()
{

}





void VehicleWindow::on_DELETE_MATRICULE_clicked()
{
   QString matricule=ui->lineEdit_matricule->text();



    if(Vb.supprimer(matricule))
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("Supprimer !."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("n'est pas supprimer"), QMessageBox::Ok);
ui->tableView->setModel(Vb.afficher());
}


void VehicleWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
           QString cellText = index.data().toString();
       }
}




void VehicleWindow::on_pdf_clicked()
{
       QString strStream;
       QTextStream out(&strStream);
       QString logoPath = ":/img/rapidrescue-logos.jpeg";
       const int rowCount = ui->tableView->model()->rowCount();
       const int columnCount = ui->tableView->model()->columnCount();

       out <<  "<html>\n"
              "<head>\n"
              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           <<  QString("<title>%1</title>\n").arg("strTitle")
           <<"<style>\n"
              "body { font-family: Arial, sans-serif; font-size: 12px; color: #333; margin: 0; padding: 0; }\n"
              "table { border-collapse: collapse; width: 100%; }\n"
              "  th, td { border: 1px solid black; padding: 5px; }\n"
              "  td { vertical-align: top; }\n"
              "th { background-color: #f0f0f0; }\n"
              "tr:nth-child(even) { background-color: #f2f2f2; }\n"
              "h1 { font-size: 18px; text-align: center; }\n"
              "img { max-width: 150px; height: auto; }\n"
              "</style>\n"
              "<title>Liste Des Vehicules</title>\n"
           "</head>\n"
              "<body bgcolor=#ffffff link=#5000A0>\n"
              "<img src=\"" << logoPath << "\" alt=\"Company Logo\" height=\"100\" width=\"100\">\n" // insert your logo here
              //     "<align='right'> " << datefich << "</align>"
              "<center> <H1>Liste Des Vehicules </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

       // headers
       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
           if (!ui->tableView->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++)
       {
           out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
           for (int column = 0; column < columnCount; column++)
           {
               if (!ui->tableView->isColumnHidden(column))
               {
                   QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table> </center>\n"
              "</body>\n"
              "</html>\n";

       QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
       {
           fileName.append(".pdf");
       }
       QTextDocument doc;
       doc.setHtml(strStream);

       // create a QPrinter object and set its properties
       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName(fileName);

       // print the QTextDocument to the QPrinter
       doc.print(&printer);
       QMessageBox::information(this,"Exporter en PDF","Exporter En PDF Avec Succées ");
}


void VehicleWindow::on_recherche_clicked()
{
       Vehicule H;
       QString searchQuery = ui->search->text();
       QSqlQueryModel* searchResults = H.search(searchQuery);

       // Display the search results in a table view
       ui->tableView->setModel(searchResults);
}


void VehicleWindow::on_sendMessageButton_clicked()
{
        QString message = ui->textEdit_message->toPlainText();
        QString number = ui->lineEdit_number->text();


        QNetworkAccessManager* manager = new QNetworkAccessManager();

        QUrl url("https://rest.nexmo.com/sms/json");

        QUrlQuery params;
        params.addQueryItem("from", "RapidRescue");
        params.addQueryItem("text", "Phone number"+number+" ->"+message);
        params.addQueryItem("to", "+21621700434");
        params.addQueryItem("api_key", "bca0ed31");
        params.addQueryItem("api_secret", "ksY1EA94ATfaXu5y");

        QByteArray postData = params.toString(QUrl::FullyEncoded).toUtf8();

        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QNetworkReply* reply = manager->post(request, postData);

        QObject::connect(reply, &QNetworkReply::finished, [=]() {
            QByteArray response = reply->readAll();
            qDebug() << "Response: " << response;
            reply->deleteLater();
            manager->deleteLater();
        });
}


void VehicleWindow::on_trier_clicked()
{
        Vehicule H;
        QSqlQueryModel *model = H.tri_matricule();
        bool test=model;
        QMessageBox msgBox;
        if(test)
           msgBox.setText("tri avec succés.");
               else
               msgBox.setText("Echec de la tri.");
        qDebug()<<test;

        ui->tableView->setModel(model);
}


void VehicleWindow::on_tabWidget_currentChanged(int index)
{
        // Create a new QChart object
        QChart *chart = new QChart();

        // Create a new QPieSeries object
        QPieSeries *series = new QPieSeries();
        // Set the animation options for the series
        // Set animation options for the chart
        chart->setTitle("Type de Vehicule");
        chart->setAnimationOptions(QChart::AllAnimations);
        // Fetch the vehicle types from the database (assuming they are stored in a table named "vehicle_types")
        QSqlQuery query("SELECT DISTINCT type FROM VEHICULE");
        while (query.next()) {
               QString type = query.value(0).toString();
               // Count the number of vehicles of each type in the VEHICULE table
               QSqlQuery count_query;
               count_query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE type = ?");
               count_query.addBindValue(type);
               count_query.exec();
               count_query.first();
               int count = count_query.value(0).toInt();
               // Add a new slice to the pie chart for each vehicle type
               series->append(type, count);
        }

        // Add the series to the chart
        chart->addSeries(series);

        // Create a new QChartView object with the chart
        QChartView *chartView = new QChartView(chart);

        // Set the chart view's parent to the PieChart widget
        chartView->setParent(ui->PieChart);

        // Set the chart view's geometry to fill the PieChart widget
        chartView->setGeometry(ui->PieChart->geometry());
}


void VehicleWindow::on_tabWidget_tabBarClicked(int index)
{
        // Create a new QChart object
        QChart *chart = new QChart();

        // Create a new QPieSeries object
        QPieSeries *series = new QPieSeries();
        // Set the animation options for the series
        // Set animation options for the chart
        chart->setTitle("Type de Vehicule");
        chart->setAnimationOptions(QChart::AllAnimations);
        // Fetch the vehicle types from the database (assuming they are stored in a table named "vehicle_types")
        QSqlQuery query("SELECT DISTINCT type FROM VEHICULE");
        while (query.next()) {
               QString type = query.value(0).toString();
               // Count the number of vehicles of each type in the VEHICULE table
               QSqlQuery count_query;
               count_query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE type = ?");
               count_query.addBindValue(type);
               count_query.exec();
               count_query.first();
               int count = count_query.value(0).toInt();
               // Add a new slice to the pie chart for each vehicle type
               series->append(type, count);
        }

        // Add the series to the chart
        chart->addSeries(series);

        // Create a new QChartView object with the chart
        QChartView *chartView = new QChartView(chart);

        // Set the chart view's parent to the PieChart widget
        chartView->setParent(ui->PieChart);

        // Set the chart view's geometry to fill the PieChart widget
        chartView->setGeometry(ui->PieChart->geometry());
}



