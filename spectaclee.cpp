#include "spectaclee.h"
#include <QString>
#include<QSqlQuery>
#include<QtDebug>
Spectaclee::Spectaclee()
{
Num=0; duree=0;horaire="";type="";

}

Spectaclee::Spectaclee(int Num,int duree,QString horaire,QString type){
   this->Num=Num;
   this->duree=duree;
   this->horaire=horaire;
   this->type=type;}
int Spectaclee::getNum(){return Num;}
int Spectaclee::getduree(){return duree;}
QString Spectaclee::gethoraire(){return horaire;}
QString Spectaclee::gettype(){return type;}
  void Spectaclee::setNum(int Num){this->Num=Num;}
  void Spectaclee::setduree(int duree){this->duree=duree;}
  void Spectaclee::sethoraire(QString horaire){this->horaire=horaire;}
  void Spectaclee::settype(QString type){this->type=type;}
  bool Spectaclee::ajouter()
  {

      QSqlQuery query;
     QString num_string= QString::number(Num);
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
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


      return model;
  }
  bool Spectaclee::supprimer(int id){
        QSqlQuery query;
        QString res=QString::number(id);




      query.prepare("Delete from Fournisseur where id=:id");
      query.bindValue(":id", res);

      return  query.exec();



  }




