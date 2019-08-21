#include "login.h"
#include "ui_login.h"
#include "electorwidget.h"
#include "inicioadmin.h"
#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <QPixmap>
#include <QBitmap>

Login::Login(CtrlAutenticacion *a, int intentos, QWidget *parent)
    : QDialog(parent),      
      ui( new Ui::Login ),
      auth(a),
      maxtries(intentos)
{
    ui->setupUi(this);
    connect(ui->accederBtn, &QPushButton::clicked, this, &Login::authenticate);
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    ui->username->setFocus();
}
Login::Login(QWidget *parent)
    : QDialog(parent),      
      ui( new Ui::Login )
{
    ui->setupUi(this);
    win = new InicioAdmin(this);
    
    connect(ui->accederBtn, &QPushButton::clicked, this, &Login::authenticate);
    connect(this, &Login::loggedIn, win, &InicioAdmin::showMaximized);
    connect(win, &InicioAdmin::logout, this, &Login::show);
    // connect(win, &QWidget::close, this, &Login::show);

}

Login::~Login()    
{
    delete ui;
}

// void Login::closeEvent(QCloseEvent *event)
// {
//     QDialog::closeEvent(event);
// }

void Login::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if (key == Qt::Key_Return || key == Qt::Key_Enter)
    {
        authenticate();
    }
    else
        QDialog::keyPressEvent(event);
    
}

// void Login::on_salirBtn_clicked()
// {
//     emit reject();
//     close();
// }


void Login::authenticate()
{
    QString usrname = ui->username->text();
    QString passw = ui->password->text();

     
    // if(usrname.isEmpty() || passw.isEmpty())
    // {
    //     ui->msgOut->setText("Introduzca los dos campos solicitados " + passw);
    //     return;
    // }
        
    // ui->username->clear();
    // ui->password->clear();
    
    // auto respuesta = auth->autenticar(usrname, passw);
    // int intentos = auth->getLastUserTries();
    // if(respuesta == CtrlAutenticacion::UsuarioBloqueado)
    // {
       
    //     ui->msgOut->setText("Acceso denegado: Cuenta bloqueada");
    //     ui->username->setFocus();
    //     return;
    // }
    
    // if(maxtries == intentos)
    // {
    //     auth->bloquear(usrname);
    //     ui->msgOut->setText("Número de intentos agotado. Su cuenta ha sido bloqueada");
    //     return;
    // }
    

     
    // if(respuesta == CtrlAutenticacion::NombreInvalido)
    // {

    //     ui->msgOut->setText("Nombre de usuario inválido. Intente nuevamente");
    //     ui->username->setFocus();
    //     return;
    // }

    // if(respuesta == CtrlAutenticacion::AccesoDenegado)
    // {     
    //     ui->msgOut->setText("Contraseña incorrecta. Le quedan "
    //                         + QString::number(maxtries - intentos)
    //                         + " intentos.");        
    //     ui->username->setFocus();
    //     return;
    //}
    
         
    emit loggedIn();
    hide() ;
}
