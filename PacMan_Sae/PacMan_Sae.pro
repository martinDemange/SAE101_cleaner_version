TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        affichage.cpp \
        config.cpp \
        gestion.cpp \
        initialisation.cpp \
        main.cpp \
        mouvementPerso.cpp

HEADERS += \
    affichage.h \
    config.h \
    gestion.h \
    initialisation.h \
    mouvementPerso.h \
    types.h


include(minglv2/mingl.pri)
