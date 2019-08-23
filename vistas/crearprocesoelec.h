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
class QDataWidgetMapper;
class QSqlTableModel;
class QSqlQueryModel;
class CrearProcesoElec : public QDialog
{
    Q_OBJECT
    
public:
    explicit CrearProcesoElec(QWidget *parent=nullptr);
    void setupModel(int id);
    ~CrearProcesoElec();
private slots:
    void on_loadFileBtn_clicked();
    void on_crearBtn_clicked();
private:    
    Ui::CrearProcesoElec *ui;        
    Modelos::Eleccion *eleccion;
    QSqlQueryModel  *model2;
    QDataWidgetMapper *mapper;
    int ideleccion;
};

#endif /* CREARPROCESOELEC_H */
