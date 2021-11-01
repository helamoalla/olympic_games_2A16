#include "spectaclee.h"
#include <QString>
#include<QSqlQuery>
#include<QtDebug>
Spectaclee::Spectaclee()
{
num=0; duree=0;horaire="";type="";

}

Spectaclee::Spectaclee(int num,int duree,QString horaire,QString type){
   this->num=num;
   this->duree=duree;
   this->horaire=horaire;
   this->type=type;}
int Spectaclee::getNum(){return num;}
int Spectaclee::getduree(){return duree;}
QString Spectaclee::gethoraire(){return horaire;}
QString Spectaclee::gettype(){return type;}
  void Spectaclee::setNum(int num){this->num=num;}
  void Spectaclee::setduree(int duree){this->duree=duree;}
  void Spectaclee::sethoraire(QString horaire){this->horaire=horaire;}
  void Spectaclee::settype(QString type){this->type=type;}
  bool Spectaclee::ajouter()
  {

      QSqlQuery query;
     QString num_string= QString::number(num);
     QString duree_string= QString::number(duree);
            query.prepare("INSERT INTO SPECTACLE (num, duree, horaire , type) "
                          "VALUES (:num, :duree, :horaire ,:type)");
            query.bindValue(0, num_string );
            query.bindValue(1, duree_string);
            query.bindValue(2, horaire);
            query.bindValue(3, type);

            return query.exec();



  }
  QSqlQueryModel* Spectaclee::afficher(){

      QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery("SELECT* FROM SPECTACLE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


      return model;
  }
  bool Spectaclee::supprimer(int num){
        QSqlQuery query;
        QString res=QString::number(num);




      query.prepare("Delete from SPECTACLE where num=:num");
      query.bindValue(":num", res);

      return  query.exec();



  }




