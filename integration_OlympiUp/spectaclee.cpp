#include "spectaclee.h"
#include <QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<mainwindow.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
Spectaclee::Spectaclee()
{
idE=0; duree=0; horaire=" "; type=" ";

}

Spectaclee::Spectaclee(int idE,int duree,QString horaire,QString type){
   this->idE=idE;
   this->duree=duree;
   this->horaire=horaire;
   this->type=type;}
int Spectaclee ::getidE(){return idE;}
int Spectaclee ::getduree(){return duree;}
QString Spectaclee ::gethoraire(){return horaire;}
QString Spectaclee ::gettype(){return type;}
  void Spectaclee ::setid(int idE){this->idE=idE;}
  void Spectaclee ::setduree(int duree){this->duree=duree;}
  void Spectaclee ::sethoraire(QString horaire){this->horaire=horaire;}
  void Spectaclee ::settype(QString type){this->type=type;}
  bool Spectaclee ::ajouter()
  {

      QSqlQuery query;
     QString num_string= QString::number(idE);
     QString duree_string= QString::number(duree);


            query.prepare("INSERT INTO SPECTACLE (num, duree, horaire , type) "
                          "VALUES (:id, :duree, :horaire ,:type)");
            query.bindValue(":id", idE);
            query.bindValue(":duree", duree);
            query.bindValue(":horaire", horaire);
            query.bindValue(":type", type);
            return query.exec();
 }

  QSqlQueryModel* Spectaclee::afficher(){

      QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery("SELECT* FROM SPECTACLE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


      return model;
  }
        bool Spectaclee::supprimer(int idE){
        QSqlQuery query;
        QString res=QString::number(idE);




         query.prepare("Delete from SPECTACLE where num=:num");
         query.bindValue(":num", res);

      return  query.exec();



  }

        bool Spectaclee::modifier(int idE,int duree,QString horaire,QString type){
            QSqlQuery query;


            QString id_string= QString::number(idE);
            QString duree_string= QString::number(duree);




            query.prepare(" UPDATE SPECTACLE set num=:num ,duree=:duree,horaire=:horaire ,type=:type where num=:num");
               query.bindValue(":num", idE);
               query.bindValue(":duree", duree);
               query.bindValue(":horaire", horaire);
               query.bindValue(":type", type);

               return query.exec();
        }



        QSqlQueryModel * Spectaclee::triehoraire()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM SPECTACLE ORDER BY HORAIRE");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("HORAIRE"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));

            return model;
        }
        QSqlQueryModel * Spectaclee::trieduree()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM SPECTACLE ORDER BY DUREE");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("HORAIRE"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
            return model;
        }
        QSqlQueryModel * Spectaclee::trietype()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
            model->setQuery("SELECT * FROM SPECTACLE ORDER BY TYPE");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("HORAIRE"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
            return model;
        }




        void Spectaclee :: recherche(QTableView * table ,QString nom,int num,QString nom1 )
        {
            QSqlQueryModel *model= new QSqlQueryModel();
            QString num_string=QString::number(num);


            QSqlQuery *query=new QSqlQuery;
            query->prepare("select * from SPECTACLE where NUM like '%"+nom+"%'  or DUREE like '%"+num_string+"%'or TYPE like '%"+nom1+"%';");


            query->exec();
            model->setQuery(*query);
            table->setModel(model);
            table->show();

        }



        void  Spectaclee::telechargerEXCEL(){


                             QPdfWriter pdf("C:\\Users\\helam\\OneDrive\\Bureau\\export_pdf\\export_EXCEL.xlsx");
                             QPainter painter(&pdf);
                            int i = 4000;
                                 painter.setPen(Qt::blue);
                                 painter.setFont(QFont("Arial", 30));
                                 painter.drawText(1100,1200,"SPECTACLE");
                                 painter.setPen(Qt::black);
                                 painter.setFont(QFont("Arial",14));
                                 painter.drawRect(100,100,7300,2600);
                                 painter.drawRect(0,3000,9600,500);
                                 painter.setFont(QFont("Arial",11));
                                 painter.drawText(200,3300,"NUM");
                                 painter.drawText(1300,3300,"DUREE");
                                 painter.drawText(2200,3300,"HORAIRE");
                                 painter.drawText(3200,3300,"TYPE");


                                 QSqlQuery query;
                                 //query.prepare("select * from spectacle where id='"+val+"'");
                                 query.prepare("select * from spectacle");
                                 query.exec();
                                 while (query.next())
                                 {
                                     painter.drawText(200,i,query.value(0).toString());
                                     painter.drawText(1300,i,query.value(2).toString());
                                     painter.drawText(2200,i,query.value(3).toString());
                                     painter.drawText(3200,i,query.value(1).toString());



                                    i = i + 500;
                                 }}
