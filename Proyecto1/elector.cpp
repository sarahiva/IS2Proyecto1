#include "elector.h"
#include "ui_elector.h"

Elector::Elector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Elector)
{
    ui->setupUi(this);
}

Elector::~Elector()
{
    delete ui;
}
