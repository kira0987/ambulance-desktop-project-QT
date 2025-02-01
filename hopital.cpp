#include "hopital.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "connection.h"
#include <QDateEdit>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;
HOPITAL::HOPITAL()
{
    id=0;
    nom="";
    Adresse="";
    NumTel=0;
    Speciality="";
    NbrInTheHospital=0;
    Capacity=0;

}
HOPITAL::HOPITAL(int id,QString nom,QString Adresse,int NumTel,QString Speciality,float NbrInTheHospital,float Capacity,QDate Date)
{
    this->id=id;
    this->nom=nom;
    this->Adresse=Adresse;
    this->NumTel=NumTel;
    this->Speciality=Speciality;
    this->NbrInTheHospital=NbrInTheHospital;
    this->Capacity=Capacity;
    this-> Date=Date;

}
int HOPITAL::get_id()
{
    return id;
}

QString HOPITAL::get_Adress()
{
    return Adresse;
}
int HOPITAL::get_NumTel()
{
    return NumTel;
}
QString HOPITAL::get_Speciality()
{
    return Speciality;
}
float HOPITAL::get_NbrInTheHospital()
{
    return NbrInTheHospital;
}
float HOPITAL::get_Capacity()
{
    return Capacity;
}
QDate HOPITAL::get_Date()
{
    return Date;
}


void HOPITAL::setid(int id)
{
    this->id=id;
}
void HOPITAL::setnom(QString n)
{
this->nom=n;
}

void HOPITAL::setAdress(QString n)
{
    this->Adresse=n;
}
void HOPITAL::setNumTel(int n)
{
    this->NumTel=n;
}
void HOPITAL::setSpeciality(QString n)
{
    this->Speciality=n;
}
void HOPITAL::setNbrInTheHospital(float n)
{
    this->NbrInTheHospital=n;
}
void HOPITAL::setCapacity(float n)
{
    this->Capacity=n;
}
void HOPITAL::setDate(QDate n)
{
    this->Date=n;
}

bool HOPITAL::Ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString NumTel_string=QString::number(NumTel);
    QString NbrInTheHospital_string=QString::number(NbrInTheHospital);
    QString Capacity_string=QString::number(Capacity);



         query.prepare("INSERT INTO HOPITAL(ID_HOPITAL,NOM_HOPITAL,ADRESS,PHONE_NUMBER,SPECIALTIES,NBR_DE_PATIENTS_ADMIS,CAPACITY,DATE_HOPITAL) VALUES (:id,:nom,:Adresse,:NumTel,:Speciality,:NbrInTheHospital,:Capacity,:Date)");
         query.bindValue(":id",id_string);
         query.bindValue(":nom",nom);
         query.bindValue(":Adresse", Adresse);
          query.bindValue(":NumTel",NumTel_string);
          query.bindValue(":Speciality", Speciality);
          query.bindValue(":NbrInTheHospital", NbrInTheHospital_string);
          query.bindValue(":Capacity", Capacity_string);
          query.bindValue(":Date", Date);

      return query.exec();


}
QSqlQueryModel *HOPITAL::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));

        return model;
}
bool HOPITAL::Supprime(int id)
{
   QSqlQuery query;
        query.prepare("delete from HOPITAL where ID_HOPITAL=:id");
        query.bindValue(0, id);
     return query.exec();
}
bool HOPITAL::reset()
{
    QSqlQuery query;
         query.prepare("delete from HOPITAL");
         query.bindValue(0, id);
      return query.exec();
}
bool HOPITAL::modifier(int id)
{

QSqlQuery query;

QString id_string=QString::number(id);
QString NumTel_string=QString::number(NumTel);
QString NbrInTheHospital_string=QString::number(NbrInTheHospital);
QString Capacity_string=QString::number(Capacity);


query.prepare("UPDATE HOPITAL SET ID_HOPITAL=:id,NOM_HOPITAL=:nom,ADRESS=:Adresse,PHONE_NUMBER=:NumTel,SPECIALTIES=:Speciality,NBR_DE_PATIENTS_ADMIS=:NbrInTheHospital,CAPACITY=:Capacity,DATE_HOPITAL=:Date WHERE ID_HOPITAL=:id;");

query.bindValue(":id",id_string);
query.bindValue(":nom",nom);
query.bindValue(":Adresse", Adresse);
 query.bindValue(":NumTel",NumTel_string);
 query.bindValue(":Speciality", Speciality);
 query.bindValue(":NbrInTheHospital", NbrInTheHospital_string);
 query.bindValue(":Capacity", Capacity_string);
 query.bindValue(":Date", Date);

return    query.exec();
}



