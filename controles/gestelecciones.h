#ifndef GESTELECCIONES_H
#define GESTELECCIONES_H
#include <QString>

namespace Controles {
    class GestElecciones
    {
    public:
        GestElecciones();
        virtual ~GestElecciones();
        static bool yaVoto(QString elector);
        static bool votar(QString elector);
    };

}

#endif /* GESTELECCIONES_H */
