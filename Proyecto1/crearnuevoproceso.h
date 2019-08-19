#ifndef CREARNUEVOPROCESO_H
#define CREARNUEVOPROCESO_H

#include <QWidget>

namespace Ui {
class CrearNuevoProceso;
}

class CrearNuevoProceso : public QWidget
{
    Q_OBJECT

public:
    explicit CrearNuevoProceso(QWidget *parent = nullptr);
    ~CrearNuevoProceso();

private:
    Ui::CrearNuevoProceso *ui;
};

#endif // CREARNUEVOPROCESO_H
