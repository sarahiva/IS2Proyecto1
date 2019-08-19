#ifndef INICIOADMIN_H
#define INICIOADMIN_H

#include <QWidget>

namespace Ui {
class InicioAdmin;
}

class InicioAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit InicioAdmin(QWidget *parent = nullptr);
    ~InicioAdmin();

private:
    Ui::InicioAdmin *ui;
};

#endif // INICIOADMIN_H
