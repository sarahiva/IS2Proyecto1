#ifndef CTRLPROCESOELECTORAL_H
#define CTRLPROCESOELECTORAL_H
namespace Modelos {
    class Eleccion;
}

#include <QDate>
#include <QTime>
namespace Controles {
    

class CtrlProcesoElectoral
{
public:
    CtrlProcesoElectoral();
    virtual ~CtrlProcesoElectoral();
    static Modelos::Eleccion *crearProcesoElectoral(QDate fj, QTime fi, QTime ff);
    static Modelos::Eleccion *getEleccion();
    static void actualizarCambios(QDate fj, QTime fi, QTime ff);
    void buscar();
    void confirmar();
    void modificarEleccion(int id);
    CtrlProcesoElectoral *getinstance();
private:
    Modelos::Eleccion *eleccion;
    CtrlProcesoElectoral *instance;
};
}

#endif /* CTRLPROCESOELECTORAL_H */
