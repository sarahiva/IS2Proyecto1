#include "resultados.h"
#include "ui_resultados.h"
#include "itemresultados.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "controles/ctrlusuarios.h"
#include "controles/gestelecciones.h"


Resultados::Resultados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);
    this->cargarCandidatos();
    
}

Resultados::~Resultados()
{
    delete ui;
}


void Resultados::cargarCandidatos()
{
    clearLayout(ui->resultados);
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    ItemResultados *item;
    QSqlQuery query(nullptr, db);
    if(query.exec("SELECT * FROM vResultados"))
    {
        QString nombre, partido, emblema, foto;
        int votos;
        double porcentaje;
        
        while(query.next())
        {
            
            nombre     = query.value("nombre").toString();
            votos      = query.value("cantidadVotos").toInt();
            porcentaje      = query.value("porcentaje").toDouble();
            partido    = query.value("partido").toString();
            emblema    = query.value("emblema").toString();
            item = new ItemResultados(this, nombre, partido, emblema, foto, votos, porcentaje);
            // ui->frame->layout()->addWidget(item);
            ui->resultados->addWidget(item);
           
        }       
    }
    
}
void Resultados::clearLayout(QLayout *layout) {
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
