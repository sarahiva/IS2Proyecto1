#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <QWidget>

namespace Ui {
class Candidato;
}

class Candidato : public QWidget
{
    Q_OBJECT

public:
    explicit Candidato(QWidget *parent = nullptr);
    ~Candidato();

private:
    Ui::Candidato *ui;
};

#endif // CANDIDATO_H
