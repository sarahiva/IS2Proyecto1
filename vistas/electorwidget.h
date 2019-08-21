#ifndef ELECTORWIDGET_H
#define ELECTORWIDGET_H

#include <QWidget>

namespace Ui {
class ElectorWidget;
}

class ElectorWidget : public QWidget
{
    Q_OBJECT

protected:
        void closeEvent(QCloseEvent *event) override;
    
public:
    explicit ElectorWidget(QWidget *parent = nullptr);
    ~ElectorWidget();
    
private:
    Ui::ElectorWidget *ui;
};

#endif // ELECTORWIDGET_H
