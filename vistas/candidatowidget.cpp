#include "candidatowidget.h"
#include "ui_candidatowidget.h"

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
