#include "employer.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
employer::employer()
{
id=0;
nom="";
prenom="";
emplacement="";
}
employer::employer(int id,QString nom,QString prenom,QString emplacement)
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->emplacement=emplacement;


}
QString employer::getprenom(){

    return this->prenom;
}
QString employer::getemplacement(){

    return this->emplacement;
}
QString employer::getnom(){

    return this->nom;
}

int employer::getid(){

    return this->id;
}

bool employer::ajouter(){
    QSqlQuery query;
                query.prepare("insert into employer values(?,?,?,?)");

                query.addBindValue(this->id);
                    query.addBindValue(this->nom);
                    query.addBindValue(this->prenom);
                     query.addBindValue(this->emplacement);

                     return query.exec();
}


QSqlQueryModel * employer::afficher(){
    QSqlQueryModel *model = new QSqlQueryModel();

                    model->setQuery("SELECT* FROM employer");
                    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
                            model->setHeaderData(3, Qt::Horizontal, QObject::tr("emplacement"));
                            return model;


}
bool employer::supprimer(int id){

    QSqlQuery query;

    QString res=QString::number(id);
            query.prepare("Delete from employer where id=:id");
            query.bindValue(":id", res);
   return query.exec();

}
bool employer::modifier(QString nom, QString prenom, QString emplacement,  int id)
{
    QSqlQuery query;

    QString idQString = QString::number(id);

    query.prepare("UPDATE EMPLOYER set id=:id, nom=:nom, prenom=:prenom, emplacement=:emplacement where id=:id_ancien");
    query.bindValue(":id", idQString);
    query.bindValue(":id_ancien", idQString);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":emplacement", emplacement);

    return query.exec();
}


void employer :: recherche(QTableView * table ,QString nom, QString prenom,QString emplacement )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EMPLOYER where NOM like '%"+nom+"%' or PRENOM like '%"+prenom+"%' or EMPLACEMENT like '%"+emplacement+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void  employer::telechargerPDF(){


                      QPdfWriter pdf("C:\\Users\\21699\\Desktop\\export_pdf\\export_pdf");


                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::green);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(1100,1200,"LISTES DES EMPLOYER");
                          painter.setPen(Qt::gray);
                          painter.setFont(QFont("Arial",14));
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"id");
                          painter.drawText(1300,3300,"nom");
                          painter.drawText(2200,3300,"prenom");
                          painter.drawText(3200,3300,"emplacement");


                          QSqlQuery query;
                          query.prepare("select * from employer");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(2).toString());
                              painter.drawText(2200,i,query.value(3).toString());
                              painter.drawText(3200,i,query.value(1).toString());
                              painter.drawText(5300,i,query.value(4).toString());
                              painter.drawText(6700,i,query.value(5).toString());


                             i = i + 500;
                          }}

QSqlQueryModel * employer::tri()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM employer ORDER BY Nom");
         return model;
 }

 QSqlQueryModel * employer::tri1()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM employer ORDER BY prenom");
         return model;
 }
 QSqlQueryModel * employer::tri2()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM employer ORDER BY ID");
         return model;
 }
