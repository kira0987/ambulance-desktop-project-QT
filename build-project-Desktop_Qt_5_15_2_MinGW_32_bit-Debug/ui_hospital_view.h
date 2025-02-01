/********************************************************************************
** Form generated from reading UI file 'hospital_view.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOSPITAL_VIEW_H
#define UI_HOSPITAL_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_hospital_view
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *TRI_RECHERCHE_2;
    QGroupBox *groupBox_3;
    QPushButton *hopital_2;
    QPushButton *equippement_medical_2;
    QPushButton *urgence_2;
    QPushButton *equippage_2;
    QPushButton *vehicule_2;
    QPushButton *logout_2;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *ADRESS;
    QLineEdit *NOM;
    QLineEdit *CAPACITY;
    QLabel *label_23;
    QLabel *label_4;
    QFrame *line_11;
    QPushButton *ADD;
    QPushButton *reset_2;
    QLineEdit *NB_HOPITAL;
    QLabel *label_5;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QLabel *label_6;
    QLabel *label_28;
    QLineEdit *PHONE;
    QGroupBox *groupBox_17;
    QPushButton *tri_id;
    QPushButton *tri_nom;
    QPushButton *tri_adresse;
    QPushButton *tri_speciality;
    QPushButton *tri_nbr;
    QPushButton *tri_capacity;
    QPushButton *tri_date;
    QPushButton *tri_phone;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QTableView *tableView;
    QFrame *line_15;
    QFrame *line_16;
    QLabel *label_10;
    QLineEdit *ID_DELETE;
    QLabel *label_25;
    QPushButton *SHOW;
    QPushButton *MODIFY;
    QFrame *line_27;
    QGroupBox *groupBox_18;
    QPushButton *PDF;
    QPushButton *calendar;
    QPushButton *EXCEL;
    QGroupBox *groupBox_19;
    QLineEdit *SEARCH;
    QPushButton *SEARCH_2;
    QLabel *label_7;
    QLabel *label_37;
    QLabel *label;
    QPushButton *suppression;
    QDateEdit *CREATION;
    QLabel *label_26;
    QLineEdit *ID_M;
    QWidget *STATISTIQUES_2;
    QGroupBox *groupBox_9;
    QFrame *line_41;
    QCustomPlot *specialty_view;
    QCustomPlot *capacity_view;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hospital_view)
    {
        if (hospital_view->objectName().isEmpty())
            hospital_view->setObjectName(QString::fromUtf8("hospital_view"));
        hospital_view->resize(1296, 974);
        centralwidget = new QWidget(hospital_view);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1471, 921));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Arial Black\";\n"
"QWidget\n"
"{\n"
"background-color: #0f4264;\n"
"}\n"
"\n"
""));
        tabWidget->setTabBarAutoHide(true);
        TRI_RECHERCHE_2 = new QWidget();
        TRI_RECHERCHE_2->setObjectName(QString::fromUtf8("TRI_RECHERCHE_2"));
        groupBox_3 = new QGroupBox(TRI_RECHERCHE_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 1631, 1011));
        groupBox_3->setStyleSheet(QString::fromUtf8("color:rgb(0,0,0);\n"
"font: 900 9pt \"Arial Black\";\n"
"background-color: \"#0F4264\";\n"
"color: \"white\""));
        hopital_2 = new QPushButton(groupBox_3);
        hopital_2->setObjectName(QString::fromUtf8("hopital_2"));
        hopital_2->setGeometry(QRect(40, 200, 141, 61));
        hopital_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 224, 99);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/hospital.png"), QSize(), QIcon::Selected, QIcon::On);
        hopital_2->setIcon(icon);
        hopital_2->setIconSize(QSize(50, 50));
        equippement_medical_2 = new QPushButton(groupBox_3);
        equippement_medical_2->setObjectName(QString::fromUtf8("equippement_medical_2"));
        equippement_medical_2->setGeometry(QRect(40, 360, 141, 61));
        equippement_medical_2->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 34, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/first-aid-box.png"), QSize(), QIcon::Selected, QIcon::On);
        equippement_medical_2->setIcon(icon1);
        equippement_medical_2->setIconSize(QSize(50, 50));
        urgence_2 = new QPushButton(groupBox_3);
        urgence_2->setObjectName(QString::fromUtf8("urgence_2"));
        urgence_2->setGeometry(QRect(40, 440, 141, 61));
        urgence_2->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 255, 29);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/alarm.png"), QSize(), QIcon::Selected, QIcon::On);
        urgence_2->setIcon(icon2);
        urgence_2->setIconSize(QSize(50, 50));
        equippage_2 = new QPushButton(groupBox_3);
        equippage_2->setObjectName(QString::fromUtf8("equippage_2"));
        equippage_2->setGeometry(QRect(40, 520, 141, 61));
        equippage_2->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 219, 255);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/log-in.png"), QSize(), QIcon::Selected, QIcon::On);
        equippage_2->setIcon(icon3);
        equippage_2->setIconSize(QSize(50, 50));
        vehicule_2 = new QPushButton(groupBox_3);
        vehicule_2->setObjectName(QString::fromUtf8("vehicule_2"));
        vehicule_2->setGeometry(QRect(40, 280, 141, 61));
        vehicule_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 42, 237);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/ambulance.png"), QSize(), QIcon::Selected, QIcon::On);
        vehicule_2->setIcon(icon4);
        vehicule_2->setIconSize(QSize(50, 50));
        logout_2 = new QPushButton(groupBox_3);
        logout_2->setObjectName(QString::fromUtf8("logout_2"));
        logout_2->setGeometry(QRect(40, 600, 141, 61));
        logout_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/check-out.png"), QSize(), QIcon::Selected, QIcon::On);
        logout_2->setIcon(icon5);
        logout_2->setIconSize(QSize(50, 50));
        line_8 = new QFrame(groupBox_3);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(210, 20, 20, 881));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(groupBox_3);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(690, 20, 31, 881));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(groupBox_3);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(220, 900, 481, 16));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 120, 101, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        label_15->setFont(font);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(230, 160, 111, 16));
        label_17->setFont(font);
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(230, 240, 101, 16));
        label_19->setFont(font);
        ADRESS = new QLineEdit(groupBox_3);
        ADRESS->setObjectName(QString::fromUtf8("ADRESS"));
        ADRESS->setGeometry(QRect(360, 160, 161, 22));
        ADRESS->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        ADRESS->setReadOnly(false);
        NOM = new QLineEdit(groupBox_3);
        NOM->setObjectName(QString::fromUtf8("NOM"));
        NOM->setGeometry(QRect(330, 120, 161, 22));
        NOM->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        NOM->setReadOnly(false);
        CAPACITY = new QLineEdit(groupBox_3);
        CAPACITY->setObjectName(QString::fromUtf8("CAPACITY"));
        CAPACITY->setGeometry(QRect(350, 330, 81, 22));
        CAPACITY->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        CAPACITY->setReadOnly(false);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(230, 330, 91, 16));
        label_23->setFont(font);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 39, 121, 51));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 4);\n"
"font: 12pt \"Segoe UI\";\n"
"font: 14pt \"Arial Rounded MT Bold\";"));
        line_11 = new QFrame(groupBox_3);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(220, 100, 481, 16));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        ADD = new QPushButton(groupBox_3);
        ADD->setObjectName(QString::fromUtf8("ADD"));
        ADD->setGeometry(QRect(450, 30, 101, 71));
        ADD->setAutoFillBackground(false);
        ADD->setStyleSheet(QString::fromUtf8("color: rgb(149, 255, 243);\n"
"background-color: rgb(255, 255, 127);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/add-database.png"), QSize(), QIcon::Selected, QIcon::On);
        ADD->setIcon(icon6);
        ADD->setIconSize(QSize(80, 40));
        reset_2 = new QPushButton(groupBox_3);
        reset_2->setObjectName(QString::fromUtf8("reset_2"));
        reset_2->setGeometry(QRect(460, 440, 83, 71));
        reset_2->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 119, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/reset.png"), QSize(), QIcon::Selected, QIcon::On);
        reset_2->setIcon(icon7);
        reset_2->setIconSize(QSize(80, 60));
        NB_HOPITAL = new QLineEdit(groupBox_3);
        NB_HOPITAL->setObjectName(QString::fromUtf8("NB_HOPITAL"));
        NB_HOPITAL->setGeometry(QRect(550, 300, 81, 22));
        NB_HOPITAL->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        NB_HOPITAL->setReadOnly(false);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 60, 90, 90));
        label_5->setAutoFillBackground(false);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/hospital.png")));
        label_5->setScaledContents(true);
        line_12 = new QFrame(groupBox_3);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(60, 50, 91, 16));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(groupBox_3);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(60, 150, 91, 16));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(groupBox_3);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(60, 180, 91, 16));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 160, 81, 20));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(230, 200, 131, 16));
        label_28->setFont(font);
        PHONE = new QLineEdit(groupBox_3);
        PHONE->setObjectName(QString::fromUtf8("PHONE"));
        PHONE->setGeometry(QRect(360, 200, 161, 22));
        PHONE->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        PHONE->setMaxLength(99999999);
        PHONE->setReadOnly(false);
        groupBox_17 = new QGroupBox(groupBox_3);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(710, 380, 671, 91));
        groupBox_17->setFont(font);
        groupBox_17->setStyleSheet(QString::fromUtf8(""));
        tri_id = new QPushButton(groupBox_17);
        tri_id->setObjectName(QString::fromUtf8("tri_id"));
        tri_id->setGeometry(QRect(60, 10, 83, 29));
        tri_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_nom = new QPushButton(groupBox_17);
        tri_nom->setObjectName(QString::fromUtf8("tri_nom"));
        tri_nom->setGeometry(QRect(170, 10, 83, 29));
        tri_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_adresse = new QPushButton(groupBox_17);
        tri_adresse->setObjectName(QString::fromUtf8("tri_adresse"));
        tri_adresse->setGeometry(QRect(380, 10, 83, 29));
        tri_adresse->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_speciality = new QPushButton(groupBox_17);
        tri_speciality->setObjectName(QString::fromUtf8("tri_speciality"));
        tri_speciality->setGeometry(QRect(30, 50, 111, 29));
        tri_speciality->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_nbr = new QPushButton(groupBox_17);
        tri_nbr->setObjectName(QString::fromUtf8("tri_nbr"));
        tri_nbr->setGeometry(QRect(160, 50, 361, 29));
        tri_nbr->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_capacity = new QPushButton(groupBox_17);
        tri_capacity->setObjectName(QString::fromUtf8("tri_capacity"));
        tri_capacity->setGeometry(QRect(500, 10, 111, 29));
        tri_capacity->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_date = new QPushButton(groupBox_17);
        tri_date->setObjectName(QString::fromUtf8("tri_date"));
        tri_date->setGeometry(QRect(540, 50, 111, 29));
        tri_date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        tri_phone = new QPushButton(groupBox_17);
        tri_phone->setObjectName(QString::fromUtf8("tri_phone"));
        tri_phone->setGeometry(QRect(280, 10, 83, 29));
        tri_phone->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 39);"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(330, 240, 121, 26));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(470, 240, 121, 26));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(230, 270, 141, 26));
        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(360, 270, 191, 26));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(520, 270, 161, 26));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(710, 50, 711, 321));
        tableView->setStyleSheet(QString::fromUtf8("/* Set the background color of the table */\n"
