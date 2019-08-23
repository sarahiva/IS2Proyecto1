#include "gestelecciones.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace Controles;



bool GestElecciones::yaVoto(QString elector)
{
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    int res = 0;
    query.prepare("SELECT yaVoto FROM Elector WHERE claveElector = :idelector");
    query.bindValue(":idelector", elector);
    if(query.exec())
    {
        query.next();
        res = query.value("yaVoto").toInt();
        
    }
    return res > 0;
    
}

    
bool GestElecciones::votar(QString elector)
{
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    bool res = false;
    query.prepare("UPDATE Elector SET yaVoto = 1 WHERE claveElector=:idelector");
    query.bindValue(":idelector", elector);
    if(query.exec())
    {
        
        res = true;
    }
    return res;
}
