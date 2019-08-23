#ifndef USUARIO_H
#define USUARIO_H
#include <QString>

namespace Modelos
{
    struct Usuario
    {
        Usuario();
        QString usr;
        QString usrnombre;
        QString pass;
        int tipoUsuario;
        
    };
}


#endif /* USUARIO_H */
