#ifndef ITEMCANDIDATO_H
#define ITEMCANDIDATO_H

#include <QWidget>

namespace Ui {
    class ItemCandidato;
}

class ItemCandidato : public QWidget
{
    Q_OBJECT
    
public:
    explicit ItemCandidato(QWidget *parent=nullptr,
                           QString nombre="",
                           QString partido="",
                           QString emblema="",
                           QString clve="");
    ~ItemCandidato();
    void setdatos(QString nombre, QString partido, QString emblema, QString clve);
private slots:
    void on_votar_clicked();
    void on_verperfil_clicked();
signals:
    void voted();
private:
    Ui::ItemCandidato *ui;        
    QString clave;
};


#endif /* ITEMCANDIDATO_H */
