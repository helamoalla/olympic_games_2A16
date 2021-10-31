#include "joueurs.h"
#include "ui_joueurs.h"
#include "joueurss.h"
#include <QMessageBox>
#include <QDebug>
joueurs::joueurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueurs)
{
    ui->setupUi(this);
    ui->tab_joueur->setModel(j.afficher());
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

}

void joueurs::on_pb_supprimer_clicked()
{
int id=ui->le_id_supp->text().toInt();
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
