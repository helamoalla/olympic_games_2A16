#include "competition.h"
#include "ui_mainwindow.h'
#include"competition.h"
#include"Competitions.h"
#include <QMessageBox> // fournit une boîte de dialogue modale pour informer l'utilisateur ou lui poser une question et recevoir une réponse
#include "QSqlQuery"
#include "stat.h"
competition::competition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition)
{
    ui->setupUi(this);
    ui->comboBox->setModel(tmpcopitition.afficher());
    ui->tabCompetition->setModel(tmpcopitition.afficher());
    mSystemTrayIcon = new QSystemTrayIcon(this);
     mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
     mSystemTrayIcon->setVisible(true);
}

competition::~competition()
{
    delete ui;
}

void competition::on_pb_ajouter_3_clicked()
{   //int numero=ui->le_numero->text().toInt();
   // QString equipe1=ui->le_equipe1->text();
    //QString equipe2=ui->le_equipe2->text();

    int numero=ui->le_numero->text().toInt(); //convertir le numero en int

        QString equipe1=ui->le_equipe1->text(); //convertir le QString en int
        QString equipe2=ui->le_equipe2->text();
        QString reference=ui->le_reference->text();
        int score=ui->le_score->text().toInt();
        QString mail=ui->le_mail->text();
        int temps=ui->le_temps->text().toInt(); //convertir le numero en int

       Competitions w(numero,equipe1,equipe2,reference,mail,temps,score);
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

void competition::on_pb_modifier_clicked()
{

    if (ui->pb_modifier->isChecked())
    {

        ui->pb_modifier->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("Competitions");
        tableModel->select();
        ui->tabCompetition->setModel(tableModel);
    }
    else
    {
        ui->pb_modifier->setText("Modifier");
        ui->tabCompetition->setModel(tmpcopitition.afficher());

    }




}

void competition::on_pb_supprimer_clicked()
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

void competition::on_pb_afficher_clicked()
{

    ui->tabCompetition->setModel(tmpcopitition.afficher());

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

void competition::on_trierTemps_clicked()
{
   ui->tabrecherche->setModel(tmpcopitition.trierTemps());
}

void competition::on_trier_score_clicked()
{
    ui->tabrecherche->setModel(tmpcopitition.trier_score());
}

void competition::on_trier_equipe_clicked()
{
    ui->tabrecherche->setModel(tmpcopitition.trier_equipe());
}

void competition::on_recherche_textEdited(const QString &arg1)
{

           int score = ui->recherche->text().toInt();

            tmpcopitition.recherche(ui->tabrecherche,score);
            if (ui->recherche->text().isEmpty())
            {
                ui->tabrecherche->setModel(tmpcopitition.afficher());
            }

}

void competition::on_rechav_textChanged(const QString &arg1)
{
    ui->tabCompetition->setModel(tmpcopitition.rechercheavancee(arg1));
}

void competition::on_pushButton_10_clicked()
{
    Stat *w = new Stat();
    w->make();
    w->show();
}

void competition::on_pushButton_8_clicked()
{




}

void competition::on_pushButton_4_clicked()
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
