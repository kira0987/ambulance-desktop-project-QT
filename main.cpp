#include "mainwindow.h"
#include "vehiclewindow.h"
#include <QFile>
#include <QApplication>
#include <QtWidgets>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Ok to continue."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




    w.setAttribute(Qt::WA_TranslucentBackground);
    //w.setWindowFlags( Qt::FramelessWindowHint);
    w.show();
    return app.exec();
}
