#include "hospital_view.h"
#include "ui_hospital_view.h"
#include "mainwindow.h"
#include "qtextdocument.h"
#include "ui_mainwindow.h"
#include "hopital.h"
#include <QPixmap>
#include <QApplication>
#include <QTextDocument>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "arduino.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;
#include <iostream>
#include "connection.h"
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
hospital_view::hospital_view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hospital_view)
{
    ui->setupUi(this);
    this->resize(1480, 950);
ui->tableView->setModel(H.afficher());
    showStatistics();
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
}

hospital_view::~hospital_view()
{
    delete ui;
}

void hospital_view::on_ADD_clicked()
{
    int id =0;

     QString nom =ui->NOM->text();
     QString Adresse =ui->ADRESS->text();
     int NumTel =ui->PHONE->text().toInt();
     QString Speciality = "";
     if (ui->checkBox->isChecked())
         Speciality += ui->checkBox->text() + ", ";
     if (ui->checkBox_2->isChecked())
         Speciality += ui->checkBox_2->text() + ", ";
     if (ui->checkBox_3->isChecked())
         Speciality += ui->checkBox_3->text() + ", ";
     if (ui->checkBox_4->isChecked())
         Speciality += ui->checkBox_4->text() + ", ";
     if (ui->checkBox_5->isChecked())
         Speciality += ui->checkBox_5->text() + ", ";

     if (!Speciality.isEmpty())
         Speciality.chop(2);
     float NbrInTheHospital =ui->NB_HOPITAL->text().toFloat();
     float Capacity =ui->CAPACITY->text().toFloat();
     QString dateString = ui->CREATION->text();
     QDate Date = QDate::fromString(dateString, "dd/MM/yyyy");
     QString errorMessage;
    QString NumTelStr = QString::number(ui->PHONE->text().toInt());

    qDebug() << "id: " << id;
    qDebug() << "nom: " << nom;
    qDebug() << "adresse: " << Adresse;
    qDebug() << "numTel: " << NumTel;
    qDebug() << "speciality: " << Speciality;
    qDebug() << "nbrInTheHospital: " << NbrInTheHospital;
    qDebug() << "capacity: " << Capacity;
    qDebug() << "numTelStr: " << NumTelStr;
    qDebug() << "date: " << Date;
     if (nom.isEmpty() || Adresse.isEmpty() || NumTel<=0 ||
             Speciality.isEmpty() || NbrInTheHospital <= 0 || Capacity <= 0 ||!Date.isValid()) {
         errorMessage = "Veuillez remplir tous les champs.";
     } else {

          if (Capacity > 1000)
         {
             errorMessage = "La capacité doit être inférieure ou égale à 1000.";
         }
         else if (NbrInTheHospital > Capacity) {
             errorMessage = "Le nombre dans l'hôpital ne doit pas dépasser la capacité.";
         }
          else if (NumTelStr.length() != 8) {
             errorMessage = "le numéro de téléphone contient 8 numéros";
          }
     }

     // Si une erreur a été détectée, afficher un message d'erreur et ne pas ajouter l'élément
     if (!errorMessage.isEmpty()) {
         QMessageBox::critical(this, "Erreur", errorMessage);
         return;
     }

    HOPITAL H(id,nom,Adresse,NumTel,Speciality,NbrInTheHospital,Capacity,Date);

    bool test=H.Ajouter();
ui->tableView->setModel(H.afficher());
QMessageBox msgBox;
if(test)
    msgBox.setText("Ajout avec succés.");
else
  msgBox.setText("Echec de l'Ajout.");
 msgBox.exec();
qDebug()<<test;
}


void hospital_view::on_SHOW_clicked()
{
    HOPITAL H;
    ui->tableView->setModel(H.afficher());
}


void hospital_view::on_reset_2_clicked()
{
    HOPITAL H;
    H.reset();
    bool test=H.reset();
    ui->tableView->setModel(H.afficher());
    QMessageBox msgBox;
    if(test)
        msgBox.setText("reset avec succés.");
    else
      msgBox.setText("Echec de Reset.");
     msgBox.exec();
     qDebug()<<test;

}