"QTableView {\n"
"  \n"
"	background-color: rgb(117, 255, 234);\n"
"	color: rgb(85, 0, 0);\n"
"}\n"
"\n"
"/* Set the font and text color of the table headers */\n"
"QHeaderView::section {\n"
"  font: bold 12px;\n"
" \n"
"	color: rgb(255, 3, 7);\n"
"  background-color: #00a86b;\n"
"  height: 30px;\n"
"  border: none;\n"
"  border-right: 1px solid #c2c2c2;\n"
"}\n"
"\n"
"/* Set the font and text color of the table cells */\n"
"QTableView QTableWidget QTableCornerButton::section {\n"
"  background-color: #00a86b;\n"
"	color: rgb(85, 0, 0);\n"
"  border: none;\n"
"}\n"
"\n"
"QTableView QTableWidget QHeaderView {\n"
"  font: bold 10pt;\n"
"  color: rgb(85, 0, 0);\n"
"  background-color: #00a86b;\n"
"  border: none;\n"
"}\n"
"\n"
"QTableView QTableWidget {\n"
"  background-color: #f2f2f2;\n"
"  alternate-background-color: #f5ffef;\n"
"  font-size: 12px;\n"
"  selection-color: #ffffff;\n"
"	color: rgb(85, 0, 0);\n"
"  selection-background-color: #00a86b;\n"
"  border: no"
                        "ne;\n"
