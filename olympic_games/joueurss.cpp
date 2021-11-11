#include "joueurss.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<joueurs.h>
Joueurss::Joueurss()
{
id=0;
annees_naissance=0;

}
Joueurss::Joueurss(int id,int annees_naissance,QString nom ,QString prenom,QString nationalite,QString type_sport)
{
   this->id=id;
   this->annees_naissance=annees_naissance;
   this->nom=nom;
   this->prenom=prenom;
   this->nationalite=nationalite;
   this->type_sport=type_sport;
}
int Joueurss::getid(){return id;}
int Joueurss::getannees_naiss(){return annees_naissance;}
QString Joueurss::getnom(){return nom;}
QString Joueurss::getprenom(){return prenom;}
QString Joueurss::getnationalite(){return nationalite;}
QString Joueurss::gettype_sport(){return type_sport;}
void Joueurss::setid(int id){this->id=id;}
void Joueurss::setannees_naiss(int annees_naissance){this->annees_naissance=annees_naissance;}
void Joueurss::setnom(QString nom){this->nom=nom;}
void Joueurss::setprenom(QString prenom){this->prenom=prenom;}
void Joueurss::setnationalite(QString nationalite){this->nationalite=nationalite;}
void Joueurss::settype_sport(QString type_sport){this->type_sport=type_sport;}
bool Joueurss::ajouter()
{
  //bool test=false;
   QSqlQuery query;
   QString id_string=QString::number(id);
    QString annees_string=QString::number(annees_naissance);
         query.prepare("INSERT INTO joueurs (id, annees_naissance,nom,prenom,nationalite,type_sport) "
                       "VALUES (:id, :annees_naissance, :nom, :prenom, :nationalite, :type_sport)");
         query.bindValue(0, id_string);
         query.bindValue(1, annees_string);
         query.bindValue(2,nom);
         query.bindValue(3, prenom);
         query.bindValue(4, nationalite);
         query.bindValue(5,type_sport);
         return  query.exec();



}
QSqlQueryModel * Joueurss::afficher(){



    QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT* FROM joueurs");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("annees_naissance"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("nationalite"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_sport"));


        return model;

}
bool Joueurss::supprimer(int id2)
{
 QSqlQuery query;
 QString res=QString::number(id2);
 query.prepare("delete from joueurs where id= :id");
 query.bindValue(":id",res);
 return query.exec();
}
bool Joueurss::modifier(int id,int annees_naissance,QString nom,QString prenom,QString nationalite,QString type_sport)
{
    QSqlQuery query;

         QString id_string=QString::number(id);
         QString annees_string= QString::number(annees_naissance);
           query.prepare(" UPDATE joueurs set id=:id ,annees_naissance=:annees_naissance,nom=:nom,prenom=:prenom, nationalite=:nationalite,type_sport=:type_sport  where id=:id");
           query.bindValue(":id",id_string);
           query.bindValue(":annees_naissance",annees_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":nationalite",nationalite);
           query.bindValue(":type_sport",type_sport);

           return query.exec();
}
QSqlQueryModel * Joueurss::trierprenom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM joueurs ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("annees_naissance"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_sport"));
    return model;
}
QSqlQueryModel * Joueurss::trierannees()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM joueurs ORDER BY annees_naissance");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("annees_naissance"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_sport"));
    return model;
}
void Joueurss::recherche(QTableView * table, QString nationalite,int annees,QString type_sport)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QString annees_string=QString::number(annees);
        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from joueurs where nationalite like '%"+nationalite+"%' or TYPE_SPORT like '%"+type_sport+"%' or annees_naissance like '%"+annees_string+"%' ;");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}
