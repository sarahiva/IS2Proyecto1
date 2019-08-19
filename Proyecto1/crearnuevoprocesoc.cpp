#include "crearnuevoprocesoc.h"
#include "ui_crearnuevoprocesoc.h"

CrearNuevoProcesoC::CrearNuevoProcesoC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrearNuevoProcesoC)
{
    ui->setupUi(this);
}

CrearNuevoProcesoC::~CrearNuevoProcesoC()
{
    delete ui;
}
