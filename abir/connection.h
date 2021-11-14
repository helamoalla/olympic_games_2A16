#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase> // fournit la connexion entre qt et la base de donnée
#include <QSqlError> //elle permet d'afficher les erreurs
#include <QSqlQuery>

class Connection
{
private:
    QSqlDatabase db; //attribut de type   QSqlDatabase
public:
    Connection();
    bool creatconnection();


};

#endif // CONNECTION_H
