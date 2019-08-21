#ifndef CREARPROCESOELEC_H
#define CREARPROCESOELEC_H

#include <QDialog>


namespace Ui {
    class CrearProcesoElec;
}

class CrearProcesoElec : public QDialog
{
    Q_OBJECT
    
public:
    explicit CrearProcesoElec(QWidget *parent=nullptr);
    ~CrearProcesoElec();
private slots:
    void on_loadFileBtn_clicked();
    void on_publiBtn_clicked();
private:
    Ui::CrearProcesoElec *ui;        

};

#endif /* CREARPROCESOELEC_H */
