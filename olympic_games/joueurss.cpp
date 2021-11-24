#include "joueurss.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<joueurs.h>
//#include <QIntValidator>
//#include <QSystemTrayIcon>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>

Joueurss::Joueurss()
{
id=0;
annees_naissance=0;

}
Joueurss::Joueurss(int id,int annees_naissance,int score,QString nom ,QString prenom,QString nationalite,QString type_sport,QString equipe)
{
   this->id=id;
   this->annees_naissance=annees_naissance;
   this->score=score;
   this->equipe=equipe;
   this->nom=nom;
   this->prenom=prenom;
   this->nationalite=nationalite;
   this->type_sport=type_sport;
}
int Joueurss::getid(){return id;}
int Joueurss::getannees_naiss(){return annees_naissance;}
int Joueurss::getscore(){return score;}
QString Joueurss::getequipe(){return equipe;}
QString Joueurss::getnom(){return nom;}
QString Joueurss::getprenom(){return prenom;}
QString Joueurss::getnationalite(){return nationalite;}
QString Joueurss::gettype_sport(){return type_sport;}
void Joueurss::setid(int id){this->id=id;}
void Joueurss::setannees_naiss(int annees_naissance){this->annees_naissance=annees_naissance;}
void Joueurss::setscore(int score){this->score=score;}
void Joueurss::setequipe(QString equipe){this->equipe=equipe;}
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
    QString score_string=QString::number(score);
         query.prepare("INSERT INTO joueurs (id, annees_naissance,nom,prenom,nationalite,type_sport,equipe,score) "
                       "VALUES (:id, :annees_naissance, :nom, :prenom, :nationalite, :type_sport, :equipe, :score)");
         query.bindValue(0, id_string);
         query.bindValue(1, annees_string);
         query.bindValue(2,nom);
         query.bindValue(3, prenom);
         query.bindValue(4, nationalite);
         query.bindValue(5,type_sport);
         query.bindValue(6, equipe);
         query.bindValue(7,score_string);
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
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("equipe"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("score"));


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
bool Joueurss::modifier(int id,int annees_naissance,int score,QString nom,QString prenom,QString nationalite,QString type_sport,QString equipe)
{
    QSqlQuery query;

         QString id_string=QString::number(id);
         QString annees_string= QString::number(annees_naissance);
         QString score_string= QString::number(score);
           query.prepare(" UPDATE joueurs set id=:id ,annees_naissance=:annees_naissance,score=:score,nom=:nom,prenom=:prenom, nationalite=:nationalite,type_sport=:type_sport,equipe=:equipe  where id=:id");
           query.bindValue(":id",id_string);
           query.bindValue(":annees_naissance",annees_string);
           query.bindValue(":score",score_string);
           query.bindValue(":equipe",equipe);
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
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("equipe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("score"));
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
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("equipe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("score"));
    return model;
}
QSqlQueryModel * Joueurss::trierscore()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM joueurs ORDER BY score");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("annees_naissance"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_sport"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("equipe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("score"));
    return model;
}
void Joueurss::recherche(QTableView * table, QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();

        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from joueurs where nationalite like '%"+rech+"%' or TYPE_SPORT like '%"+rech+"%' or annees_naissance like '%"+rech+"%' ;");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}
void  Joueurss::telechargerPDF(){


                     QPdfWriter pdf("C:\\Users\\helam\\OneDrive\\Bureau\\export_pdf\\export_pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"LISTES DES JOUEUR");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"ID");
                         painter.drawText(1300,3300,"NOM");
                         painter.drawText(2200,3300,"PRENOM");
                         painter.drawText(3200,3300,"ANNEES_NAISSANCE");
                         painter.drawText(5300,3300,"NATIONALITE");
                         painter.drawText(6700,3300,"TYPE_SPORT");
                         painter.drawText(7000,3300,"EQUIPE");
                         painter.drawText(7500,3300,"SCORE");

                         QSqlQuery query;
                         //query.prepare("select * from joueurs where id='"+val+"'");
                         query.prepare("select * from joueurs");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(2).toString());
                             painter.drawText(2200,i,query.value(3).toString());
                             painter.drawText(3200,i,query.value(1).toString());
                             painter.drawText(5300,i,query.value(4).toString());
                             painter.drawText(6700,i,query.value(5).toString());
                             painter.drawText(7000,i,query.value(6).toString());
                             painter.drawText(7500,i,query.value(7).toString());


                            i = i + 500;
                         }}

int Joueurss::calculscore(QString val)
{
      QSqlQuery query;
      query.prepare("SELECT score FROM joueurs where equipe=:equipe");
      query.bindValue(":equipe", val);

    qDebug() << query.lastQuery();

      int somme=0;
      if(query.exec())
    {
        while(query.next())
        {
            int score = query.value(0).toString().toInt();//Récupère le résultat de la requête
             somme=somme+score;

        }
    }
      return somme;

    }


