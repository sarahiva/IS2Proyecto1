#ifndef PERFILCANDIDATO_H
#define PERFILCANDIDATO_H

#include <QWidget>

namespace Ui {
class PerfilCandidato;
}

class PerfilCandidato : public QWidget
{
    Q_OBJECT

public:
    explicit PerfilCandidato(QWidget *parent = nullptr);
    ~PerfilCandidato();

private:
    Ui::PerfilCandidato *ui;
};

#endif // PERFILCANDIDATO_H
