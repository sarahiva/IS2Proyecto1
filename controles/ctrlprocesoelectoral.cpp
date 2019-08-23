#include "ctrlprocesoelectoral.h"
#include "modelos/eleccion.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace Controles;

CtrlProcesoElectoral::CtrlProcesoElectoral()
    : eleccion(nullptr)
{
    
}
CtrlProcesoElectoral::~CtrlProcesoElectoral() {
    
}


void CtrlProcesoElectoral::actualizarCambios(QDate fj, QTime fi, QTime ff)
{
    
    // if(eleccion == nullptr)
    //     return;

    // QSqlDatabase db = QSqlDatabase::database("eleccion", true);      
    // QSqlQuery query(nullptr, db);
    // query.prepare("UPDATE Eleccion SET fechaJornada=:fj, horaIniJornada=:fi, horaFinJornada=:ff"
    //       " WHERE idEleccion = :id");

    
    // query.bindValue(":id", getinstance()->elecion->geId());
      
    //       if(query.exec())
    //       {
    //           query.next();
    //           eleccion = new Modelos::Eleccion(query.value("fechaJornada").toDate(),
    //                                            query.value("horaIniJornada").toTime(),
    //                                            query.value("horaFinJornada").toTime());
    //       }
    //       return eleccion;
}
    
Modelos::Eleccion *CtrlProcesoElectoral::crearProcesoElectoral(QDate fj, QTime fi, QTime ff)
{
    
    return new Modelos::Eleccion(fj, fi, ff);
}

CtrlProcesoElectoral *CtrlProcesoElectoral::getinstance()
{
    if(instance)
        return instance;
    else
        return (instance = new CtrlProcesoElectoral);
}


Modelos::Eleccion *CtrlProcesoElectoral::getEleccion()
{
    
      QSqlDatabase db = QSqlDatabase::database("eleccion", true);
      QSqlQuery query(nullptr, db);
      query.prepare("SELECT * FROM Eleccion ORDER BY idEleccion DESC LIMI 1");
      // query.bindValue(":usr", QVariant(id));
      Modelos::Eleccion * eleccion = nullptr;
          if(query.exec())
          {
              query.next();
              eleccion = new Modelos::Eleccion(query.value("fechaJornada").toDate(),
                                               query.value("horaIniJornada").toTime(),
                                               query.value("horaFinJornada").toTime());
          }
          return eleccion;
      
      
}
