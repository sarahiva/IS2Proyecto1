#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <QWidget>

namespace Ui {
class CandidatoWidget;
}

class CandidatoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CandidatoWidget(QWidget *parent = nullptr);
    ~CandidatoWidget();

private:
    Ui::CandidatoWidget *ui;
};

#endif // CANDIDATO_H
