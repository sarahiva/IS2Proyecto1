#include "perfilcandidato.h"
#include "ui_perfilcandidato.h"

PerfilCandidato::PerfilCandidato(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::PerfilCandidato)
{
    ui->setupUi(this);
}

PerfilCandidato::~PerfilCandidato()
{
    delete ui;
}
