#include "ui_inicioadmin.h"
#include "inicioadmin.h"
#include "crearprocesoelec.h"

InicioAdmin::InicioAdmin(QWidget *parent)
    : QMainWindow(parent),
      ui( new Ui::InicioAdmin)
{
    ui->setupUi(this);
}

InicioAdmin::~InicioAdmin()
{
    delete ui;
}

void InicioAdmin::on_createProcBtn_clicked()
{
    CrearProcesoElec elec;
    if(elec.exec() == QDialog::Accepted)
    {
        
    }
    
    return;
}

void InicioAdmin::on_publiBtn_clicked()
{

}

void InicioAdmin::on_loadListBtn_clicked()
{

}

void InicioAdmin::on_genCtasBtn_clicked()
{

}

void InicioAdmin::on_ctasBtn_clicked()
{

}

void InicioAdmin::on_cerrarSesionBtn_clicked()
{
    if(close())
        emit logout();
}
