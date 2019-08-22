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
    void actualizarCambios();
    void buscar();
    void confirmar();
    void modificarEleccion(int id);
private:
    Modelos::Eleccion *eleccion;
};
}

#endif /* CTRLPROCESOELECTORAL_H */
