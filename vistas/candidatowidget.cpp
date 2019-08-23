#include "candidatowidget.h"
#include "ui_candidatowidget.h"
#include "controles/ctrlusuarios.h"

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
            
        }
        else if(edo == 1)
        {
            estado = "En revisión";
            ui->titulo->setEnabled(false);
            ui->titulo->setEnabled(false);
        }
        else if(edo == 2)
        {
            estado = "Cancelada";
            ui->titulo->setEnabled(false);
            ui->textEdit->setEnabled(false);
        }
        else if(edo == 3)
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

        
    
}

void CandidatoWidget::on_textEdit_textChanged()
{
    ui->guardar->setEnabled(true);
}

void CandidatoWidget::on_solicitar_clicked()
{
    QString html = ui->textEdit->toHtml();  
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    if(currentfolio > 0)
    {
        query.prepare("UPDATE Publicacion SET texto = :texto"
                      " WHERE folio = :folio");
        query.bindValue(":folio", currentfolio);
    }
        
    else
    {
        query.prepare("INSERT INTO Publicacion(titulo, texto, estado, claveCandidato, idEleccion ) "
                      " VALUES(:titulo, :texto, 1, :candidato, :eleccion)");
        query.bindValue(":text", ui->textEdit->toHtml());
        query.bindValue(":candidato", candidato);
        query.bindValue(":eleccion", eleccion);
        
    }
    query.exec();
    
}
