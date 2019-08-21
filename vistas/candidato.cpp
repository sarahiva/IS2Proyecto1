#include "candidato.h"
#include "ui_candidato.h"

CandidatoWidget::CandidatoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CandidatoWidget)
{
    ui->setupUi(this);
}

CandidatoWidget::~CandidatoWidget()
{
    delete ui;
}
