#-------------------------------------------------
#
# Project created by QtCreator 2019-08-18T11:52:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += debug
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = Proyecto1
TEMPLATE = app
DESTDIR = build
OBJECTS_DIR = build/objs
MOC_DIR = build/mocs
UI_DIR = vistas
VPATH = vistas forms estilos controles modelos utils
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
    electorwidget.cpp \
    candidatowidget.cpp \
    resultados.cpp \
    perfilcandidato.cpp \
    inicioadmin.cpp \
    resumenproceso.cpp \
    modificarproceso.cpp \
    revisarpublicaciones.cpp \
    cargarvotantes.cpp \
    generarcuentas.cpp \
    consultarcuentas.cpp \
    crearprocesoelec.cpp \
itemcandidato.cpp \
    login.cpp \
    controles/ctrlcampagnas.cpp \
    modelos/eleccion.cpp \
    modelos/propaganda.cpp \
    controles/ctrlprocesoelectoral.cpp \
    controles/ctrlcuentas.cpp \
    itemresultados.cpp \
    controles/ctrlusuarios.cpp \
    modelos/usuario.cpp \
    controles/gestelecciones.cpp \
    modelos/candidato.cpp \
    modelos/elector.cpp

HEADERS += \
    electorwidget.h \
    candidatowidget.h \
    resultados.h \
    perfilcandidato.h \
    inicioadmin.h \
    resumenproceso.h \
    modificarproceso.h \
    revisarpublicaciones.h \
    cargarvotantes.h \
    generarcuentas.h \
    consultarcuentas.h \
    crearprocesoelec.h \
    itemcandidato.h \
    login.h \
    controles/ctrlcampagnas.h \
    modelos/eleccion.h \
    modelos/propaganda.h \
    modelos/usuario.h \
    controles/ctrlprocesoelectoral.h \
    controles/ctrlcuentas.h \
    controles/ctrlusuarios.h \
    modelos/candidato.h \
    utils/csv.h \
    gestelecciones.h  \
    utils/exceptions.h \
    itemresultados.h \
    modelos/elector.h
    

FORMS += \
    electorwidget.ui \
    candidatowidget.ui \
    resultados.ui \
    perfilcandidato.ui \
    inicioadmin.ui \
    resumenproceso.ui \
    modificarproceso.ui \
    revisarpublicaciones.ui \
    cargarvotantes.ui \
    generarcuentas.ui \
    consultarcuentas.ui \
    crearprocesoelec.ui \
    itemCandidato.ui \
    itemresultados.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
    
myrun.target = run
myrun.depends = all
myrun.commands = $$DESTDIR/$$TARGET
QMAKE_EXTRA_TARGETS += myrun