void hospital_view::on_suppression_clicked()
{
    HOPITAL H;
    H.setid(ui->ID_DELETE->text().toInt());

    QString errorMessage;
    int id = H.get_id();
    if (!H.id_existe(id)) {
        errorMessage = "L'ID n'existe pas.";
    }
    if (!errorMessage.isEmpty()) {
        QMessageBox::critical(this, "Erreur", errorMessage);
        return;
    }

    bool test = H.Supprime(id);

    ui->tableView->setModel(H.afficher());
    QMessageBox msgBox;
    if (test) {
        msgBox.setText("Suppression avec succès.");
    } else {
        msgBox.setText("Echec de Suppression.");
    }
    msgBox.exec();
    qDebug() << test;
}


void hospital_view::on_MODIFY_clicked()
{
    int id = ui->ID_M->text().toInt();
    QString nom = ui->NOM->text();
    QString adresse = ui->ADRESS->text();
    int numTel = ui->PHONE->text().toInt();
    QString speciality = "";
    if (ui->checkBox->isChecked())
        speciality += ui->checkBox->text() + ", ";
    if (ui->checkBox_2->isChecked())
        speciality += ui->checkBox_2->text() + ", ";
    if (ui->checkBox_3->isChecked())
        speciality += ui->checkBox_3->text() + ", ";
    if (ui->checkBox_4->isChecked())
        speciality += ui->checkBox_4->text() + ", ";
    if (ui->checkBox_5->isChecked())
        speciality += ui->checkBox_5->text() + ", ";
    if (!speciality.isEmpty())
        speciality.chop(2);
    float nbrInTheHospital = ui->NB_HOPITAL->text().toFloat();
    float capacity = ui->CAPACITY->text().toFloat();
    QString dateString = ui->CREATION->text();
    QDate Date = QDate::fromString(dateString, "dd/MM/yyyy");
    QString errorMessage;
    QString numTelStr = QString::number(numTel);

    qDebug() << "id: " << id;
    qDebug() << "nom: " << nom;
    qDebug() << "adresse: " << adresse;
    qDebug() << "numTel: " << numTel;
    qDebug() << "speciality: " << speciality;
    qDebug() << "nbrInTheHospital: " << nbrInTheHospital;
    qDebug() << "capacity: " << capacity;
    qDebug() << "numTelStr: " << numTelStr;

    if (!H.id_existe(id)) {
        errorMessage = "L'ID n'existe pas.";
    } else if ( nom.isEmpty() || adresse.isEmpty() || numTel <= 0 || speciality.isEmpty() || nbrInTheHospital <= 0 || capacity <= 0||!Date.isValid()) {
        errorMessage = "Veuillez remplir tous les champs.";
    } else if (capacity > 1000) {
        errorMessage = "La capacité doit être inférieure ou égale à 1000.";
    } else if (nbrInTheHospital > capacity) {
        errorMessage = "Le nombre dans l'hôpital ne doit pas dépasser la capacité.";
    } else if (numTelStr.length() != 8) {
        errorMessage = "Le numéro de téléphone doit contenir 8 chiffres.";
    }

    qDebug() << "errorMessage: " << errorMessage;

    if (!errorMessage.isEmpty()) {
        QMessageBox::critical(this, "Erreur", errorMessage);
        return;
    }

    HOPITAL H(id, nom, adresse, numTel, speciality, nbrInTheHospital, capacity, Date);
    bool test = H.modifier(id);
    ui->tableView->setModel(H.afficher());
    QMessageBox msgBox;
    if(test )
        msgBox.setText("modification avec succés.");
    else
        msgBox.setText("Echec de la modification.");
    msgBox.exec();
    qDebug() << "test: " << test;
}


void hospital_view::on_tri_id_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_id();
    bool test=model;
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_nom_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_nom();
    bool test=model;
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_phone_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_phone();
    bool test=model;
    QMessageBox msgBox;

        msgBox.setText("phone sorted.");

    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_adresse_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_adresse();
    bool test=model;
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_capacity_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_capacity();
    bool test=H.tri_capacity();
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_speciality_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_speciality();
    bool test=model;
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_nbr_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_nbr();
    bool test=model;
    QMessageBox msgBox;
    if(test)
        msgBox.setText("tri avec succés.");
    else
      msgBox.setText("Echec de la tri.");
    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_tri_date_clicked()
{
    HOPITAL H;
    QSqlQueryModel *model = H.tri_date();
    bool test=model;
    QMessageBox msgBox;

        msgBox.setText("date sorted.");

    qDebug()<<test;

        ui->tableView->setModel(model);
}


