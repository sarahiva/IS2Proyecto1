#include "ui_inicioadmin.h"
#include "inicioadmin.h"
#include "crearprocesoelec.h"
#include "revisarpublicaciones.h"
#include "generarcuentas.h"
#include "cargarvotantes.h"
#include "consultarcuentas.h"

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
    CrearProcesoElec elec(this);
    if(elec.exec() == QDialog::Accepted)
    {
        
    }
    
    return;
}

void InicioAdmin::on_publiBtn_clicked()
{
    RevisarPublicaciones publicaciones(this);
    if(publicaciones.exec() == QDialog::Accepted)
    {
        
    }
    
}

void InicioAdmin::on_loadListBtn_clicked()
{
    CargarVotantes votantes(this);
    votantes.exec();
}

void InicioAdmin::on_genCtasBtn_clicked()
{
    GenerarCuentas gen(this);
    gen.exec();
}

void InicioAdmin::on_ctasBtn_clicked()
{
    ConsultarCuentas cuentas(this);
    cuentas.exec();
}

void InicioAdmin::on_cerrarSesionBtn_clicked()
{
    if(close())
        emit logout();
}
