#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_stat.h"
#include "ui_arduino.h"
#include "joueurss.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include "ticket.h"
#include "QStringListModel"
#include <QIntValidator>
#include<QTableView>
#include "spectaclee.h"
#include "employer.h"
#include "QPixmap"
#include<QLabel>
#include "historique.h"
#include<QSystemTrayIcon>
#include "competitions.h"
#include "QSqlTableModel"
#include <QSqlQueryModel>
#include "QStackedWidget"
#include "stat.h"
#include "smtp.h"
#include "arduino.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret= a.connect_arduino();
        switch (ret)
        {
         case(0):qDebug() << "arduino is available and connected to: "<<a.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to: "<<a.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available  ";
        }
        QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    ui->tab_joueur->setModel(j.afficher());
    ui->comboBox_2->setModel(j.afficher());
    ui->label_pdf->hide();
    ui->le_ref->setValidator(new QIntValidator(0,99999999,this));
       ui->le_num->setValidator(new QIntValidator(0,999999999,this));
       ui->tab_ticket->setModel(T.afficher());
       ui->tab_spec->setModel(s.afficher());
       ui->comboBox->setModel(s.afficher());
       ui->comboBox->setModel(tmpcopitition.afficher());
           ui->tabCompetition->setModel(tmpcopitition.afficher());
           mSystemTrayIcon = new QSystemTrayIcon(this);
            mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
            mSystemTrayIcon->setVisible(true);
            QString language = "FR";
                employer e;
                ui->tableView->setModel(e.afficher());

                mSystemTrayIcon = new QSystemTrayIcon(this);
                     mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
                     mSystemTrayIcon->setVisible(true);

                     ui->comboBox->addItem("FR");
                         ui->comboBox->addItem("ENG");
                         ui->stackedWidget->setCurrentIndex(0);


}
QString language = "FR";
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connecter_clicked()
{ QStackedWidget stackedWidget;
    connect(ui->stackedWidget, SIGNAL(clicked()), this, SLOT(viewData));
    QString username=ui->lineEdit_username->text();
            QString password = ui->lineEdit_password->text();
            if(username == "hela" && password == "hela")
            { QMessageBox::information(this, "Login", "Username and password is correct");
           //connect(ui->MainWindow->page_3, SIGNAL(on_connecter_clicked()), this, SLOT(viewData));
            ui->stackedWidget->setCurrentIndex(1);
            }
                //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                else if(username == "haj" && password == "haj")
            { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->stackedWidget->setCurrentIndex(2);
            }
                    //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                    else if(username == "aziz" && password == "aziz")
                    { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->stackedWidget->setCurrentIndex(3);
            }
                        //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                        else if(username == "abir" && password == "abir")
                        { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->stackedWidget->setCurrentIndex(4);
            }
                            //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                            else if(username == "slim" && password == "slim")
                            { QMessageBox::information(this, "Login", "Username and password is correct");
               ui->stackedWidget->setCurrentIndex(5);
            }
                                //hide(); mainwindow = new MainWindow(this); mainwindow->show(); }
                                        else { QMessageBox::warning(this,"Login", "Username and password is not correct"); }
}
/////hela///////////
void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int annees_naissance=ui->le_annees_naiss->text().toInt();
    int score=ui->le_score->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString nationalite=ui->le_nationalite->text();
    QString type_sport=ui->le_type_sport->text();
    QString equipe=ui->le_equipe->text();

