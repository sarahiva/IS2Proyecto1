#ifndef CONSULTARCUENTAS_H
#define CONSULTARCUENTAS_H

#include <QDialog>
class QSortFilterProxyModel;
class QSqlTableModel;
namespace Ui {
class ConsultarCuentas;
}

class ConsultarCuentas : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultarCuentas(QWidget *parent = nullptr);
    ~ConsultarCuentas();
private slots:
    void on_tableView_clicked(const QModelIndex &idx);
    void on_eliminar_clicked();
    void on_lineEdit_textChanged(const QString &str);
private:
    void clear();
    Ui::ConsultarCuentas *ui;
    QSqlTableModel *model;
    QSortFilterProxyModel *proxymodel;
};

#endif // CONSULTARCUENTAS_H
