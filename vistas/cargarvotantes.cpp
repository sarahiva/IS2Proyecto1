#include "cargarvotantes.h"
#include "ui_cargarvotantes.h"

#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

CargarVotantes::CargarVotantes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargarVotantes)
{
    ui->setupUi(this);
}

CargarVotantes::~CargarVotantes()
{
    delete ui;
}


void CargarVotantes::on_cargar_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Abrirarchivo de Candidatos", "./", tr("Archivos CSV (*.csv)"));
    if(!filename.isNull())
    {
        ui->filename->setText(filename);
    }
}
void CargarVotantes::on_registrar_clicked()
{
    QString filename = ui->filename->text();
    if(filename.isNull())
        return;
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(db);
    query.prepare("LOAD DATA LOCAL INFILE :infile INTO TABLE Elector"
                  " FIELDS TERMINATED BY ',' ENCLOSED BY '\"'"
                  " LINES TERMINATED BY '\n' IGNORE 1 ROWS "
                  "(claveElector,nombre,apaterno,amaterno,yaVoto,idUsuario)");
    query.bindValue(":infile", filename);
    query.exec();
    close();
}
