#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Vehicule
{
    QString matricule,type,equipement;
    int carburant;
public:
    Vehicule();
    Vehicule(QString,QString,QString,int);

    QString getMatricule();
    QString getType();
    QString getCarburant();

    void setMatricule(QString m){matricule = m;};
    void setType(QString t){type = t;};
    void setCarburant(int c){carburant = c;};

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_matricule();
    QSqlQueryModel * search(QString searchQuery);
    bool supprimer(QString);
    bool update();
};

#endif // VEHICULE_H