Joueurss j (id,annees_naissance,score,nom,prenom,nationalite,type_sport,equipe);
bool test=j.ajouter();
if(test)
  {  QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    int annees_naissance=ui->le_annees_naiss->text().toInt();
    int score=ui->le_score->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString nationalite=ui->le_nationalite->text();
    QString type_sport=ui->le_type_sport->text();
    QString equipe=ui->le_equipe->text();

        Joueurss j (id,annees_naissance,score,nom,prenom,nationalite,type_sport,equipe);
        bool test=j.modifier(id,annees_naissance,score,nom,prenom,nationalite,type_sport,equipe);
            if(test)
          {ui->tab_joueur->setModel(j.afficher());
          QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                            QObject::tr("invite modifiée.\n"
                                        "Click ok to exit."), QMessageBox::Ok);

          }
            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->le_id->text().toInt();
    bool test=j.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("suppression effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
          { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                       QObject::tr("suppression non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void MainWindow::on_pb_afficher_clicked()
{
ui->tab_joueur->setModel(j.afficher());
}

void MainWindow::on_pb_importer_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this ,tr("choisir"),"",tr("photos(*.png)"));
    if(QString::compare(filename, QString())!=0)
{
    QImage photo;
    bool valid=photo.load(filename);
    if(valid)
    {
        photo=photo.scaledToWidth(ui->label_9->width(), Qt::SmoothTransformation);
        ui->label_9->setPixmap(QPixmap::fromImage(photo));


    }
    else
    {
    //error
    }
}
}

void MainWindow::on_ajout_imag_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this ,tr("choisir"),"",tr("photos(*.png)"));
    qDebug() << filename;

    if(QString::compare(filename, QString())!=0)
{
    QImage photo;

    bool valid=photo.load(filename);
    if(valid)
    {
        photo=photo.scaledToWidth(ui->label_15->width(), Qt::SmoothTransformation);
        ui->label_15->setPixmap(QPixmap::fromImage(photo));

        QString id = ui->comboBox_2->currentText();

        QSqlQueryModel* model = new QSqlQueryModel();
        QString query_string = "update JOUEURS set image='file_path' where id=:id";
        query_string.replace("file_path", filename);
        query_string.replace(":id", id);

        model->setQuery(query_string);
        model->query().exec();
    }
    else
    {
    //error
    }
}
}

void MainWindow::on_calcul_score_clicked()
{
    QString val = ui->le_eq->text();
    QString score_string = QString::number(j.calculscore(val));
    ui->label_score->setText("score total: " + score_string);
}

void MainWindow::on_export_pdf_clicked()
{
    QSqlQuery query;
    QString val = ui->label_pdf->text();
    //query.prepare("select * from joueurs where id='"+val+"'");
query.prepare("select * from joueurs where id");
 j.telechargerPDF();
//    if(query.exec()){

//        while(query.next())
//        {

//            j.telechargerPDF(val);
//       ui->le_id->setText(query.value(0).toString());
//       ui->le_annees_naiss->setText(query.value(1).toString());
//        ui->le_nom->setText(query.value(2).toString());
//        ui->le_prenom->setText(query.value(3).toString());
//        ui->le_nationalite->setText(query.value(4).toString());
//         ui->le_type_sport->setText(query.value(5).toString());


//   }
//    }
//    else
//        QMessageBox::critical(nullptr, QObject::tr(" echoué"),
//                    QObject::tr("Erreur !.\n"
//                                "Click Cancel to exit."), QMessageBox::Cancel);

     QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer export_pdf.pdf");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;
}

void MainWindow::on_trier_score_clicked()
{
ui->tab_joueur->setModel(j.trierscore());
}

void MainWindow::on_trier_annees_clicked()
{
ui->tab_joueur->setModel(j.trierannees());
}

