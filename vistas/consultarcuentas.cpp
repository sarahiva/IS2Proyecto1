#include "consultarcuentas.h"
#include "ui_consultarcuentas.h"

ConsultarCuentas::ConsultarCuentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsultarCuentas)
{
    ui->setupUi(this);
}

ConsultarCuentas::~ConsultarCuentas()
{
    delete ui;
}
