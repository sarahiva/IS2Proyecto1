#include "ctrlprocesoelectoral.h"
#include "modelos/eleccion.h"

using namespace Controles;

CtrlProcesoElectoral::CtrlProcesoElectoral()
    : eleccion(nullptr)
{
    
}
CtrlProcesoElectoral::~CtrlProcesoElectoral() {
    
}

Modelos::Eleccion *CtrlProcesoElectoral::crearProcesoElectoral(QDate fj, QTime fi, QTime ff)
{
    
    return new Modelos::Eleccion(fj, fi, ff);
}