void MainWindow::on_trier_prenom_clicked()
{
ui->tab_joueur->setModel(j.trierprenom());
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    Joueurss j;

     QString rech = ui->lineEdit_5->text();
         j.recherche(ui->tab_joueur,rech);
         if (ui->lineEdit_5->text().isEmpty())
         {
             ui->tab_joueur->setModel(j.afficher());
         }
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    int id = ui->comboBox_2->currentText().toInt();
         QString id_string= QString::number(id);
                QSqlQuery query;
                query.prepare("select * from joueurs where id='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->le_id->setText(query.value(0).toString());
                   ui->le_annees_naiss->setText(query.value(1).toString());
                    ui->le_nom->setText(query.value(2).toString());
                    ui->le_prenom->setText(query.value(3).toString());
                    ui->le_nationalite->setText(query.value(4).toString());
                     ui->le_type_sport->setText(query.value(5).toString());
                     ui->le_equipe->setText(query.value(6).toString());
                      ui->le_score->setText(query.value(7).toString());
               }
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tab_joueur_activated(const QModelIndex &index)
{
    Joueurss f;
  QString val=ui->tab_joueur->model()->data(index).toString();
  qDebug() << val;
  ui->label_pdf->setText(val);
}
/////////aziz//////////
void MainWindow::on_QR_code_clicked()
{
    QString qr=ui->le_QR_2->text();
       if(qr=="1")
             {
                 QPixmap pix("C:\\Users\\HP\\Desktop\\projetccp\\1.png");
                 int w = ui->label_pic_3->width();
                 int h = ui->label_pic_3->height();
                  ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

             }
      else if(qr=="2")
             {
                 QPixmap pix("C:\\Users\\HP\\Desktop\\projetccp\\2.png");
                 int w = ui->label_pic_3->width();
                 int h = ui->label_pic_3->height();
                  ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


             }
      else if(qr=="3")
             {
                 QPixmap pix("C:\\Users\\HP\\Desktop\\projetccp\\3.png");
                 int w = ui->label_pic_3->width();
                 int h = ui->label_pic_3->height();
                  ui->label_pic_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


             }
       else
       {
           QMessageBox msgBox;

                  msgBox.setText("taper 1 ou 2 ou 3");
              msgBox.exec();

    }

}

void MainWindow::on_comboBox_modifier_ref_activated(const QString &arg1)
{
//    int reference = ui->comboBox_modifier_ref->currentText().toInt();
//            QString reference_string= QString::number(reference);
//                   QSqlQuery query;
//                   query.prepare("select * from ticket where reference='"+reference_string+"'");

//                   if(query.exec()){

//                       while(query.next())
//                       {

//                      ui->le_ref->setText(query.value(0).toString());
//                      ui->le_num->setText(query.value(1).toString());
//                       ui->le_date->setText(query.value(2).toString());
//                       ui->le_nom_2->setText(query.value(3).toString());
//                       ui->le_prenom_2->setText(query.value(4).toString());

//                  }
//                   }
//                   else
//                       QMessageBox::critical(nullptr, QObject::tr(" echoué"),
//                                   QObject::tr("Erreur !.\n"
//                                               "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_lineEdit_7_clicked()
{
    ticket T;

          QString rech = ui->recher_edit->text();
              T.recherche(ui->tab_ticket,rech);
              if (ui->recher_edit->text().isEmpty())
              {
                  ui->tab_ticket->setModel(T.afficher());
              }
}

void MainWindow::on_pb_upload_clicked()
{
    QSqlQueryModel* modal= new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("select reference from TICKET");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_modifier_ref->setModel(modal);
}

void MainWindow::on_trier_datee_clicked()
{
ui->tab_ticket->setModel(T.trierdate());
}

void MainWindow::on_trier_nom_clicked()
{
ui->tab_ticket->setModel(T.triernom());
}

void MainWindow::on_trier_num_clicked()
{
ui->tab_ticket->setModel(T.trinum());
}

void MainWindow::on_pushButton_stat_clicked()
{
//    QChart* chart_bar = T.chart_pie();
//       QChartView* chart_view_bar = new QChartView(chart_bar, ui->label_stat);
//       chart_view_bar->setRenderHint(QPainter::Antialiasing);
//       chart_view_bar->setMinimumSize(400,400);
//       chart_view_bar->show();
}

void MainWindow::on_comboBox_modifier_ref_currentIndexChanged(const QString &arg1)
{
    int reference = ui->comboBox_modifier_ref->currentText().toInt();
            QString reference_string= QString::number(reference);
                   QSqlQuery query;
                   query.prepare("select * from ticket where reference='"+reference_string+"'");

                   if(query.exec()){

                       while(query.next())
                       {

                      ui->le_ref->setText(query.value(0).toString());
                      ui->le_num->setText(query.value(1).toString());
                       ui->le_date->setText(query.value(2).toString());
                       ui->le_nomT->setText(query.value(3).toString());
                       ui->le_prenomT->setText(query.value(4).toString());

                  }
                   }
                   else
                       QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
//////////haj/////////
void MainWindow::on_trie_horaire_clicked()
{
 ui->tab_spec->setModel(s.triehoraire());
}

void MainWindow::on_trie_duree_clicked()
{
ui->tab_spec->setModel(s.trieduree());
}

void MainWindow::on_trie_type_clicked()
{
ui->tab_spec->setModel(s.trietype());
}

void MainWindow::on_qb_ajouter_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
               notifyIcon->show();
               notifyIcon->setIcon(QIcon("icone.png"));

               notifyIcon->showMessage("spectacle ajouter ","spectacle ajouter",QSystemTrayIcon::Information,15000);

       int idE=ui->le_Num->text().toInt();
           int duree=ui->le_duree->text().toInt();
           QString horaire=ui->le_horaire->text();
           QString type=ui->le_type->text();
           Spectaclee S(idE,duree,horaire,type);
           bool test=S.ajouter();
            ui->tab_spec->setModel(S.afficher());


           QMessageBox msgBox;
        if(test){
            h.saveajouter();
            ui->comboBox->setModel(s.afficher());
             QMessageBox ::information(nullptr,QObject::tr("ok"),
                                       QObject::tr("ajouter"
                                                   "click cancel to exit."), QMessageBox ::Cancel);
             ui->tab_spec->setModel(S.afficher());
       }

        else{
            QMessageBox ::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("ajouter le "
                                                  "click cancel to exit."), QMessageBox ::Cancel);

       }
}

void MainWindow::on_exporter_clicked()
{
    s.telechargerEXCEL();


            QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supp_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                       notifyIcon->show();
                       notifyIcon->setIcon(QIcon("icone.png"));

                       notifyIcon->showMessage("spectacle supprimer ","spectacle supprimer",QSystemTrayIcon::Information,15000);

               Spectaclee S;
               S.setid(ui->comboBox->currentText().toInt());


           bool test=S.supprimer(S.getidE());

           if(test){
               h.savesupp();
               ui->comboBox->setModel(s.afficher());
               QMessageBox::information(nullptr, QObject::tr("ok"),
                           QObject::tr("supression effectué .\n"
                                       "Click Ok to exit."), QMessageBox::Ok);
           ui->tab_spec->setModel(S.afficher());}
           else{
               QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("échec suprresion.\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );}
}

void MainWindow::on_pushButton_9_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
               notifyIcon->show();
               notifyIcon->setIcon(QIcon("icone.png"));

               notifyIcon->showMessage("spectacle modifiee ","spectacle modifiee",QSystemTrayIcon::Information,15000);


       {


               int idE=ui->le_Num->text().toInt();
               int duree=ui->le_duree->text().toInt();
               QString horaire=ui->le_horaire->text();
               QString type=ui->le_type->text();


                Spectaclee S(idE,duree,horaire,type);


                bool test=s.modifier(idE,duree,horaire,type);
                if(test)
              {ui->tab_spec->setModel(s.afficher());
                    h.savemodifier();
                    ui->comboBox->setModel(s.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                                QObject::tr("invite modifiée.\n"
                                            "Click ok to exit."), QMessageBox::Ok);

              }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                                QObject::tr("echec d'ajout !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       }


}

void MainWindow::on_pushButton_10_clicked()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
               notifyIcon->show();
               notifyIcon->setIcon(QIcon("icone.png"));

               notifyIcon->showMessage("membres affiche ","mombres affiche",QSystemTrayIcon::Information,15000);
       QString qr=ui->le_aff->text();

      if (qr=="dance")
      {
       QPixmap pix("C:/Users/21694/Desktop/1.png");
                     int w = ui->label_pic_2->width();
                     int h = ui->label_pic_2->height();
                      ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));}
      else if (qr=="music")
      {
       QPixmap pix("C:/Users/21694/Desktop/2.png");
                     int w = ui->label_pic_2->width();
                     int h = ui->label_pic_2->height();
                      ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));}
      else
          {
              QMessageBox msgBox;

                     msgBox.setText("taper dance ou music");
                 msgBox.exec();

       }
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    Spectaclee s;


           QString nom = ui->lineEdit_6->text();
           QString nom1 = ui->lineEdit_6->text();
           int idE = ui->lineEdit_6->text().toInt();

           s.recherche(ui->tab_spec,nom,idE,nom1);
           if (ui->lineEdit_6->text().isEmpty())
           {
               ui->tab_spec->setModel(s.afficher());
           }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int idE = ui->comboBox->currentText().toInt();
             QString id_string= QString::number(idE);
                    QSqlQuery query;
                    query.prepare("select * from SPECTACLE where NUM='"+id_string+"'");

                    if(query.exec()){

                            while(query.next())
                            {

                       ui->le_Num->setText(query.value(0).toString());
                       ui->le_horaire->setText(query.value(1).toString());
                       ui->le_duree->setText(query.value(2).toString());
                       ui->le_type->setText(query.value(3).toString());

        }}
                    else
                        QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}
