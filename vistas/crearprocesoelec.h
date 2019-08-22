#ifndef CREARPROCESOELEC_H
#define CREARPROCESOELEC_H

namespace Modelos {
    class Eleccion;
}

#include <QDialog>

namespace Ui {
    class CrearProcesoElec;
}
class QStringListModel;

class CrearProcesoElec : public QDialog
{
    Q_OBJECT
    
public:
    explicit CrearProcesoElec(QWidget *parent=nullptr);
    ~CrearProcesoElec();
private slots:
    void on_loadFileBtn_clicked();
    void on_crearBtn_clicked();
private:
    Ui::CrearProcesoElec *ui;        
    Modelos::Eleccion *eleccion;
    QStringListModel *model;
};

#endif /* CREARPROCESOELEC_H */
