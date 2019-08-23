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
protected:
        void closeEvent(QCloseEvent *event) override;

private slots:
    void on_createProcBtn_clicked();    
    void on_publiBtn_clicked();
    void on_loadListBtn_clicked();
    void on_genCtasBtn_clicked();
    void on_ctasBtn_clicked();
    void on_cerrarSesionBtn_clicked();
    void on_votarBtn_clicked();
    void on_resultadosBtn_clicked();
    void on_candidatosBtn_clicked();
    void on_adminBtn_clicked();
public slots:
    void login();
signals:
    void logout();
private:
    Ui::InicioAdmin *ui;        

};


#endif /* INCIOADMIN_H */
