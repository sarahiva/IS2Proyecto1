#ifndef CONSULTARCUENTAS_H
#define CONSULTARCUENTAS_H

#include <QDialog>

namespace Ui {
class ConsultarCuentas;
}

class ConsultarCuentas : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarCuentas(QWidget *parent = nullptr);
    ~ConsultarCuentas();

private:
    Ui::ConsultarCuentas *ui;
};

#endif // CONSULTARCUENTAS_H
