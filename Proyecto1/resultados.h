#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <QWidget>

namespace Ui {
class Resultados;
}

class Resultados : public QWidget
{
    Q_OBJECT

public:
    explicit Resultados(QWidget *parent = nullptr);
    ~Resultados();

private:
    Ui::Resultados *ui;
};

#endif // RESULTADOS_H