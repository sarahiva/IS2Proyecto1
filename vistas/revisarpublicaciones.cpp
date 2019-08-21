#include "revisarpublicaciones.h"
#include "ui_revisarpublicaciones.h"

RevisarPublicaciones::RevisarPublicaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RevisarPublicaciones)
{
    ui->setupUi(this);
}

RevisarPublicaciones::~RevisarPublicaciones()
{
    delete ui;
}
