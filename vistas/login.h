#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>


namespace Ui{
    class Login;
}

class InicioAdmin;
class CtrlAutenticacion;
class Login : public QDialog
{
    Q_OBJECT

 protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
//  virtual void closeEvent(QCloseEvent *event) override;
    
public:
    explicit Login(CtrlAutenticacion *a, int intentos, QWidget *parent = nullptr);
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    
signals:
    void loggedIn();

private slots:
    void authenticate();
    // void on_salirBtn_clicked();
    
private:
    Ui::Login *ui;
    CtrlAutenticacion *auth;
    int maxtries;
    InicioAdmin *win;
};
#endif /* LOGIN_H */
