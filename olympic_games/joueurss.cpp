#include "joueurss.h"
#include <QSqlQuery>
#include <QtDebug>
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
bool Joueurss::supprimer(int id)
{
 QSqlQuery query;
 QString res=QString::number(id);
 query.prepare("delete from joueurs where id= : id");
 query.bindValue(":id",res);
 return query.exec();
}
