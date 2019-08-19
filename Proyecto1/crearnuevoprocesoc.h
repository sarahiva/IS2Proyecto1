#ifndef CREARNUEVOPROCESOC_H
#define CREARNUEVOPROCESOC_H

#include <QWidget>

namespace Ui {
class CrearNuevoProcesoC;
}

class CrearNuevoProcesoC : public QWidget
{
    Q_OBJECT

public:
    explicit CrearNuevoProcesoC(QWidget *parent = nullptr);
    ~CrearNuevoProcesoC();

private:
    Ui::CrearNuevoProcesoC *ui;
};

#endif // CREARNUEVOPROCESOC_H
