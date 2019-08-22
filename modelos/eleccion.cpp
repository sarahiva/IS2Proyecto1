#include "eleccion.h"

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>
using namespace Modelos;

Eleccion::Eleccion()
{
    Eleccion(QDate::currentDate(), QTime::currentTime(), QTime::currentTime().addSecs(24 * 60 * 60));
    actualizaInfo();
    
}

Eleccion::Eleccion(QDate fjornada, QTime iniJornada, QTime finJornada)
{
    fechaJornada = fjornada;
    horaIniJornada = iniJornada;
    horaFinJornada = finJornada;
    idEleccion=-1;
    actualizaInfo();
}

void Eleccion::actualizaInfo()
{
    QSqlDatabase db = QSqlDatabase::database("eleccion");
    db.open();
    
    qDebug() << db.lastError().text();
    QSqlTableModel model(nullptr, db);
    model.setTable("Eleccion");
    model.select();

    if(idEleccion < 0)
    {
        qDebug() << model.database().isOpen();
        QSqlRecord rec = model.record();
        rec.setGenerated("idEleccion", true);
        rec.setValue("fechaJornada", fechaJornada);
        rec.setValue("horaIniJornada", horaIniJornada);
        rec.setValue("horaFinJornada", horaFinJornada);        
        model.insertRecord(-1, rec);
        model.select();
        
        idEleccion = model.record(model.rowCount() - 1).value("idEleccion").toInt();
        
    }
    
}
