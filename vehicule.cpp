#include "vehicule.h"
#include <QString>
#include <QDebug>
#include <QSqlError>
Vehicule::Vehicule(){

};

Vehicule::Vehicule(QString m ,QString t ,QString e,int c){
    this->matricule = m;
    this->type = t;
    this->equipement = e;
    this->carburant = c;
}
bool Vehicule::ajouter(){
    QSqlQuery q;
    QString res = QString::number(carburant);
    q.prepare("insert into vehicule (matricule,type,carburant,equipement ) " "values(:matricule,:type,:carburant,:equipement)");

    q.bindValue(":matricule",matricule);
    q.bindValue(":type",type);
    q.bindValue(":equipement",equipement);
    q.bindValue(":carburant",res);

    return q.exec();
}


bool Vehicule::update(){
    QSqlQuery q;
    QString res = QString::number(carburant);
    q.prepare("UPDATE VEHICULE SET  type =:type ,equipement =:equipement , carburant =:carburant where matricule =:matricule" );

    q.bindValue(":matricule",matricule);
    q.bindValue(":type",type);
    q.bindValue(":equipement",equipement);
    q.bindValue(":carburant",res);

    return q.exec();
}

bool Vehicule::supprimer(QString matricule){
    QSqlQuery query;
    query.prepare("delete from vehicule where matricule= :matricule");
    query.bindValue(":matricule",matricule);

    return query.exec();
}


QSqlQueryModel * Vehicule::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select matricule,type,carburant,equipement  from Vehicule");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("carburant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("EQUIPEMENT"));
    return model;
}

QSqlQueryModel * Vehicule::search(QString searchQuery){
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;

    // Bind the search query to the prepared statement
    query.prepare("SELECT * FROM VEHICULE WHERE MATRICULE LIKE '%' || :searchQuery || '%' "
                  "OR TYPE LIKE '%' || :searchQuery || '%' "
                  "OR CARBURANT LIKE '%' || :searchQuery || '%'"
                  "OR EQUIPEMENT LIKE '%' || :searchQuery || '%';");
    query.bindValue(":searchQuery", searchQuery);

    if (!query.exec())
    {
        qWarning() << "Query error: " << query.lastError().text();
        return model;
    }

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("carburant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("EQUIPEMENT"));
    return model;
}

QSqlQueryModel * Vehicule::tri_matricule()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM VEHICULE ORDER BY MATRICULE ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("carburant"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EQUIPEMENT"));

        return model;
}
