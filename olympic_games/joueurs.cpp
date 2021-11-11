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
}

joueurs::~joueurs()
{
    delete ui;
}


void joueurs::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int annees_naissance=ui->le_annees_naiss->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString nationalite=ui->le_nationalite->text();
    QString type_sport=ui->le_type_sport->text();


Joueurss j (id,annees_naissance,nom,prenom,nationalite,type_sport);
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
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString nationalite=ui->le_nationalite->text();
    QString type_sport=ui->le_type_sport->text();

        Joueurss j (id,annees_naissance,nom,prenom,nationalite,type_sport);
        bool test=j.modifier(id,annees_naissance,nom,prenom,nationalite,type_sport);
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

void joueurs::on_lineEdit_3_textChanged(const QString &arg1)   ///mtaa el recherche
{
   Joueurss j;
        QString nationalite = ui->lineEdit_3->text();
        int annees= ui->lineEdit_3->text().toInt();
        QString type_sport = ui->lineEdit_3->text();
        j.recherche(ui->tab_joueur,nationalite,annees,type_sport);
        if (ui->lineEdit_3->text().isEmpty())
        {
            ui->tab_joueur->setModel(j.afficher());
        }
}
