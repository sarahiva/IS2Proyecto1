#include "electorwidget.h"
#include "ui_electorwidget.h"
#include <QMessageBox>
#include <QCloseEvent>

ElectorWidget::ElectorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElectorWidget)
{
    ui->setupUi(this);
//    connect(ui->ButtonCerrarSesion, &QPushButton::clicked, this, &ElectorWidget::close);
}

ElectorWidget::~ElectorWidget()
{
    delete ui;
}


void ElectorWidget::closeEvent(QCloseEvent *event)
{

    int res = QMessageBox::question(this, tr("Cerrar Sesión"), "¿Está seguro que desea salir?");
    if(res == QMessageBox::Yes)
    {

        event->accept();        
    }
    else
        event->ignore();

}
