#include "consultarcuentas.h"
#include "ui_consultarcuentas.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSortFilterProxyModel>
ConsultarCuentas::ConsultarCuentas(QWidget *parent) :
   QDialog(parent),
    ui(new Ui::ConsultarCuentas)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    model = new QSqlTableModel(this, db);
    model->setTable("vUsuarios");
    model->select();
    proxymodel = new QSortFilterProxyModel(this);
    proxymodel->setSourceModel(model);
    proxymodel->setFilterKeyColumn(-1); /// Filtrar todas por todas las columnas
    proxymodel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(proxymodel);
    ui->tableView->setSortingEnabled(true);
    // ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    model->setHeaderData(model->fieldIndex("usr"), Qt::Horizontal, tr("ID"));
    model->setHeaderData(model->fieldIndex("usrnombre"), Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(model->fieldIndex("pass"), Qt::Horizontal, tr("Password"));
    clear();
    ui->passw->hide();
}

ConsultarCuentas::~ConsultarCuentas()
{
    delete ui;
}

void ConsultarCuentas::on_lineEdit_textChanged(const QString &str)
{
   proxymodel->setFilterRegExp(str);        
}

void ConsultarCuentas::on_tableView_clicked(const QModelIndex &idx)
{
    ui->ID->setText(idx.siblingAtColumn(0).data().toString());
    ui->nombre->setText(idx.siblingAtColumn(1).data().toString());
    int tipo = idx.siblingAtColumn(3).data().toInt();
    QString stipo;
    if(tipo == 1 )
        stipo ="Administrador";
    else if(tipo == 2)
        stipo = "Candidato";
    else
        stipo = "Elector";

    ui->tipousr->setText(stipo);
    
}


void ConsultarCuentas::on_eliminar_clicked()
{
    QModelIndex idx = ui->tableView->selectionModel()->currentIndex();
    QString nombre = idx.siblingAtColumn(1).data().toString();
    int usrid = idx.siblingAtColumn(4).data().toInt();
    int res = QMessageBox::warning(this, "¡Cuidado!", tr("Está a punto de eliminar al usuario %1.\n¿Desea continuar?").arg(nombre));
    if (res == QMessageBox::No)
        return;
    QSqlDatabase db = QSqlDatabase::database("eleccion", true);
    QSqlQuery query(nullptr, db);
    query.prepare("DELETE FROM Usuario WHERE idUsuario = :id");
    query.bindValue(":id", usrid);
    if(query.exec())
    {
        QMessageBox::information(this, "Operación exitosa", tr("Se eliminó a %1 correctamente").arg(nombre));
        model->select();
        clear();
    }

    
}


void ConsultarCuentas::clear()
{
    ui->ID->setText("");
    ui->nombre->setText("");
    ui->tipousr->setText("");
}
