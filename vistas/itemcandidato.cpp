#include "itemcandidato.h"
#include "ui_itemCandidato.h"
#include "perfilcandidato.h"
#include <QSqlDatabase>
#include <QSqlQuery>

ItemCandidato::ItemCandidato(QWidget *parent,
                             QString nombre,
                             QString partido,
                             QString emblema,
                             QString clve)
    :
    QWidget(parent),
    ui(new Ui::ItemCandidato)
{
    ui->setupUi(this);
    setdatos(nombre,partido, emblema, clve);
}

ItemCandidato::~ItemCandidato()
{
    delete ui;
}

void ItemCandidato::setdatos(QString nombre, QString partido, QString emblema, QString clve)
{
    ui->nombre->setText(nombre);
    ui->partido->setText(partido);
    ui->emblema->setPixmap(QPixmap(emblema).scaled(48, 48));
    clave = clve;
}

void ItemCandidato::on_votar_clicked()
{
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    query.prepare("SET @votos = (SELECT cantidadVotos FROM Candidato"
                  " WHERE claveCandidato = :clave);"
                  " UPDATE Candidato SET cantidadVotos=@votos + 1 "
                  "WHERE claveCandidato = :clave;");
    query.bindValue(":clave", clave);
    if(query.exec())
    {
        emit voted();
    }
}
void ItemCandidato::on_verperfil_clicked()
{
    PerfilCandidato perfil(this, clave);
    perfil.exec();
}
