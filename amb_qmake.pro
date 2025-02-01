QT       += core gui sql multimedia printsupport charts network serialport

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

SOURCES += \
    arduino.cpp \
    connection.cpp \
    hopital.cpp \
    hospital_view.cpp \
    main.cpp \
    mainwindow.cpp \
    vehiclewindow.cpp \
    vehicule.cpp

HEADERS += \
    arduino.h \
    connection.h \
    header/xlsxabstractooxmlfile.h \
    header/xlsxabstractooxmlfile_p.h \
    header/xlsxabstractsheet.h \
    header/xlsxabstractsheet_p.h \
    header/xlsxcell.h \
    header/xlsxcell_p.h \
    header/xlsxcellformula.h \
    header/xlsxcellformula_p.h \
    header/xlsxcelllocation.h \
    header/xlsxcellrange.h \
    header/xlsxcellreference.h \
    header/xlsxchart.h \
    header/xlsxchart_p.h \
    header/xlsxchartsheet.h \
    header/xlsxchartsheet_p.h \
    header/xlsxcolor_p.h \
    header/xlsxconditionalformatting.h \
    header/xlsxconditionalformatting_p.h \
    header/xlsxcontenttypes_p.h \
    header/xlsxdatavalidation.h \
    header/xlsxdatavalidation_p.h \
    header/xlsxdatetype.h \
    header/xlsxdocpropsapp_p.h \
    header/xlsxdocpropscore_p.h \
    header/xlsxdocument.h \
    header/xlsxdocument_p.h \
    header/xlsxdrawing_p.h \
    header/xlsxdrawinganchor_p.h \
    header/xlsxformat.h \
    header/xlsxformat_p.h \
    header/xlsxglobal.h \
    header/xlsxmediafile_p.h \
    header/xlsxnumformatparser_p.h \
    header/xlsxrelationships_p.h \
    header/xlsxrichstring.h \
    header/xlsxrichstring_p.h \
    header/xlsxsharedstrings_p.h \
    header/xlsxsimpleooxmlfile_p.h \
    header/xlsxstyles_p.h \
    header/xlsxtheme_p.h \
    header/xlsxutility_p.h \
    header/xlsxworkbook.h \
    header/xlsxworkbook_p.h \
    header/xlsxworksheet.h \
    header/xlsxworksheet_p.h \
    header/xlsxzipreader_p.h \
    header/xlsxzipwriter_p.h \
    hopital.h \
    hospital_view.h \
    mainwindow.h \
    vehiclewindow.h \
    vehicule.h

FORMS += \
    hospital_view.ui \
    mainwindow.ui \
    vehiclewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \
    res.qrc
