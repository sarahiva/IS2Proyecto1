#ifndef ITEMRESULTADOS_H
#define ITEMRESULTADOS_H

#include <QWidget>

namespace Ui {
    class ItemResultados;
}

class ItemResultados : public QWidget
{
    
    Q_OBJECT
    
public:

    explicit ItemResultados(QWidget *parent=nullptr,
                            QString nombre="",
                            QString partido = "",
                            QString emblema = "",
                            QString foto = "", 
                            int votos = 0,
                            double porcentaje=0.0);
    ~ItemResultados();

private:
    Ui::ItemResultados *ui;        

};


#endif /* ITEMRESULTADOS_H */
