#include "Competitions.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Competitions::Competitions()
{

}
Competitions::Competitions(int numero,QString equipe1,QString equipe2,QString reference,QString mail,int temps,int score)
{
    this->numero=numero;
     this ->equipe1=equipe1;
    this->equipe2=equipe2;
    this->reference=reference;
    this->score=score;
    this->mail=mail;
    this->temps=temps;
}

int Competitions::getnumero(){return numero;}
QString Competitions:: getequipe1(){return equipe1;}
QString Competitions::getequipe2(){return equipe2;}
QString Competitions::getreference(){return reference;}
int Competitions::getscore(){return score;}
QString Competitions::getmail(){return mail;}
int Competitions::gettemps(){return temps;}
void Competitions::setnumero(int numero){this->numero= numero;}
void Competitions::setequipe1(QString equipe1){this->equipe1=equipe1;}
void Competitions::setequipe2(QString equipe2){this->equipe2=equipe2;}
void Competitions::setreference(QString reference){this->reference=reference;}
void Competitions::setscore(int score){this->score=score;}
void Competitions::setmail(QString mail){this->mail=mail;}
void Competitions::settemps(int temps){this->temps= temps;}
bool Competitions::ajouter()
{

     QSqlQuery query;


          query.prepare("INSERT INTO competitions (numero,equipe1,equipe2,reference,mail,temps,score) "
                        "VALUES (:numero,:equipe1,:equipe2,:reference,:mail,:temps,:score)");
          query.bindValue(":numero",numero);
          query.bindValue(":equipe1",equipe1);
          query.bindValue(":equipe2",equipe2);
          query.bindValue(":reference",reference);
          query.bindValue(":mail",mail);
          query.bindValue(":temps",temps);
             query.bindValue(":score",score);
          return query.exec();


}

QSqlQueryModel* Competitions::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT* FROM Competitions");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("equipe1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("equipe2"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("reference"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("temps"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("score"));

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



QSqlQueryModel * Competitions::trierTemps()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Competitions ORDER BY temps");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("equipe1"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("equipe2"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("temps"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("score"));




    return model;
}
QSqlQueryModel * Competitions::trier_score()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Competitions ORDER BY score");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("equipe1"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("equipe2"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("temps"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("score"));


    return model;
}
QSqlQueryModel * Competitions::trier_equipe()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Competitions ORDER BY equipe1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("equipe1"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("equipe2"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("temps"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("score"));


    return model;
}

void Competitions::recherche(QTableView * table, int score)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QString numero_string=QString::number(score);
        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from Competitions where numero like '%"+numero_string+"%';");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}

QSqlQueryModel * Competitions::rechercheavancee(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Competitions where(numero LIKE '"+id+"%') or (equipe1 LIKE'"+id+"%') or (equipe2 LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("equipe1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("equipe2"));



    return model;
}