"  border-bottom: 1px solid #c2c2c2;\n"
"}\n"
"\n"
"/* Set the background color of selected rows */\n"
"QTableView QTableWidget::item:selected {\n"
"  background-color: #00a86b;\n"
"}\n"
"\n"
"/* Set the background color of the header for selected columns */\n"
"QTableView QHeaderView::section:selected {\n"
"  background-color: #00a86b;\n"
"}\n"
"\n"
"/* Set the background color of the cell under the mouse cursor */\n"
"QTableView QTableWidget::item:hover {\n"
"  background-color: #d0f0db;\n"
"}\n"
"\n"
"/* Remove the focus border around the cells */\n"
"QTableView QTableWidget:focus {\n"
"  border: none;\n"
"}\n"
"\n"
"/* Set the color and style of the grid lines */\n"
"QTableView QTableWidget::horizontalHeader, QTableView QTableWidget::verticalHeader {\n"
"  border: none;\n"
"  color: rgb(88, 99, 194);\n"
"  border-bottom: 1px solid #c2c2c2;\n"
"  border-right: 1px solid #c2c2c2;\n"
"}\n"
"\n"
"/* Set the padding and margin for the cells */\n"
"QTableView QTableWidget::item {\n"
"  padding: 5px;\n"
" "
                        " margin: 0px;\n"
