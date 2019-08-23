#ifndef CTRLCUENTAS_H
#define CTRLCUENTAS_H
#include <QString>
namespace Controles {
    class CtrlCuentas
    {
    public:
        CtrlCuentas();
        void cargarLista(QString fname);
        bool generarCuentas(bool candidatos = false);
    private:
        QString filename;
    };
    
}

#endif // CTRLCUENTAS_H
