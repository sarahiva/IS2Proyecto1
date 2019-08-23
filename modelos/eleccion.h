#ifndef ELECCION_H
#define ELECCION_H

#include <QDate>
#include <QTime>
class QSqlTableModel;
namespace Modelos {
    
    class Eleccion
    {
    public:
        Eleccion();
        Eleccion(QDate fjornada, QTime iniJornada, QTime finJornada);
        void actualizaInfo();
        int getID() const { return idEleccion; }
        friend class InicioAdmin;
      private:
        int idEleccion;
        QDate fechaJornada;
        QTime horaIniJornada;
        QTime horaFinJornada;
        // QSqlTableModel *model;
    };
    
}


#endif // ELECCION_H
