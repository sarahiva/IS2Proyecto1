#ifndef NEWELECTIONWIZARD_H
#define NEWELECTIONWIZARD_H

#include <QWizard>

namespace Ui {
    class NewElectionWizard;
}

class NewElectionWizard : public QWizard
{
    Q_OBJECT
    
public:
    
    explicit NewElectionWizard(QWidget *parent=nullptr);
    ~NewElectionWizard();

private:
    Ui::NewElectionWizard *ui;        

};


#endif /* NEWELECTIONWIZARD_H */
