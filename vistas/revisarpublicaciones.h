#ifndef REVISARPUBLICACIONES_H
#define REVISARPUBLICACIONES_H

#include <QDialog>

namespace Ui {
class RevisarPublicaciones;
}

class QDataWidgetMapper;
class     QSqlQueryModel;
class     QSqlTableModel;
class RevisarPublicaciones : public QDialog
{
    Q_OBJECT

public:
    explicit RevisarPublicaciones(QWidget *parent = nullptr);
    ~RevisarPublicaciones();
private slots:
    void on_next_clicked();
    void on_prev_clicked();
    void on_accept_clicked();
    void on_rechazar_clicked();
private:
    Ui::RevisarPublicaciones *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel *model;
};

#endif // REVISARPUBLICACIONES_H
