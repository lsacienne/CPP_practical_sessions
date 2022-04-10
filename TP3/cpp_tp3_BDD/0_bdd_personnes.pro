TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += header

TARGET = ../tp3

SOURCES += \
        main.cpp \
        Personne.cpp \
        Administratif.cpp \
        Etudiant.cpp \
        Enseignant.cpp \
        bdd.cpp

HEADERS += \
        ListeRecursif.h \
        Personne.h \
        Administratif.h \
        Etudiant.h \
        Enseignant.h \
        bdd.h

