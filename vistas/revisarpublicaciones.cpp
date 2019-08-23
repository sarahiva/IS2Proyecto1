#include "revisarpublicaciones.h"
#include "ui_revisarpublicaciones.h"
#include <QSqlDatabase>
#include <QDataWidgetMapper>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>
RevisarPublicaciones::RevisarPublicaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RevisarPublicaciones)
{
    ui->setupUi(this);
    ui->checkBox->hide();
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    model =  new QSqlTableModel(this, db);
    model->setTable("Publicacion");
    model->select();
    model->setFilter("estado=1");
    qDebug() << model->lastError().text() << model->index(0,2).data().toString();
    qDebug() << model->rowCount();
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
    int row = mapper->currentIndex();
    auto idx = model->index(row, 0);

    int folio = idx.siblingAtColumn(0).data().toInt();
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr,db);
    query.prepare("UPDATE Publicacion SET estado=2 WHERE folio = :folio");
    query.bindValue(":folio", folio);
    if(query.exec())
    {
        QMessageBox::information(this, "Información", "La Publicación ha sido aprobada");
        model->submitAll();
        model->select();
    }

        
    
}

void RevisarPublicaciones::on_rechazar_clicked()
{
    int row = mapper->currentIndex();
    auto idx = model->index(row, 0);

    int folio = idx.siblingAtColumn(0).data().toInt();
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr,db);
    query.prepare("UPDATE Publicacion SET estado=3 WHERE folio = :folio");
    query.bindValue(":folio", folio);
    if(query.exec())
    {
        QMessageBox::information(this, "Información", "La Publicación ha sido aprobada");
        model->submitAll();
        model->select();
    }

}
