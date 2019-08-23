#ifndef CANDIDATOWIDGET_H
#define CANDIDATOWIDGET_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class CandidatoWidget;
}


class QSqlQueryModel;
class CandidatoWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CandidatoWidget(QWidget *parent = nullptr);
    ~CandidatoWidget();
    void loadCandidato();
private slots:
    void on_guardar_clicked();
    void on_textEdit_textChanged();
    void on_solicitar_clicked();
private:
    Ui::CandidatoWidget *ui;
    QSqlQueryModel *model;
    int currentfolio;
    QString candidato;
    int eleccion;
    
};

#endif // CANDIDATOWIDGET_H