void hospital_view::on_PDF_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
                "<img src=\"file:///C:/Users/houssam/Desktop/project github c++/project/rapidrescue-logos.jpeg\" alt=\"Logo\" width=\"100\" height=\"100\">\n"


            //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Liste Des HOPITAUX </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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


void hospital_view::on_calendar_clicked()
{
    H.displayCertificationCeremonyCalendar();
}


void hospital_view::on_EXCEL_clicked()
{
    QTableView *table = ui->tableView;

    QString filters("Excel files (*.xlsx);;CSV files (*.csv)");
    QString defaultFilter("Excel files (*.xlsx)");
    QString fileName = QFileDialog::getSaveFileName(
        0, "Save file", QCoreApplication::applicationDirPath(), filters, &defaultFilter);
    QFile file(fileName);

    QAbstractItemModel *model = table->model();

    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QXlsx::Document xlsx;
xlsx.write("I1", "pourcentage des patients");
        // Write headers
        for (int column = 0; column < model->columnCount(); column++) {
            if (!table->isColumnHidden(column)) {
                QString header = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
                xlsx.write(1, column + 1, header);
            }
        }

        // Write data
        for (int row = 0; row < model->rowCount(); row++) {
            int current_row = row + 2;
            for (int column = 0; column < model->columnCount(); column++) {
                if (!table->isColumnHidden(column)) {
                    QModelIndex index = model->index(row, column);
                    QString data = model->data(index, Qt::DisplayRole).toString();
                    xlsx.write(current_row, column + 1, data);
                }
            }

            // Calculate and write percentage
            QModelIndex index_patients = model->index(row, 5); // index of the column "NBR_DE_PATIENTS_ADMIS"
            QModelIndex index_capacity = model->index(row, 6); // index of the column "CAPACITY"
            int patients = model->data(index_patients, Qt::DisplayRole).toInt();
            int capacity = model->data(index_capacity, Qt::DisplayRole).toInt();
            double percentage = (double)patients / (double)capacity * 100;
            xlsx.write(current_row, 9, QString::number(percentage, 'f', 2) + "%");
        }

        // Auto-fit columns
        for (int column = 0; column < model->columnCount(); column++) {
            if (!table->isColumnHidden(column)) {
                xlsx.setColumnWidth(column + 1, xlsx.columnWidth(column + 1) * 3);
            }
        }
        // Calculate and write additional data
        int total_patients = 0;
        int total_capacity = 0;
        for (int row = 0; row < model->rowCount(); row++) {
            QModelIndex index_patients = model->index(row, 5); // index of the column "NBR_DE_PATIENTS_ADMIS"
            QModelIndex index_capacity = model->index(row, 6); // index of the column "CAPACITY"
            int patients = model->data(index_patients, Qt::DisplayRole).toInt();
            int capacity = model->data(index_capacity, Qt::DisplayRole).toInt();
            total_patients += patients;
            total_capacity += capacity;
        }

        xlsx.write(model->rowCount() + 4, 5, "Total Patients:");
        xlsx.write(model->rowCount() + 4, 6, total_patients);

        xlsx.write(model->rowCount() + 5, 5, "Total Capacity:");
        xlsx.write(model->rowCount() + 5, 6, total_capacity);

        // Write total rate
        double total_rate = (double)total_patients / (double)total_capacity;
        xlsx.write(model->rowCount() + 6, 5, "pourcentage de nombre de  patients par rapport à la capacité:");
        xlsx.write(model->rowCount() + 6, 6, QString::number(total_rate * 100, 'f', 2) + "%");
        // Save file
        xlsx.saveAs(&file);
        file.close();

        QMessageBox::information(this, "Exporter en Excel", "Exportation En Excel Avec Succès");
    }
}

void hospital_view::on_SEARCH_2_clicked()
{
    HOPITAL H;
    QString searchQuery = ui->SEARCH->text();
    QSqlQueryModel* searchResults = H.recherche(searchQuery);

    // Display the search results in a table view
    ui->tableView->setModel(searchResults);
}

void hospital_view::showStatistics()
{
    QPieSeries* specialty_series = generateSpecialitiesData();


    QChart* specialty_chart = new QChart();
    specialty_chart->addSeries(specialty_series);
    specialty_chart->setTitle("<b>Percentage des spécialités dans tous les Hopitaux</b>");
    specialty_chart->legend()->setAlignment(Qt::AlignRight);



    QChartView* specialty_view = new QChartView(specialty_chart);


    // Get a reference to the second tab's QWidget
    QWidget* secondTabWidget = ui->tabWidget->widget(1);

    QLayout *existingLayout = secondTabWidget->layout();
    if (existingLayout)
    {
        delete existingLayout;
    }

    // Set your QVBoxLayout as the new layout for the second tab's QWidget
    QVBoxLayout* layout = new QVBoxLayout(secondTabWidget);
    layout->addWidget(specialty_view);

}



