#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("olympic_games");
db.setUserName("hela");//inserer nom de l'utilisateur
db.setPassword("hela");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
