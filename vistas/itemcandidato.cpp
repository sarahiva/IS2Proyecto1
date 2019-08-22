#include "itemcandidato.h"
#include "ui_itemCandidato.h"

ItemCandidato::ItemCandidato(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemCandidato)
{
    ui->setupUi(this);
}

ItemCandidato::~ItemCandidato()
{
    delete ui;
}

void ItemCandidato::setdatos(QString nombre, QString partido, QString emblema)
{
    ui->nombreL->setText(nombre);
    ui->_partido_->setText(partido);
    ui->emblema->setPixmap(QPixmap(emblema));
}
