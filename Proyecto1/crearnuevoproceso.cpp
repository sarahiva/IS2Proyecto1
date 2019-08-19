#include "crearnuevoproceso.h"
#include "ui_crearnuevoproceso.h"

CrearNuevoProceso::CrearNuevoProceso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrearNuevoProceso)
{
    ui->setupUi(this);
}

CrearNuevoProceso::~CrearNuevoProceso()
{
    delete ui;
}
