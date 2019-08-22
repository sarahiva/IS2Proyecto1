#ifndef PERFILCANDIDATO_H
#define PERFILCANDIDATO_H

#include <QDialog>

namespace Ui {
class PerfilCandidato;
}

class PerfilCandidato : public QDialog
{
    Q_OBJECT

public:
    explicit PerfilCandidato(QWidget *parent = nullptr);
    ~PerfilCandidato();

private:
    Ui::PerfilCandidato *ui;
};

#endif // PERFILCANDIDATO_H
