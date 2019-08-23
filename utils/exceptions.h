#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <QSqlError>
#include <QException>
class QSqlConnectionError : public QException
{
public:
    QSqlConnectionError(QString msg) : message(msg) { }
    void raise() const override { throw *this; }
    QSqlConnectionError *clone() const override { return new QSqlConnectionError(*this); }
    QString qWhat() const { return message; }
   
private:
    QString message;
};


#endif /* EXCEPTIONS_H */