QSqlQueryModel *HOPITAL::tri_id()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY ID_HOPITAL ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}

QSqlQueryModel *HOPITAL::tri_nom()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY NOM_HOPITAL ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}
QSqlQueryModel *HOPITAL::tri_adresse()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY ADRESS ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}
QSqlQueryModel *HOPITAL::tri_phone()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY PHONE_NUMBER ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}
QSqlQueryModel *HOPITAL::tri_speciality()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY SPECIALTIES ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}
QSqlQueryModel *HOPITAL::tri_nbr()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY NBR_DE_PATIENTS_ADMIS ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}
QSqlQueryModel *HOPITAL::tri_capacity()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY CAPACITY ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}

QSqlQueryModel *HOPITAL::tri_date()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM HOPITAL ORDER BY DATE_HOPITAL ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));
        return model;
}

QSqlQueryModel* HOPITAL::recherche(QString searchQuery)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    QDate date;
    if (QDate::fromString(searchQuery, "yyyy-MM-dd").isValid()) {
        date = QDate::fromString(searchQuery, "yyyy-MM-dd");
    } // Convert the search query to a QDate object

    // Bind the search query to the prepared statement
    query.prepare("SELECT * FROM HOPITAL WHERE NOM_HOPITAL LIKE '%' || :searchQuery || '%' "
                  "OR ADRESS LIKE '%' || :searchQuery || '%' "
                  "OR SPECIALTIES LIKE '%' || :searchQuery || '%'"
                  "OR PHONE_NUMBER LIKE '%' || :searchQuery || '%'"
                  "OR CAPACITY LIKE '%' || :searchQuery || '%'"
                  "OR NBR_DE_PATIENTS_ADMIS LIKE '%' || :searchQuery || '%'"
                  "OR ID_HOPITAL LIKE '%' || :searchQuery || '%'"
                  "OR DATE_HOPITAL = :dateQuery;");
    query.bindValue(":searchQuery", searchQuery);
    query.bindValue(":dateQuery", date);


    if (!query.exec())
    {
        qWarning() << "Query error: " << query.lastError().text();
        return model;
    }

    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'hopital"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("N° Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Spécialités"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de patients dans l'hopital"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de création"));

    return model;
}

bool HOPITAL::id_existe(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_HOPITAL FROM HOPITAL WHERE ID_HOPITAL=:id");
    query.bindValue(":id", id);
    query.exec();
    return query.next();
}


void HOPITAL::displayCertificationCeremonyCalendar() {
    QInputDialog dialog;
    dialog.setWindowTitle("Sélectionnez un hôpital");
    dialog.setLabelText("Sélectionnez l'ID de l'hôpital pour afficher le calendrier d'invitation par les audits :");
    dialog.setInputMode(QInputDialog::IntInput);
    dialog.setIntRange(1, std::numeric_limits<int>::max());

    int hospitalId = 0;
    if (dialog.exec() == QDialog::Accepted) {
        hospitalId = dialog.intValue();
    } else {
        return; // user canceled input
    }

    QDate currentDate = QDate::currentDate().addDays(3); // set current date + 3 days

    QSqlQuery query;
    query.prepare("SELECT ID_HOPITAL, NOM_HOPITAL, NBR_DE_PATIENTS_ADMIS, CAPACITY FROM HOPITAL WHERE ID_HOPITAL = :hospitalId AND NBR_DE_PATIENTS_ADMIS / CAPACITY > 0.8");
    query.bindValue(":hospitalId", hospitalId);
    query.exec();

    QString hospitalName;

    QDate certificationCeremonyDate;

    if (query.next()) {
           QString currentHospitalName = query.value(1).toString();
           hospitalName = currentHospitalName;
           certificationCeremonyDate = currentDate;
       } else {
           QMessageBox msgBox;
           msgBox.setWindowTitle("Hopital n'est pas invité");
           msgBox.setText("L'hôpital n'est pas invité car son taux d'occupation est inférieur à 80%.");
           msgBox.exec();
           return;
       }



    // display calendar for the selected hospital
    if (!hospitalName.isEmpty()) {
        QCalendarWidget *calendar = new QCalendarWidget();
        calendar->setWindowTitle("L'évenement d'audit a invité l'hopital :  " + hospitalName);
        calendar->setMinimumDate(certificationCeremonyDate);
        calendar->setMaximumDate(certificationCeremonyDate);
        calendar->setSelectedDate(certificationCeremonyDate);
        calendar->show();
    }
}
