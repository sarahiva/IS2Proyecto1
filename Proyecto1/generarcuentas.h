#ifndef GENERARCUENTAS_H
#define GENERARCUENTAS_H

#include <QWidget>

namespace Ui {
class GenerarCuentas;
}

class GenerarCuentas : public QWidget
{
    Q_OBJECT

public:
    explicit GenerarCuentas(QWidget *parent = nullptr);
    ~GenerarCuentas();

private:
    Ui::GenerarCuentas *ui;
};

#endif // GENERARCUENTAS_H
