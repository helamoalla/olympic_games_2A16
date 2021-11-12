#include "competition.h"
#include "ui_competition.h"
#include"competition.h"
#include"Competitions.h"
#include <QMessageBox>
#include "QSqlQuery"
competition::competition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition)
{
    ui->setupUi(this);
    ui->comboBox->setModel(c.afficher());
    ui->tabCompetition->setModel(c.afficher());
}

competition::~competition()
{
    delete ui;
}

void competition::on_pb_ajouter_clicked()
{   //int numero=ui->le_numero->text().toInt();
   // QString equipe1=ui->le_equipe1->text();
    //QString equipe2=ui->le_equipe2->text();

    int numero=ui->le_numero->text().toInt();

        QString equipe1=ui->le_equipe1->text();
        QString equipe2=ui->le_equipe2->text();

       Competitions c(numero,equipe1,equipe2);
       bool test=c.ajouter();
       QMessageBox msgBox;
       if(test)
           msgBox.setText("ajout avec succes");

       else
           msgBox.setText("echec");
       msgBox.exec();
       ui->tabCompetition->setModel(c.afficher());

}

void competition::on_pb_modifier_clicked()
{


    int numero = ui->le_numero->text().toInt();

           QString equipe1= ui->le_equipe1->text();
           QString equipe2= ui->le_equipe2->text();


         Competitions c(numero,equipe1,equipe2);


         bool test=c.modifier(numero,equipe1,equipe2);
         if(test)
       {ui->tabCompetition->setModel(c.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                         QObject::tr("invite modifiée.\n"
                                     "Click ok to exit."), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void competition::on_pb_supprimer_clicked()
{
    int numero =ui->le_numero->text().toInt();
        bool test=c.supprimer(numero);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tabCompetition->setModel(c.afficher());
}

void competition::on_pb_afficher_clicked()
{

}




void competition::on_comboBox_activated(const QString &arg1)
{
    int numero = ui->comboBox->currentText().toInt();
         QString id_string= QString::number(numero);
                QSqlQuery query;
                query.prepare("select * from Competitions where NUMERO='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->le_numero->setText(query.value(1).toString());
                   ui->le_equipe1->setText(query.value(0).toString());

                    ui->le_equipe2->setText(query.value(2).toString());

    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}