///////////abir///////////
void MainWindow::on_pb_ajouter_3_clicked()
{
    int numero=ui->le_numero->text().toInt(); //convertir le numero en int

            QString equipe1=ui->le_equipe1->text(); //convertir le QString en int
            QString equipe2=ui->le_equipe2->text();
            QString ref=ui->le_reference->text();
            int score=ui->le_score->text().toInt();
            QString mail=ui->le_mail->text();
            int temps=ui->le_temps->text().toInt(); //convertir le numero en int

           Competitions w(numero,equipe1,equipe2,ref,mail,temps,score);
           bool test=w.ajouter();
           QMessageBox msgBox;
           if(test)
           {

           mSystemTrayIcon->showMessage(tr("ajout avec succes"),
                         tr("ajout effectué"));
           }

           else
           {

           mSystemTrayIcon->showMessage(tr("echec"),
                         tr("ajout echec"));
    }
           ui->tabCompetition->setModel(w.afficher());

}

void MainWindow::on_pb_modifier_3_clicked()
{
    if (ui->pb_modifier_3->isChecked())
      {

          ui->pb_modifier_3->setText("Modifiable");
          QSqlTableModel *tableModel= new QSqlTableModel();
          tableModel->setTable("Competitions");
          tableModel->select();
          ui->tabCompetition->setModel(tableModel);
      }
      else
      {
          ui->pb_modifier_3->setText("Modifier");
          ui->tabCompetition->setModel(tmpcopitition.afficher());

      }

}

