#ifndef HOPITAL_H
#define HOPITAL_H
#include<QString>
#include <QList>
#include <QCheckBox>
#include<QStringList>
#include <QSqlQueryModel>
#include "connection.h"
#include <QDateEdit>
#include <QDateTime>
#include <QDate>
#include "qcustomplot.h"

class HOPITAL
{

public :
    void setid(int );
    void setnom(QString );
    void setAdress(QString );
    void setNumTel(int );
    void setSpeciality(QString );
    void setNbrInTheHospital(float );
    void setCapacity(float );
    void setDate(QDate );
   int get_id();
   QString get_nom();
   QString get_Adress();
   int get_NumTel();
   QString get_Speciality();
   float get_NbrInTheHospital();
   float get_Capacity();
   QDate get_Date();

   HOPITAL();
     HOPITAL(int,QString,QString,int,QString,float,float,QDate);
    bool modifier(int);
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
    bool reset();
    QSqlQueryModel* tri_id();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel* tri_adresse();
    QSqlQueryModel* tri_phone();
    QSqlQueryModel* tri_speciality();
    QSqlQueryModel* tri_nbr();
    QSqlQueryModel* tri_capacity();
    QSqlQueryModel* tri_date();
bool id_existe(int id);
    bool modifier(int,QString);
      QSqlQueryModel* recherche(QString);
void displayCertificationCeremonyCalendar();
private:
    QString nom,Adresse,Speciality;
    int id,NumTel;
   float NbrInTheHospital,Capacity;
   QDate Date;

};

#endif // HOPITAL_H
