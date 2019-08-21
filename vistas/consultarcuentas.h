#ifndef CONSULTARCUENTAS_H
#define CONSULTARCUENTAS_H

#include <QWidget>

namespace Ui {
class ConsultarCuentas;
}

class ConsultarCuentas : public QWidget
{
    Q_OBJECT

public:
    explicit ConsultarCuentas(QWidget *parent = nullptr);
    ~ConsultarCuentas();

private:
    Ui::ConsultarCuentas *ui;
};

#endif // CONSULTARCUENTAS_H
