#ifndef ELECTOR_H
#define ELECTOR_H

#include <QWidget>

namespace Ui {
class Elector;
}

class Elector : public QWidget
{
    Q_OBJECT

public:
    explicit Elector(QWidget *parent = nullptr);
    ~Elector();

private:
    Ui::Elector *ui;
};

#endif // ELECTOR_H
