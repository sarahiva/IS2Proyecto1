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
    explicit PerfilCandidato(QWidget *parent = nullptr, QString idCandidato="");
    ~PerfilCandidato();

private:
    Ui::PerfilCandidato *ui;
    QString id;
};

#endif // PERFILCANDIDATO_H