void MainWindow::on_pb_supprimer_3_clicked()
{
    int numero =ui->le_numero->text().toInt();
          bool test=tmpcopitition.supprimer(numero);

          if(test)
              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("supression effectué .\n"
                                      "Click Ok to exit."), QMessageBox::Ok);
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("échec suprresion.\n"
                                      "Click cancel to exit."), QMessageBox::Cancel);
          ui->tabCompetition->setModel(tmpcopitition.afficher());
}

void MainWindow::on_pb_afficher_3_clicked()
{
    ui->tabCompetition->setModel(tmpcopitition.afficher());

}

void MainWindow::on_pushButton_12_clicked()//timer
{

}

void MainWindow::on_pushButton_14_clicked()
{
    Stat *w = new Stat();
       w->make();
       w->show();
}

void MainWindow::on_rechav_textChanged(const QString &arg1)
{
 ui->tabCompetition->setModel(tmpcopitition.rechercheavancee(arg1));
}



void MainWindow::on_trierTemps_clicked()
{
ui->tabrecherche->setModel(tmpcopitition.trierTemps());
}

void MainWindow::on_trier_score_2_clicked()
{
 ui->tabrecherche->setModel(tmpcopitition.trier_score());
}

void MainWindow::on_trier_equipe_clicked()
{
 ui->tabrecherche->setModel(tmpcopitition.trier_equipe());
}

