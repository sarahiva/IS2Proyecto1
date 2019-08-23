#include "crearprocesoelec.h"
#include "ui_crearprocesoelec.h"


#include "controles/ctrlprocesoelectoral.h"
#include "modelos/eleccion.h"
#include "utils/csv.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include <QDebug>
#include <QSqlError>
#include <QStringListModel>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDataWidgetMapper>
#include <QMessageBox>

CrearProcesoElec::CrearProcesoElec(QWidget *parent)
    : QDialog(parent),
      ui (new Ui::CrearProcesoElec),
      eleccion(nullptr)
{
    ui->setupUi(this);
    ui->horaIni->setTime(QTime::currentTime());
    ui->horaFin->setTime(QTime::currentTime().addSecs(24 * 60 * 60));
    
}



void CrearProcesoElec::setupModel(int id)
{
    ideleccion = id;
    ui->crearBtn->setText("Actulizar");
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    model2 =  new QSqlQueryModel;
    QString q = "SELECT * FROM Eleccion WHERE idEleccion=%1";
    model2->setQuery( q.arg(id));
    mapper =  new QDataWidgetMapper(this);
    mapper->setModel(model2);
    mapper->addMapping(ui->calendario, 1, "selectedDate");
    mapper->addMapping(ui->horaIni, 2, "time");
    mapper->addMapping(ui->horaFin, 2, "time");
    mapper->toFirst();
}


CrearProcesoElec::~CrearProcesoElec()
{
    delete ui;

    
}

void CrearProcesoElec::on_loadFileBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Abrirarchivo de Candidatos", "./", tr("Archivos CSV (*.csv)"));
    if(!filename.isNull())
    {
        qDebug() << "LISTA VALIDA: " << filename;
        ui->filename->setText(filename);
        QStringList list;
        // char *line;
        // io::CSVReader<5> linereader(filename.toStdString());
        io::LineReader linereader(filename.toStdString());

        while(char*line = linereader.next_line()){
            list << line;
            ui->listWidget->addItem(QString::fromLocal8Bit(line));
        }
        // linereader.read_header(io::ignore_missing_column,
        //                        "ClaveCandidato",
        //                        "nombre",
        //                        "apaterno",
        //                        "amaterno",
        //                        "partido");
        // std::string nombre, apaterno, amaterno, partido, clave;
        // QString formatlist("%1 %2 %3 % - %4");
        // while(linereader.read_row(clave,nombre, apaterno, amaterno))
        // {
        //     qDebug() << formatlist
        //         .arg(QString::fromStdString(nombre))
        //         .arg(QString::fromStdString(apaterno))
        //         .arg(QString::fromStdString(amaterno))
        //         .arg(QString::fromStdString(partido));
        //     list << QString(line);
        // }
        
    }
    // qDebug() << "LISTA INVALIDA";


}

void CrearProcesoElec::on_crearBtn_clicked()
{
    QString filename = ui->filename->text();
    if(filename.isNull())
        return;
    
    using namespace Controles;
    if(eleccion == nullptr)
        eleccion = CtrlProcesoElectoral
            ::crearProcesoElectoral(ui->calendario->selectedDate(),
                                    ui->horaIni->time(),
                                    ui->horaFin->time());

    QSqlDatabase db = QSqlDatabase::database("eleccion", true);

    QSqlQuery query(db);
    query.prepare("LOAD DATA LOCAL INFILE :infile INTO TABLE Candidato"
                  " FIELDS TERMINATED BY ',' LINES TERMINATED BY "
                  "'\n' IGNORE 1 ROWS "
                  "(claveCandidato, nombre, apaterno, amaterno, partido, emblema, "
                  "foto,idUsuario, cantidadVotos ) SET idEleccion= :id");
    query.bindValue(":infile", filename);
    query.bindValue(":id", eleccion->getID());
    query.exec();
    QMessageBox::information(this, "Proceso finalizado", "Se ha creado exitosamente el proceso electoral.");
    close();
}
