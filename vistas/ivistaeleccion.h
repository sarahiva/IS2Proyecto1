#ifndef IVISTAELECCION_H
#define IVISTAELECCION_H
#include <QDate>
namespace Vistas
{
    class IVistaEleccion
    {
    public:
        IVistaEleccion();
        virtual ~IVistaEleccion();
        virtual QDate getFechaJornada() = 0;
    
};
}



#endif /* IVISTAELECCION_H */
