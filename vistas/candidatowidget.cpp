#include "candidatowidget.h"
#include "ui_candidatowidget.h"
#include "controles/ctrlusuarios.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
CandidatoWidget::CandidatoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CandidatoWidget)
{
    ui->setupUi(this);
    currentfolio = -1;
    eleccion = -1;
    model = new QSqlQueryModel(this);
        
}

CandidatoWidget::~CandidatoWidget()
{
    delete ui;
}

void CandidatoWidget::loadCandidato()
{
    using namespace Controles;
    auto usr = CtrlUsuarios::currentUser();
    candidato = usr.usr;
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    query.prepare("SELECT * FROM Publicacion WHERE claveCandidato=:candidato ORDER BY folio DESC LIMIT 1");
    query.bindValue(":candidato", candidato);

    if(query.exec())
    {
            qDebug() << query.lastQuery();
            qDebug() << query.lastError().text() << candidato;
            
        query.next();
        ui->textEdit->setHtml(query.value("texto").toString());
        currentfolio = query.value("folio").toInt();
        eleccion = query.value("idEleccion").toInt();
        
        int edo = query.value("estado").toInt();
        ui->titulo->setText(query.value("titulo").toString());
        QString estado;
        if(edo == 0 )
        {
            estado = "Sin enviar";
            ui->titulo->setEnabled(true);
            ui->textEdit->setEnabled(true);
        }
        else if(edo == 1)
        {
            estado = "En revisión";
            ui->titulo->setEnabled(false);
            ui->textEdit->setEnabled(false);
        }
        else if(edo == 3)
        {
            estado = "Rechazada";
            ui->titulo->setEnabled(true);
            ui->textEdit->setEnabled(true);
        }
        else if(edo == 2)
        {
            estado = "Aprobada";
            ui->titulo->setEnabled(false);
            ui->textEdit->setEnabled(false);

        }        
        ui->estado->setText(estado);
        
    }

    
    
    
}
void CandidatoWidget::on_guardar_clicked()
{
 QString html = ui->textEdit->toPlainText();  
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);


     query.prepare("UPDATE Publicacion SET texto = :texto, titulo = :titulo, estado=0"
                      " WHERE claveCandidato = :candidato");

     query.bindValue(":titulo", ui->titulo->text());
     query.bindValue(":texto", html);
     query.bindValue(":candidato", candidato);

        if(query.exec())
        {
            QMessageBox::information(this, "Información", "Se ha guardado el articulo.");
            // ui->textEdit->setPlainText("");
            // ui->titulo->setText("");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Ocurió un error, intente más tarde o contacte a su adminstrador.");
        }
        
    
}

void CandidatoWidget::on_textEdit_textChanged()
{
    ui->guardar->setEnabled(true);
}

void CandidatoWidget::on_solicitar_clicked()
{
    QString html = ui->textEdit->toPlainText();  
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);


     query.prepare("UPDATE Publicacion SET texto = :texto, titulo = :titulo, estado=1"
                      " WHERE claveCandidato = :candidato");

     query.bindValue(":titulo", ui->titulo->text());
     query.bindValue(":texto", html);
     query.bindValue(":candidato", candidato);

        if(query.exec())
        {
            QMessageBox::information(this, "Información", "Su solicictud ha sido enviada");
            ui->textEdit->setPlainText("");
            ui->titulo->setText("");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Ocurió un error, intente más tarde o contacte a su adminstrador.");
        }
    // if(currentfolio > 0)
    // {
    //     query.prepare("UPDATE Publicacion SET texto = :texto"
    //                   " WHERE folio = :folio");
    //     query.bindValue(":folio", currentfolio);
    // }
        
    // else
    // {
    //     query.prepare("INSERT INTO Publicacion(titulo, texto, estado, claveCandidato, idEleccion ) "
    //                   " VALUES(:titulo, :texto, 1, :candidato, :eleccion)");
    //     query.bindValue(":text", ui->textEdit->toHtml());
    //     query.bindValue(":candidato", candidato);
    //     query.bindValue(":eleccion", eleccion);
        
    // }
    // query.exec();
    
}