void MainWindow::on_pushButton_16_clicked() //envoi mail
{
    qDebug() <<  "Loaded SSL Library version: " << QSslSocket::sslLibraryVersionString();


       QString from = "abir.khlifi@esprit.tn";
       QString to = ui->lineEdit_to_email->text();
       QString subject = ui->lineEdit_subject_email->text();
       QString password ="201JFT3490";
       QString email_text = ui->textEdit_email->toPlainText();

     Smtp* smtp = new Smtp(from, password);
      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


          smtp->sendMail(from, to, subject, email_text);
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    int numero = ui->comboBox->currentText().toInt();
            QString id_string= QString::number(numero);
                   QSqlQuery query;
                   query.prepare("select * from Competitions where NUMERO='"+id_string+"'");

                   if(query.exec()){

                       while(query.next())
                       {
                           ui->le_numero->setText(query.value(0).toString());
                           ui->le_equipe1->setText(query.value(1).toString());
                           ui->le_equipe2->setText(query.value(2).toString());
                           ui->le_reference->setText(query.value(3).toString());
                           ui->le_mail->setText(query.value(4).toString());
                           ui->le_temps->setText(query.value(5).toString());
                           ui->le_score->setText(query.value(6).toString());

       }}
                   else
                       QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_textEdited(const QString &arg1)
{
    int score = ui->recherche->text().toInt();

               tmpcopitition.recherche(ui->tabrecherche,score);
               if (ui->recherche->text().isEmpty())
               {
                   ui->tabrecherche->setModel(tmpcopitition.afficher());
               }
}

void MainWindow::update_label()
{
    data=a.read_from_arduino();
    if(data=="0")
        ui->label_3->setText(" Présence d'un objet ");

}



/////slim/////////////
void MainWindow::on_pushButton_22_clicked()
{
    employer e;
               ui->tableView->setModel(e.tri());
}

void MainWindow::on_pushButton_23_clicked()
{
    employer e;
              ui->tableView->setModel(e.tri1());
}

void MainWindow::on_pushButton_24_clicked()
{
    employer e;
                ui->tableView->setModel(e.tri2());
}

void MainWindow::on_modifierE_clicked()
{
    int id_E= ui->le_idE->text().toInt();
        QString nomE = ui->le_nomE->text();
        QString prenomE = ui->le_prenomE->text();
        QString emplacement = ui->le_emplacementE->text();


       employer e;
       bool teste=e.modifier(nomE , prenomE , emplacement , id_E);
             if(teste)
               {
                 // ui->tableView->setModel((e.afficher()));
                  QMessageBox::information(nullptr, QObject::tr("Modifier !"),
                                    QObject::tr("  modifié ! \n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
               }

               else {

                   QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               }
}

void MainWindow::on_afficherE_clicked()
{
    employer e;
          ui->tableView->setModel(e.afficher());
}

void MainWindow::on_ajouterE_clicked()
{
    int id_E= ui->le_idE->text().toInt();
         QString nomE = ui->le_nomE->text();
         QString prenomE = ui->le_prenomE->text();
         QString emplacement = ui->le_emplacementE->text();

              employer e(id_E,nomE,prenomE,emplacement);
             bool test=e.ajouter();
             QMessageBox msgBox;
             if(test){
                 mSystemTrayIcon->showMessage(tr("ajout avec succes"),
                                      tr("ajout effectué"));
                        }

                        else
                        {

                        mSystemTrayIcon->showMessage(tr("echec"),
                                      tr("ajout echec"));
             }
                 ui->tableView->setModel(e.afficher());


}

void MainWindow::on_supprimerE_clicked()
{
    employer E1;
           int id_E = ui->enterID->text().toInt();
               bool test=E1.supprimer(id_E);
       QMessageBox msgBox ;
               if(test){
                   msgBox.setText("supression effectué .\n"
                                   "Click Ok to exit.");
                   ui->tableView->setModel(e.afficher());


               }else
                   msgBox.setText("Echec de suppression" );
                           msgBox.exec();
}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    language = ui->comboBox->currentText();

          if(language == "FR"){
              ui->label_52->setText("Nom");
              ui->label_53->setText("Prenom");
              ui->label_54->setText("Emplacement");
              ui->pushButton_25->setText("supprimer");
              ui->supprimerE->setText("supprimer");
              ui->afficherE->setText("Afficher");
              ui->modifierE->setText("Modifier");
              ui->ajouterE->setText("Ajouter");
              ui->pushButton_22->setText("trier par nom");
              ui->pushButton_23->setText("trier par prenom");
              ui->pushButton_24->setText("trier par id");





          }
          else {
              ui->label_52->setText("Name");
              ui->label_53->setText("First-Name");
              ui->label_54->setText("Site");
              ui->pushButton_25->setText("Delete");
              ui->supprimerE->setText("Delete");
              ui->afficherE->setText("Display");
              ui->modifierE->setText("Edit");
              ui->ajouterE->setText("Add");
              ui->pushButton_22->setText("Sort by name");
              ui->pushButton_23->setText("Sort by first name");
              ui->pushButton_24->setText("Sort by id");





          }
}

void MainWindow::on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2)
{
    employer e;


           QString nomE = ui->le_nomE->text();
            QString prenomE = ui->le_prenomE->text();
             QString emplacement  = ui->le_emplacementE->text();
           e.recherche(ui->tableView,nomE,prenomE,emplacement);
           if (ui->le_nomE->text().isEmpty())
           {
              ui->tableView->setModel(e.afficher());
           }
}
void MainWindow::on_export_pdfE_clicked()
{
    e.telechargerPDF();

                 QMessageBox::information(nullptr,QObject::tr("OK"),
                            QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

/////aziz/////
void MainWindow::on_ajouterT_clicked()
{
    int reference = ui->le_ref->text().toInt();
        int num = ui->le_num->text().toInt();
        QString datee = ui->le_date->text();
        QString nomt = ui->le_nomT->text();
        QString prenomt = ui->le_prenomT->text();


        ticket T (reference,num,datee, nomt, prenomt);

        bool test = T.ajouter();

        if( test )
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué.\n"
                                                 "Click cancel to exit."),
                                     QMessageBox::Cancel);
            ui->tab_ticket->setModel(T.afficher());
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Ajout non effectué.\n"
                                                 "Click cancel to exit."),
                                     QMessageBox::Cancel);
        }

}

