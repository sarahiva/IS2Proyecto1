#ifndef INCIOADMIN_H
#define INCIOADMIN_H

#include <QMainWindow>

namespace Ui {
    class InicioAdmin;
}

class InicioAdmin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InicioAdmin(QWidget *parent=nullptr);
    ~InicioAdmin();


private slots:
    void on_createProcBtn_clicked();    
    void on_publiBtn_clicked();

    void on_loadListBtn_clicked();

    void on_genCtasBtn_clicked();

    void on_ctasBtn_clicked();

    void on_cerrarSesionBtn_clicked();
signals:
    void logout();
private:
    Ui::InicioAdmin *ui;        

};


#endif /* INCIOADMIN_H */