"}"));
        line_15 = new QFrame(groupBox_3);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(220, 420, 481, 16));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        line_16 = new QFrame(groupBox_3);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(220, 510, 481, 16));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(230, 470, 171, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 4);\n"
"font: 14pt \"Arial Rounded MT Bold\";"));
        ID_DELETE = new QLineEdit(groupBox_3);
        ID_DELETE->setObjectName(QString::fromUtf8("ID_DELETE"));
        ID_DELETE->setGeometry(QRect(500, 530, 81, 22));
        ID_DELETE->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        ID_DELETE->setReadOnly(false);
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(230, 530, 241, 16));
        label_25->setFont(font);
        SHOW = new QPushButton(groupBox_3);
        SHOW->setObjectName(QString::fromUtf8("SHOW"));
        SHOW->setGeometry(QRect(580, 30, 101, 71));
        SHOW->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/eye.png"), QSize(), QIcon::Selected, QIcon::On);
        SHOW->setIcon(icon8);
        SHOW->setIconSize(QSize(80, 60));
        MODIFY = new QPushButton(groupBox_3);
        MODIFY->setObjectName(QString::fromUtf8("MODIFY"));
        MODIFY->setGeometry(QRect(330, 30, 91, 71));
        MODIFY->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/modify.png"), QSize(), QIcon::Selected, QIcon::On);
        MODIFY->setIcon(icon9);
        MODIFY->setIconSize(QSize(60, 60));
        line_27 = new QFrame(groupBox_3);
        line_27->setObjectName(QString::fromUtf8("line_27"));
        line_27->setGeometry(QRect(220, 560, 481, 16));
        line_27->setFrameShape(QFrame::HLine);
        line_27->setFrameShadow(QFrame::Sunken);
        groupBox_18 = new QGroupBox(groupBox_3);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(720, 500, 671, 201));
        groupBox_18->setFont(font);
        groupBox_18->setStyleSheet(QString::fromUtf8(""));
        PDF = new QPushButton(groupBox_18);
        PDF->setObjectName(QString::fromUtf8("PDF"));
        PDF->setGeometry(QRect(20, 60, 121, 111));
        PDF->setStyleSheet(QString::fromUtf8("background-color: rgb(167, 255, 126);"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/pdf.png"), QSize(), QIcon::Selected, QIcon::On);
        PDF->setIcon(icon10);
        PDF->setIconSize(QSize(100, 100));
        calendar = new QPushButton(groupBox_18);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(250, 60, 131, 111));
        calendar->setStyleSheet(QString::fromUtf8("background-color: rgb(133, 255, 182);"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/calendar.png"), QSize(), QIcon::Selected, QIcon::On);
        calendar->setIcon(icon11);
        calendar->setIconSize(QSize(100, 100));
        EXCEL = new QPushButton(groupBox_18);
        EXCEL->setObjectName(QString::fromUtf8("EXCEL"));
        EXCEL->setGeometry(QRect(500, 58, 141, 111));
        EXCEL->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/excel.png"), QSize(), QIcon::Selected, QIcon::On);
        EXCEL->setIcon(icon12);
        EXCEL->setIconSize(QSize(100, 100));
        groupBox_19 = new QGroupBox(groupBox_3);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(720, 750, 671, 111));
        groupBox_19->setFont(font);
        groupBox_19->setStyleSheet(QString::fromUtf8(""));
        SEARCH = new QLineEdit(groupBox_19);
        SEARCH->setObjectName(QString::fromUtf8("SEARCH"));
        SEARCH->setGeometry(QRect(30, 50, 441, 21));
        SEARCH->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        SEARCH->setReadOnly(false);
        SEARCH_2 = new QPushButton(groupBox_19);
        SEARCH_2->setObjectName(QString::fromUtf8("SEARCH_2"));
        SEARCH_2->setGeometry(QRect(510, 40, 111, 61));
        SEARCH_2->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 25, 255);"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/seo.png"), QSize(), QIcon::Selected, QIcon::On);
        SEARCH_2->setIcon(icon13);
        SEARCH_2->setIconSize(QSize(50, 50));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 690, 151, 121));
        label_7->setAutoFillBackground(false);
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/rapidrescue-logos.jpeg")));
        label_7->setScaledContents(true);
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(230, 300, 311, 16));
        label_37->setFont(font);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 360, 141, 20));
        suppression = new QPushButton(groupBox_3);
        suppression->setObjectName(QString::fromUtf8("suppression"));
        suppression->setGeometry(QRect(582, 440, 81, 71));
        suppression->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 255, 230);"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/bin.png"), QSize(), QIcon::Selected, QIcon::On);
        suppression->setIcon(icon14);
        suppression->setIconSize(QSize(60, 60));
        CREATION = new QDateEdit(groupBox_3);
        CREATION->setObjectName(QString::fromUtf8("CREATION"));
        CREATION->setGeometry(QRect(390, 360, 121, 29));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(230, 400, 241, 16));
        label_26->setFont(font);
        ID_M = new QLineEdit(groupBox_3);
        ID_M->setObjectName(QString::fromUtf8("ID_M"));
        ID_M->setGeometry(QRect(500, 400, 81, 22));
        ID_M->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 0);"));
        ID_M->setReadOnly(false);
        tabWidget->addTab(TRI_RECHERCHE_2, QString());
        STATISTIQUES_2 = new QWidget();
        STATISTIQUES_2->setObjectName(QString::fromUtf8("STATISTIQUES_2"));
        groupBox_9 = new QGroupBox(STATISTIQUES_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(0, 0, 1501, 881));
        groupBox_9->setStyleSheet(QString::fromUtf8("color:rgb(0,0,0);\n"
"font: 900 9pt \"Arial Black\";\n"
"background-color: \"#0F4264\";\n"
"color: \"white\""));
        line_41 = new QFrame(groupBox_9);
        line_41->setObjectName(QString::fromUtf8("line_41"));
        line_41->setGeometry(QRect(220, 840, 461, 16));
        line_41->setFrameShape(QFrame::HLine);
        line_41->setFrameShadow(QFrame::Sunken);
        specialty_view = new QCustomPlot(groupBox_9);
        specialty_view->setObjectName(QString::fromUtf8("specialty_view"));
        specialty_view->setGeometry(QRect(160, 180, 921, 261));
        capacity_view = new QCustomPlot(groupBox_9);
        capacity_view->setObjectName(QString::fromUtf8("capacity_view"));
        capacity_view->setGeometry(QRect(160, 510, 921, 241));
        tabWidget->addTab(STATISTIQUES_2, QString());
        hospital_view->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hospital_view);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1296, 25));
        hospital_view->setMenuBar(menubar);
        statusbar = new QStatusBar(hospital_view);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        hospital_view->setStatusBar(statusbar);

        retranslateUi(hospital_view);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(hospital_view);
    } // setupUi

    void retranslateUi(QMainWindow *hospital_view)
    {
        hospital_view->setWindowTitle(QCoreApplication::translate("hospital_view", "MainWindow", nullptr));
        groupBox_3->setTitle(QString());
        hopital_2->setText(QString());
        equippement_medical_2->setText(QString());
        urgence_2->setText(QString());
        equippage_2->setText(QString());
        vehicule_2->setText(QString());
        logout_2->setText(QString());
        label_15->setText(QCoreApplication::translate("hospital_view", "Nom:", nullptr));
        label_17->setText(QCoreApplication::translate("hospital_view", "Adresse:", nullptr));
        label_19->setText(QCoreApplication::translate("hospital_view", "Sp\303\251cialit\303\251:", nullptr));
        label_23->setText(QCoreApplication::translate("hospital_view", "Capacit\303\251:", nullptr));
        label_4->setText(QCoreApplication::translate("hospital_view", "AJOUT", nullptr));
        ADD->setText(QString());
        reset_2->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("hospital_view", "HOPITAL", nullptr));
        label_28->setText(QCoreApplication::translate("hospital_view", "N\302\260 T\303\251l\303\251phone:", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("hospital_view", "TRI", nullptr));
        tri_id->setText(QCoreApplication::translate("hospital_view", "ID", nullptr));
        tri_nom->setText(QCoreApplication::translate("hospital_view", "NOM", nullptr));
        tri_adresse->setText(QCoreApplication::translate("hospital_view", "ADRESSE", nullptr));
        tri_speciality->setText(QCoreApplication::translate("hospital_view", "SPECIALITY", nullptr));
        tri_nbr->setText(QCoreApplication::translate("hospital_view", "NBR DE PATIENTS ADMIS A L'HOPITAL", nullptr));
        tri_capacity->setText(QCoreApplication::translate("hospital_view", "CAPACITY", nullptr));
        tri_date->setText(QCoreApplication::translate("hospital_view", "DATE", nullptr));
        tri_phone->setText(QCoreApplication::translate("hospital_view", "PHONE", nullptr));
        checkBox->setText(QCoreApplication::translate("hospital_view", "Cardiologie", nullptr));
        checkBox_2->setText(QCoreApplication::translate("hospital_view", "neurologie", nullptr));
        checkBox_3->setText(QCoreApplication::translate("hospital_view", "pneumologie", nullptr));
        checkBox_4->setText(QCoreApplication::translate("hospital_view", "orthopediatrie", nullptr));
        checkBox_5->setText(QCoreApplication::translate("hospital_view", "Anesthesiologie", nullptr));
        label_10->setText(QCoreApplication::translate("hospital_view", "SUPPRESSION", nullptr));
        label_25->setText(QCoreApplication::translate("hospital_view", "ID POUR LA SUPPRESSION:", nullptr));
        SHOW->setText(QString());
        MODIFY->setText(QString());
        groupBox_18->setTitle(QCoreApplication::translate("hospital_view", "M\303\251tiers", nullptr));
        PDF->setText(QString());
        calendar->setText(QString());
        EXCEL->setText(QString());
        groupBox_19->setTitle(QCoreApplication::translate("hospital_view", "Recherche", nullptr));
        SEARCH_2->setText(QString());
        label_7->setText(QString());
        label_37->setText(QCoreApplication::translate("hospital_view", "nombre de Patients admis \303\240 l'hopital:", nullptr));
        label->setText(QCoreApplication::translate("hospital_view", "Date de cr\303\251ation:", nullptr));
        suppression->setText(QString());
        label_26->setText(QCoreApplication::translate("hospital_view", "ID POUR MODIFIER:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TRI_RECHERCHE_2), QCoreApplication::translate("hospital_view", "HOPITAL", nullptr));
        groupBox_9->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(STATISTIQUES_2), QCoreApplication::translate("hospital_view", "statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hospital_view: public Ui_hospital_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOSPITAL_VIEW_H
