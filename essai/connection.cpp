#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("BDOlympicGames");
db.setUserName("aziz2");//inserer nom de l'utilisateur
db.setPassword("aziz2");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;





    return  test;
}
