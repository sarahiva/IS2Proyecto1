#include "generarcuentas.h"
#include "ui_generarcuentas.h"

GenerarCuentas::GenerarCuentas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerarCuentas)
{
    ui->setupUi(this);
}

GenerarCuentas::~GenerarCuentas()
{
    delete ui;
}
