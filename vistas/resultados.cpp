#include "resultados.h"
#include "ui_resultados.h"

Resultados::Resultados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);
}

Resultados::~Resultados()
{
    delete ui;
}
