#include "employer.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
employer::employer()
{
id_E=0;
nomE="";
prenomE="";
emplacement="";
}
employer::employer(int id_E,QString nomE,QString prenomE,QString emplacement)
{
this->id_E=id_E;
this->nomE=nomE;
this->prenomE=prenomE;
this->emplacement=emplacement;


}
QString employer::getprenomE(){

    return this->prenomE;
}
QString employer::getemplacement(){

    return this->emplacement;
}
QString employer::getnomE(){

    return this->nomE;
}

int employer::getid_E(){

    return this->id_E;
}

bool employer::ajouter(){
    QSqlQuery query;
                query.prepare("insert into employer values(?,?,?,?)");

                query.addBindValue(this->id_E);
                    query.addBindValue(this->nomE);
                    query.addBindValue(this->prenomE);
                     query.addBindValue(this->emplacement);

                     return query.exec();
}


QSqlQueryModel * employer::afficher(){
    QSqlQueryModel *model = new QSqlQueryModel();

                    model->setQuery("SELECT* FROM employer");
                    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_E"));
                            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomE"));
                            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomE"));
                            model->setHeaderData(3, Qt::Horizontal, QObject::tr("emplacement"));
                            return model;


}
bool employer::supprimer(int id_E){

    QSqlQuery query;

    QString res=QString::number(id_E);
            query.prepare("Delete from employer where id_E=:id_E");
            query.bindValue(":id_E", res);
   return query.exec();

}
bool employer::modifier(QString nomE, QString prenomE, QString emplacement,  int id_E)
{
    QSqlQuery query;

    QString idQString = QString::number(id_E);

    query.prepare("UPDATE EMPLOYER set id_E=:id_E, nomE=:nomE, prenomE=:prenomE, emplacement=:emplacement where id_E=:id_ancien");
    query.bindValue(":id_E", idQString);
    query.bindValue(":id_ancien", idQString);

    query.bindValue(":nomE", nomE);
    query.bindValue(":prenomE", prenomE);
    query.bindValue(":emplacement", emplacement);

    return query.exec();
}


void employer :: recherche(QTableView * table ,QString nom, QString prenom,QString emplacement )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EMPLOYER where NOME like '%"+nomE+"%' or PRENOME like '%"+prenomE+"%' or EMPLACEMENT like '%"+emplacement+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void  employer::telechargerPDF(){


                     // QPdfWriter pdf("C:\\Users\\21699\\Desktop\\export_pdf\\export_pdf");
                    QPdfWriter pdf("C:\\Users\\helam\\OneDrive\\Bureau\\export_pdf\\export_pdf.pdf");

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
                          painter.drawText(200,3300,"id_E");
                          painter.drawText(1300,3300,"nomE");
                          painter.drawText(2200,3300,"prenomE");
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
         model->setQuery("SELECT * FROM employer ORDER BY NOME");
         return model;
 }

 QSqlQueryModel * employer::tri1()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM employer ORDER BY PRENOME");
         return model;
 }
 QSqlQueryModel * employer::tri2()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM employer ORDER BY ID_E");
         return model;
 }
