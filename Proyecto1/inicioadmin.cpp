#include "inicioadmin.h"
#include "ui_inicioadmin.h"

InicioAdmin::InicioAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InicioAdmin)
{
    ui->setupUi(this);
}

InicioAdmin::~InicioAdmin()
{
    delete ui;
}
