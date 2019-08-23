#ifndef CTRLUSUARIOS_H
#define CTRLUSUARIOS_H
#include "modelos/usuario.h"
#include <QMap>

namespace Controles
{
    
    class CtrlUsuarios
    {
    public:
        CtrlUsuarios();
        static Modelos::Usuario getUser(QString id);
        static Modelos::Usuario currentUser();
        static void setCurrentUser(Modelos::Usuario usr);
    private:
        static Modelos::Usuario curUser;

    };
    
}



#endif // CTRLUSUARIOS_H
