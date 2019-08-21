#ifndef REVISARPUBLICACIONES_H
#define REVISARPUBLICACIONES_H

#include <QDialog>

namespace Ui {
class RevisarPublicaciones;
}

class RevisarPublicaciones : public QDialog
{
    Q_OBJECT

public:
    explicit RevisarPublicaciones(QWidget *parent = nullptr);
    ~RevisarPublicaciones();

private:
    Ui::RevisarPublicaciones *ui;
};

#endif // REVISARPUBLICACIONES_H
