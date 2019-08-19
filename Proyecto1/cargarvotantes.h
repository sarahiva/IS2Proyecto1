#ifndef CARGARVOTANTES_H
#define CARGARVOTANTES_H

#include <QWidget>

namespace Ui {
class CargarVotantes;
}

class CargarVotantes : public QWidget
{
    Q_OBJECT

public:
    explicit CargarVotantes(QWidget *parent = nullptr);
    ~CargarVotantes();

private:
    Ui::CargarVotantes *ui;
};

#endif // CARGARVOTANTES_H
