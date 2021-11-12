#include "Competitions.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Competitions::Competitions()
{ numero =0;
 equipe1="";
 equipe2="";
}
Competitions::Competitions(int numero,QString equipe1,QString equipe2)
{
    this->numero=numero;
     this ->equipe1=equipe1;
    this->equipe2=equipe2;
}

int Competitions::getnumero(){return numero;}
QString Competitions:: getequipe1(){return equipe1;}
QString Competitions::getequipe2(){return equipe2;}

void Competitions::setnumero(int numero){this->numero= numero;}
void Competitions::setequipe1(QString equipe1){this->equipe1=equipe1;}
void Competitions::setequipe2(QString equipe2){this->equipe2=equipe2;}

bool Competitions::ajouter()
{

     QSqlQuery query;
    QString numero_string=QString::number(numero);
          query.prepare("INSERT INTO competitions (numero, equipe1, equipe2) "
                        "VALUES (:numero, :equipe1, :equipe2)");
          query.bindValue(":numero", numero_string);
          query.bindValue(":equipe1", "equipe1");
          query.bindValue(":equipe2", "equipe2");
          return query.exec();


}

QSqlQueryModel* Competitions::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT* FROM Competitions");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("equipe1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("equipe2"));

    return model;
}
bool Competitions::supprimer(int numero)
{
    QSqlQuery query;
    QString res = QString::number(numero);


    query.prepare("DELETE FROM Competitions where NUMERO=:numero");
    query.bindValue(":numero", res);

    return query.exec();
}

bool Competitions::modifier(int numero,QString equipe1,QString equipe2)
{
    QSqlQuery query;
     QString id_string= QString::number(numero);

       query.prepare(" UPDATE Competitions set numero=:numero , equipe1=equipe1, equipe2=equipe2  where numero=:numero");
       query.bindValue(":numero",id_string);
       query.bindValue(":equipe1",equipe1);
       query.bindValue(":equipe2",equipe2);

       return query.exec();
}

