#include "ui_newelectionwizard.h"
#include "newelectionwizard.h"

NewElectionWizard::NewElectionWizard(QWidget *parent)
    : QWizard(parent),
      ui( new Ui::NewElectionWizard)
{
    ui->setupUi(this);
}

NewElectionWizard::~NewElectionWizard()
{
    delete ui;
}
