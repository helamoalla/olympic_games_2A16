#include "joueurs.h"
#include "ui_joueurs.h"
#include "joueurss.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

joueurs::joueurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueurs)
{
    ui->setupUi(this);
    ui->tab_joueur->setModel(j.afficher());
    ui->comboBox_2->setModel(j.afficher());

    ui->label_pdf->hide();
}

joueurs::~joueurs()
{
    delete ui;
}


void joueurs::on_pb_ajouter_clicked()
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

void joueurs::on_pb_modifier_clicked()
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

void joueurs::on_pb_supprimer_clicked()
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

void joueurs::on_pb_afficher_clicked()
{
    ui->tab_joueur->setModel(j.afficher());

}

void joueurs::on_pb_importer_clicked()
{
QString filename= QFileDialog::getOpenFileName(this ,tr("choisir"),"",tr("photos(*.png)"));
if(QString::compare(filename, QString())!=0)
{
    QImage photo;
    bool valid=photo.load(filename);
    if(valid)
    {   photo=photo.scaledToWidth(ui->label_9->width(), Qt::SmoothTransformation);
        ui->label_9->setPixmap(QPixmap::fromImage(photo));
    }
    else
    {
    //error
    }
}

}


void joueurs::on_comboBox_2_activated(const QString &arg1)
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


void joueurs::on_trier_prenom_clicked()
{
ui->tab_joueur->setModel(j.trierprenom());
}

void joueurs::on_trier_annees_clicked()
{
ui->tab_joueur->setModel(j.trierannees());
}
void joueurs::on_trier_score_clicked()
{
ui->tab_joueur->setModel(j.trierscore());
}
void joueurs::on_lineEdit_3_textChanged(const QString &arg1)   ///mtaa el recherche
{
   Joueurss j;

    QString rech = ui->lineEdit_3->text();
        j.recherche(ui->tab_joueur,rech);
        if (ui->lineEdit_3->text().isEmpty())
        {
            ui->tab_joueur->setModel(j.afficher());
        }
}

void joueurs::on_export_pdf_clicked()
{
    QSqlQuery query;
    QString val = ui->label_pdf->text();
    query.prepare("select * from joueurs where id='"+val+"'");

    if(query.exec()){

        while(query.next())
        {

            j.telechargerPDF(val);
       ui->le_id->setText(query.value(0).toString());
       ui->le_annees_naiss->setText(query.value(1).toString());
        ui->le_nom->setText(query.value(2).toString());
        ui->le_prenom->setText(query.value(3).toString());
        ui->le_nationalite->setText(query.value(4).toString());
         ui->le_type_sport->setText(query.value(5).toString());


   }
    }
    else
        QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

     QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}

void joueurs::on_tab_joueur_activated(const QModelIndex &index)
{
    joueurs f;
  QString val=ui->tab_joueur->model()->data(index).toString();
  qDebug() << val;
  ui->label_pdf->setText(val);


}

void joueurs::on_calcul_score_clicked()
{
    QString val = ui->le_eq->text();
    QString score_string = QString::number(j.calculscore(val));
    ui->label_score->setText("score total: " + score_string);
}


