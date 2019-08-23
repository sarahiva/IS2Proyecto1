#include "ui_inicioadmin.h"
#include "inicioadmin.h"
#include "crearprocesoelec.h"
#include "revisarpublicaciones.h"
#include "generarcuentas.h"
#include "cargarvotantes.h"
#include "consultarcuentas.h"
#include "controles/ctrlusuarios.h"
#include "controles/gestelecciones.h"
#include "controles/ctrlprocesoelectoral.h"
#include "modelos/eleccion.h"
#include <QCloseEvent>
#include <QMessageBox>

#include <QDebug>

InicioAdmin::InicioAdmin(QWidget *parent)
    : QMainWindow(parent),
      ui( new Ui::InicioAdmin)
{
    ui->setupUi(this);
    eleccion = Controles::CtrlProcesoElectoral::getEleccion();
    ui->toolbar->hide();
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
    // if(close())
        emit logout();
        
}

void InicioAdmin::on_modProcBtn_clicked()
{

    if(eleccion == nullptr) return;

    CrearProcesoElec elec(this);

    elec.setupModel(eleccion->getID());
    if(elec.exec() == QDialog::Accepted)
    {
        
    }
}

void InicioAdmin::on_votarBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void InicioAdmin::on_resultadosBtn_clicked()
{
    ui->resultados->cargarCandidatos();
    ui->stackedWidget->setCurrentIndex(1);
}
void InicioAdmin::on_candidatosBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void InicioAdmin::on_adminBtn_clicked()
{
    ui->resultados->cargarCandidatos();
    ui->stackedWidget->setCurrentIndex(0);
}

void InicioAdmin::closeEvent(QCloseEvent *event)
{

    int res = QMessageBox::question(this, tr("Cerrar Sesión"), "¿Está seguro que desea salir?");
    if(res == QMessageBox::Yes)
    {
        event->accept();
    }
    else
        event->ignore();

}

void InicioAdmin::login()
{
    using namespace Controles;
    auto usr = CtrlUsuarios::currentUser();
    ui->ID->setText(usr.usr);
    QString tipo;
    switch (usr.tipoUsuario) {
    case 1: {
        tipo = "Administrador";
        ui->toolbar->show();
        ui->votarBtn->hide();
        ui->candidatosBtn->hide();
        on_adminBtn_clicked();
        break;
    }
    case 2: {
        tipo = "Candidato";
        ui->candidato->loadCandidato();
        on_candidatosBtn_clicked();
         ui->toolbar->hide();
        break;
    }
    case 3: {
        tipo = "Elector";
        qDebug() << GestElecciones::yaVoto(usr.usr);
        if(GestElecciones::yaVoto(usr.usr))
        {
            on_resultadosBtn_clicked();
            ui->toolbar->hide();
            qDebug() << "ya voto";
            break;
        }
        else
        {
            on_votarBtn_clicked();
             ui->toolbar->hide();
            break;
        }
            
    } 
    default:
        tipo = "Desconocido";
         ui->toolbar->hide();         
        break;
    }
    ui->tipoUsr->setText(tipo);
    ui->nombreUsr->setText(usr.usrnombre);
    showMaximized();
}
