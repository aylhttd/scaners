QT  += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = bashenki.ico

SOURCES += \
    graphic_window.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    number_of_signal_chiose.cpp \
    number_of_zakladka_choise.cpp

HEADERS += \
    graphic_window.h \
    mainmenu.h \
    mainwindow.h \
    number_of_signal_chiose.h \
    number_of_zakladka_choise.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

VERSION = 1.0.0
QMAKE_TARGET_COMPANY = QARASIQ_STUDIOS
QMAKE_TARGET_PRODUCT = FIELD_DETECTOR
QMAKE_TARGET_COPYRIGHT = QARASIQ_STUDIOS

RESOURCES += \
    res.qrc
