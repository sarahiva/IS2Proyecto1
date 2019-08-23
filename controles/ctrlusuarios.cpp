#include "ctrlusuarios.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace Controles;

Modelos::Usuario CtrlUsuarios::curUser;

Modelos::Usuario
CtrlUsuarios::getUser(QString id) {
  QSqlDatabase db = QSqlDatabase::database("eleccion", true);
  QSqlQuery query(nullptr, db);
  query.prepare("SELECT * FROM vUsuarios WHERE usr=:usr");
  query.bindValue(":usr", QVariant(id));

  query.exec();
  query.next();

  Modelos::Usuario usr;  
  usr.usr = query.value("usr").toString();
  usr.usrnombre = query.value("usrnombre").toString();
  usr.pass = query.value("pass").toString();
  usr.tipoUsuario = query.value("tipoUsuario").toInt();
  setCurrentUser(usr);
  return usr;
}

void CtrlUsuarios::setCurrentUser(Modelos::Usuario usr)
{
    CtrlUsuarios::curUser = usr;
}

Modelos::Usuario
CtrlUsuarios::currentUser() {
    return CtrlUsuarios::curUser;
}

CtrlUsuarios::CtrlUsuarios()
{

}

