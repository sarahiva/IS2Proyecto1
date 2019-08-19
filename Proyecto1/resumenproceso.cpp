#include "resumenproceso.h"
#include "ui_resumenproceso.h"

ResumenProceso::ResumenProceso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResumenProceso)
{
    ui->setupUi(this);
}

ResumenProceso::~ResumenProceso()
{
    delete ui;
}
