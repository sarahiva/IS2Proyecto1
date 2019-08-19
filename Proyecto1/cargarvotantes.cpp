#include "cargarvotantes.h"
#include "ui_cargarvotantes.h"

CargarVotantes::CargarVotantes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CargarVotantes)
{
    ui->setupUi(this);
}

CargarVotantes::~CargarVotantes()
{
    delete ui;
}
