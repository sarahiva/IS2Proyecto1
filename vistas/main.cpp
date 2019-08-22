#include "login.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    // Información de la aplicación
    // Necesaria para guardar opciones
    
    QApplication app(argc, argv);
    app.setOrganizationName("");
    app.setOrganizationDomain("");
    app.setApplicationName("QVote");
    app.setApplicationVersion("0.5b");
    
    // Localización de la aplicación de acuerdo al sistema
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    //Base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "eleccion");
    db.setHostName("localhost");
    db.setUserName("adminer");
    db.setPassword("anubis%082334");
    db.setPort(3306);
    db.setDatabaseName("elecciones");

    db.open();
    qDebug() << db.lastError().text();
    qDebug()  << db;
    

    QFile stylesheet(":/estilos/ubuntu.qss");
    stylesheet.open(QFile::ReadOnly);
    QString stylestr = QLatin1String(stylesheet.readAll());
    app.setStyleSheet(stylestr);
    stylesheet.close();
    Login login;
    if(login.exec())
    {
        return 0;
    }
    return app.exec();
    
}
