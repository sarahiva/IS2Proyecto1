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
    explicit ItemCandidato(QWidget *parent=nullptr);
    ~ItemCandidato();
    void setdatos(QString nombre, QString partido, QString emblema);
private:
    Ui::ItemCandidato *ui;        

};


#endif /* ITEMCANDIDATO_H */
