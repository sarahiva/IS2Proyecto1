#include "revisarpublicaciones.h"
#include "ui_revisarpublicaciones.h"
#include <QSqlDatabase>
#include <QDataWidgetMapper>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>

RevisarPublicaciones::RevisarPublicaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RevisarPublicaciones)
{
    ui->setupUi(this);
    ui->checkBox->hide();
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    model =  new QSqlTableModel(this, db);
    model->setTable("Publicacion");
    // model->setFilter("estado=1 ");
    qDebug() << model->lastError().text() << model->index(0,2).data().toString();
    
    mapper =  new QDataWidgetMapper;
    mapper->setModel(model);    
    mapper->addMapping(ui->textBrowser, 2);
    mapper->toFirst();

}

RevisarPublicaciones::~RevisarPublicaciones()
{
    delete ui;
}



void RevisarPublicaciones::on_next_clicked()
{
    mapper->toNext();
}
void RevisarPublicaciones::on_prev_clicked()
{
    mapper->toPrevious();
}
void RevisarPublicaciones::on_accept_clicked()
{
    ui->checkBox->setChecked(true);
}

void RevisarPublicaciones::on_rechazar_clicked()
{
    ui->checkBox->setChecked(false);
}
