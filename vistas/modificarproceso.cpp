#include "modificarproceso.h"
#include "ui_modificarproceso.h"

ModificarProceso::ModificarProceso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModificarProceso)
{
    ui->setupUi(this);
}

ModificarProceso::~ModificarProceso()
{
    delete ui;
}
