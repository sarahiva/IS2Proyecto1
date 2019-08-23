#include "electorwidget.h"
#include "ui_electorwidget.h"
#include "itemcandidato.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "controles/ctrlusuarios.h"
#include "controles/gestelecciones.h"

ElectorWidget::ElectorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElectorWidget)
{
    ui->setupUi(this);
    cargarCandidatos();
// connect(ui->ButtonCerrarSesion, &QPushButton::clicked, this, &ElectorWidget::close);
}

ElectorWidget::~ElectorWidget()
{
    delete ui;
}


void ElectorWidget::clear()
{
    using namespace Controles;
    GestElecciones::votar(CtrlUsuarios::currentUser().usr);
    
    clearLayout(ui->listaCandidatos);
       ui->gracias1->show();
       ui->gracias2->show();
       
}

void ElectorWidget::cargarCandidatos()
{
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    ui->gracias1->hide();
    ui->gracias2->hide();
    QSqlQuery query(nullptr, db);
    if(query.exec("SELECT * FROM vListaCandidatos"))
    {
        QString clave, candidato, partido, emblema;
        ItemCandidato *item;
        while(query.next())
        {
           
            clave = query.value("claveCandidato").toString();
            candidato = query.value("candidato").toString();
            partido  = query.value("partido").toString();
            emblema = query.value("emblema").toString();
            item = new ItemCandidato(this, candidato, partido, emblema, clave);
            connect(item, &ItemCandidato::voted, this, &ElectorWidget::clear);
            ui->listaCandidatos->addWidget(item);
            
        }
        
    }
}
void ElectorWidget::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}