QPieSeries *hospital_view::generateSpecialitiesData()
{
    QSqlQuery query;
    QPieSeries *series = new QPieSeries();

    QStringList specialties = {"Cardiologie", "neurologie", "pneumologie", "Anesthesiologie", "orthopediatrie"};
    QVector<QColor> colors = {Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan};

    // Calculate total count
    int totalCount = 0;
    for (int i = 0; i < specialties.size(); ++i) {
        QString queryStr = "SELECT COUNT(*) FROM HOPITAL WHERE SPECIALTIES LIKE '%" + specialties[i] + "%'";
        query.exec(queryStr);
        query.next();
        int count = query.value(0).toInt();
        totalCount += count;
    }

    // Calculate percentages
    for (int i = 0; i < specialties.size(); ++i) {
        QString queryStr = "SELECT COUNT(*) FROM HOPITAL WHERE SPECIALTIES LIKE '%" + specialties[i] + "%'";
        query.exec(queryStr);
        query.next();
        int count = query.value(0).toInt();
        double percentage = totalCount > 0 ? static_cast<double>(count) / totalCount * 100.0 : 0.0;

        QPieSlice *slice = new QPieSlice(specialties[i], percentage);
        slice->setLabel(QString("<b>%1 (%2%)</b>").arg(specialties[i]).arg(percentage, 0, 'g', 2));
        slice->setBrush(colors[i]);
        series->append(slice);
    }

    return series;
}


void hospital_view::on_ON_clicked()
{
    A.write_to_arduino("1");
}


void hospital_view::on_OFF_clicked()
{
     A.write_to_arduino("0");
}


void hospital_view::update_label()
{
<<<<<<< HEAD
     // Set the initial status of all vehicles to "en urgence"
     QSqlQuery query;


     // Read data from Arduino
     data = A.read_from_arduino();
     qDebug() << "data: " << data;

     // Extract tag ID from the data
     QRegularExpression re("t:(\\d+\\.\\d+\\.\\d+\\.\\d+)");
     QRegularExpressionMatch match = re.match(data);
     QString tagId = match.captured(1);
     qDebug() << "Tag ID is: " << tagId;

     if (match.hasMatch()) {
        QString tag = tagId;
        //QSqlQuery query;
        query.prepare("SELECT * FROM VEHICULE WHERE RFID =:tagid ");
        query.bindValue(":tagid", tag);
        query.exec();

        // If a result is found, update the status to "en repos" and send "1" to Arduino
        if (query.next()) {
            qDebug() << "Tag ID found in database!";
            query.prepare("UPDATE VEHICULE SET STATUS = 'en repos' WHERE RFID =:rfid");
            query.bindValue(":rfid", tag);
            query.exec();
            A.write_to_arduino("1");
        } else {

            qWarning() << "Tag ID not found in database.";
            //A.write_to_arduino("0");

        }

        // Get the matricule for the detected RFID
        query.prepare("SELECT MATRICULE FROM VEHICULE WHERE RFID =:tagid ");
        query.bindValue(":tagid", tag);
        QString matricule;
        if (query.exec() && query.next()) {
            matricule = query.value(0).toString();
        }

        query.prepare("SELECT STATUS FROM VEHICULE WHERE RFID =:tagid ");
        query.bindValue(":tagid", tag);
        QString etat;
        if (query.exec() && query.next()) {
            etat = query.value(0).toString();
        }

        // Update the UI labels
        ui->etat->setText(etat);
        ui->label_3->setText("ON");
        ui->labeltag->setText("Matricule: "+matricule);
        ui->autreetat->setText("Passed");
        qDebug() << "Tag ID is: " << tagId;
     } else {
        ui->labeltag->setText("Matricule: code incorrect");
        ui->label_3->setText("OFF");
        ui->autreetat->setText("Not Passed");
        qWarning() << "No tag ID found in serial data.";
     }
=======
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
>>>>>>> parent of 179d153 ( ARDUINO 98%)
}

void hospital_view::on_tabWidget_currentChanged(int index)
{
    showStatistics();
}

