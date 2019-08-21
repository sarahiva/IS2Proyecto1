#include "login.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QFile>
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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "elecciones");
    db.setHostName("localhost");
    db.setUserName("adminer");
    db.setPassword("anubis%082334");
    db.setDatabaseName("elecciones");

    QFile stylesheet(":/estilos/ubuntu.qss");
    stylesheet.open(QFile::ReadOnly);
    QString stylestr = QLatin1String(stylesheet.readAll());
    app.setStyleSheet(stylestr);
    stylesheet.close();
    Login login;
    login.show();
    return app.exec();
    
}
