#include "authentification.h"
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
//authentification::authentification()
//{

//}



//authentification::authentification(QString NOM_UTILI ,QString MOT_DE_PASSE)
//{
//    this->NOM_UTILI=NOM_UTILI;
//    this->MOT_DE_PASSE=MOT_DE_PASSE;



//}
// bool authentification::ajouter()
// {
//     QSqlQuery query;
//     query.prepare("INSERT INTO PROFIL (NOM_UTILI ,MOT_DE_PASSE) " "values(:NOM_UTILI, :MOT_DE_PASSE)");

//     query.bindValue(":NOM_UTILI",NOM_UTILI);
//     query.bindValue(":MOT_DE_PASSE",MOT_DE_PASSE);

//      return query.exec();
// }


// QSqlQueryModel *authentification:: afficher()
// {
//     QSqlQueryModel * model= new QSqlQueryModel();
//     model->setQuery("select NOM_UTILI,MOT_DE_PASSE from PROFIL");

//     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_UTILI"));
//     model->setHeaderData(1, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
//      return  model;

// }


//  bool authentification::supprimer(QString NOM_UTILI)
//  {
//      QSqlQuery query;

//      query.prepare("Delete from PROFIL where NOM_UTILI=:NOM_UTILI ");
//      query.bindValue(":NOM_UTILI", NOM_UTILI);
//      return    query.exec();
//  }


//  bool authentification:: modifier(QString NOM_UTILI , QString MOT_DE_PASSE)
//  {
//       QSqlQuery query;
//       query.prepare("Update PROFIL set MOT_DE_PASSE=:MOT_DE_PASSE where NOM_UTILI=:NOM_UTILI");

//       query.bindValue(":NOM_UTILI",NOM_UTILI);
//       query.bindValue(":MOT_DE_PASSE",MOT_DE_PASSE);
//           return       query.exec()  ;
//  }
//  void  authentification::HISTORIQUE_PDF(){
//  //QDateTime datecreation = date.currentDateTime();
//                //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
//                       QPdfWriter pdf("C:\\Users\\user2\\Desktop\\2A\\QT\\CRUD_EVENT\\pdfplan.pdf");
//                       QPainter painter(&pdf);
//                      int i = 4000;
//                           painter.setPen(Qt::blue);
//                           painter.setFont(QFont("Arial", 30));
//                           painter.drawText(1100,1200,"Liste Des plannings");
//                           painter.setPen(Qt::black);
//                           painter.setFont(QFont("Arial", 15));
//                          // painter.drawText(1100,2000,afficheDC);
//                           painter.drawRect(100,100,7300,2600);
//                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
//                           painter.drawRect(0,3000,9600,500);
//                           painter.setFont(QFont("Arial", 9));
//                           painter.drawText(200,3300,"ID");
//                           painter.drawText(1300,3300,"DESCRIPTION");
//                           painter.drawText(2500,3300,"LIEU");
//                           painter.drawText(2900,3300,"NOM");

//                           QSqlQuery query;
//                           query.prepare("select * from PLANNING");
//                           query.exec();
//                           while (query.next())
//                           {
//                               painter.drawText(200,i,query.value(0).toString());
//                               painter.drawText(1300,i,query.value(1).toString());
//                               painter.drawText(2200,i,query.value(2).toString());
//                               painter.drawText(3200,i,query.value(3).toString());

//                              i = i + 500;
//                           }


//        int reponse = QMessageBox::Yes;
//            if (reponse == QMessageBox::Yes)
//            {
//                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
//                notifyIcon->show();
//               // notifyIcon->setIcon(QIcon("icone.png"));

//                notifyIcon->showMessage("GESTION DES  PLANNING ","Liste plannig pret dans PDF",QSystemTrayIcon::Information,15000);

//                painter.end();
//            }
//            if (reponse == QMessageBox::No)
//            {
//                 painter.end();
//            }
//  }
//  QSqlQueryModel * authentification::mot_de_passe (const QString &aux1)

//  {
//      QSqlQueryModel * model = new QSqlQueryModel();

//      model->setQuery("select * from EMPLOYE where ((NOM_UTILI||MOT_DE_PASSE) LIKE '%"+aux1+"%')");
//      model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_UTILI"));
//      model->setHeaderData(1, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));

//      return model;
//  }
