#include "itemresultados.h"
#include "ui_itemresultados.h"



ItemResultados::ItemResultados(QWidget* parent, QString nombre, QString partido, QString emblema, QString foto, 
                                       int votos,   double porcentaje)
    :QWidget(parent),
     ui(new Ui::ItemResultados)
{
    ui->setupUi(this);
    ui->candidato->setText(nombre);
    ui->partido->setText(partido);
    ui->emblema->setPixmap(QPixmap(emblema).scaled(48, 48));
    ui->votos->setText(QString::number(votos) );
    ui->resultado->setText(QString::number(porcentaje * 100) + " %");
    
}

ItemResultados::~ItemResultados()
{
    delete ui;
}
