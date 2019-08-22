#ifndef CANDIDATOWIDGET_H
#define CANDIDATOWIDGET_H

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

#endif // CANDIDATOWIDGET_H