void MainWindow::on_afficherT_clicked()
{
 ui->tab_ticket->setModel(T.afficher());
}

void MainWindow::on_modifierT_clicked()
{
    int reference =ui->le_ref->text().toInt();
               int num=ui->le_num->text().toInt();
               QString datee=ui->le_date->text();
               QString nomt=ui->le_nomT->text();

               QString prenomt=ui->le_prenomT->text();



                ticket T(reference,num,datee, nomt, prenomt);
                bool test=T.modifier(reference,num,datee, nomt, prenomt);
                if(test)
              {ui->tab_ticket->setModel(T.afficher());
                    /*h.savemodifier();*/
                    ui->comboBox_modifier_ref->setModel(T.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                                QObject::tr("invite modifiée.\n"
                                            "Click ok to exit."), QMessageBox::Ok);

              }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                                QObject::tr("echec d'ajout !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimerT_clicked()
{
    int reference = ui->le_ref_supp->text().toInt();


        bool test = T.supprimer(reference);

        if( test )
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Suppression avec succes.\n"
                                                 "Click cancel to exit."),
                                     QMessageBox::Cancel);
            ui->tab_ticket->setModel(T.afficher());
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Echec de suppression.\n"
                                                 "Click cancel to exit."),
                                     QMessageBox::Cancel);
        }
}

void MainWindow::on_exporter_pdfT_clicked()
{
    T.telechargerPDF();

        QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void MainWindow::on_deconnexion_clicked()
{
    QStackedWidget stackedWidget;
            connect(ui->stackedWidget, SIGNAL(clicked()), this, SLOT(viewData));
             ui->stackedWidget->setCurrentIndex(0);
}
