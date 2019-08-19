#include "candidato.h"
#include "ui_candidato.h"

Candidato::Candidato(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Candidato)
{
    ui->setupUi(this);
}

Candidato::~Candidato()
{
    delete ui;
}
