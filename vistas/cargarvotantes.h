#ifndef CARGARVOTANTES_H
#define CARGARVOTANTES_H

#include <QDialog>

namespace Ui {
class CargarVotantes;
}

class CargarVotantes : public QDialog
{
    Q_OBJECT

public:
    explicit CargarVotantes(QWidget *parent = nullptr);
    ~CargarVotantes();
private slots:
    void on_cargar_clicked();
    void on_registrar_clicked();
    
private:
    Ui::CargarVotantes *ui;
};

#endif // CARGARVOTANTES_H
