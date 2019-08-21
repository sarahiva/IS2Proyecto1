#include "crearprocesoelec.h"
#include "ui_crearprocesoelec.h"

#include <QFileDialog>


CrearProcesoElec::CrearProcesoElec(QWidget *parent)
    : QDialog(parent),
      ui (new Ui::CrearProcesoElec)
{
    ui->setupUi(this);
}

CrearProcesoElec::~CrearProcesoElec()
{
    delete ui;
}

void CrearProcesoElec::on_loadFileBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Abrirarchivo de Candidatos", "./", tr("Archivos CSV (*.csv)"));
    if(!filename.isNull())
    {
        ui->fileLEdit->setText(filename);
    }
    
}

void CrearProcesoElec::on_publiBtn_clicked()
{
    
}
