#include "perfilcandidato.h"
#include "ui_perfilcandidato.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>

PerfilCandidato::PerfilCandidato(QWidget *parent, QString idCandidato) :
   QDialog(parent),
   ui(new Ui::PerfilCandidato),
   id(idCandidato)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    query.prepare("SELECT * FROM vPerfil WHERE claveCandidato = :id" );
    query.bindValue(":id", id);
    
    if(query.exec())
    {
        query.next();
        qDebug() << id;
        QString nombre = query.value("nombre").toString();
        QString foto = query.value("foto").toString();
        QString publi = query.value("texto").toString();
        QString titulo = query.value("titulo").toString();
        qDebug() << id << foto << publi << titulo;
        ui->nombre->setText(nombre);
        ui->foto->setPixmap(QPixmap(foto));
        ui->publicaciones->setPlainText(publi);
        ui->titulo->setText(titulo);
        
    }
}

PerfilCandidato::~PerfilCandidato()
{
    delete ui;
}
