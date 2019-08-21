#ifndef MODIFICARPROCESO_H
#define MODIFICARPROCESO_H

#include <QWidget>

namespace Ui {
class ModificarProceso;
}

class ModificarProceso : public QWidget
{
    Q_OBJECT

public:
    explicit ModificarProceso(QWidget *parent = nullptr);
    ~ModificarProceso();

private:
    Ui::ModificarProceso *ui;
};

#endif // MODIFICARPROCESO_H
