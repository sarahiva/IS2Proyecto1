#ifndef GENERARCUENTAS_H
#define GENERARCUENTAS_H

#include <QDialog>

namespace Ui {
class GenerarCuentas;
}

class GenerarCuentas : public QDialog
{
    Q_OBJECT

public:
    explicit GenerarCuentas(QWidget *parent = nullptr);
    ~GenerarCuentas();

private:
    Ui::GenerarCuentas *ui;
};

#endif // GENERARCUENTAS_H
