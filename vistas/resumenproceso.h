#ifndef RESUMENPROCESO_H
#define RESUMENPROCESO_H

#include <QWidget>

namespace Ui {
class ResumenProceso;
}

class ResumenProceso : public QWidget
{
    Q_OBJECT

public:
    explicit ResumenProceso(QWidget *parent = nullptr);
    ~ResumenProceso();

private:
    Ui::ResumenProceso *ui;
};

#endif // RESUMENPROCESO_H
