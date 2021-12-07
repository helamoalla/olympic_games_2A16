#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString language = "FR";
    employer e;
    ui->tableView->setModel(e.afficher());

    mSystemTrayIcon = new QSystemTrayIcon(this);
         mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
         mSystemTrayIcon->setVisible(true);

         ui->comboBox->addItem("FR");
             ui->comboBox->addItem("ENG");

}
QString language = "FR";

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit->text().toInt();
      QString nom = ui->lineEdit_2->text();
      QString prenom = ui->lineEdit_3->text();
      QString emplacement = ui->lineEdit_4->text();

           employer e(id,nom,prenom,emplacement);
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


void MainWindow::on_pushButton_4_clicked()
{
    employer e;
       ui->tableView->setModel(e.afficher());

}

void MainWindow::on_pushButton_3_clicked()
{
    employer E1;
       int id = ui->lineEdit_5->text().toInt();
           bool test=E1.supprimer(id);
   QMessageBox msgBox ;
           if(test){
               msgBox.setText("supression effectué .\n"
                               "Click Ok to exit.");
               ui->tableView->setModel(e.afficher());


           }else
               msgBox.setText("Echec de suppression" );
                       msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
     int id = ui->lineEdit->text().toInt();
     QString nom = ui->lineEdit_2->text();
     QString prenom = ui->lineEdit_3->text();
     QString emplacement = ui->lineEdit_4->text();


    employer e;
    bool teste=e.modifier(nom , prenom , emplacement , id);
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







void MainWindow::on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2)
{
    {
                employer e;


        QString nom = ui->lineEdit_nom->text();
         QString prenom = ui->lineEdit_nom->text();
          QString emplacement  = ui->lineEdit_nom->text();
        e.recherche(ui->tableView,nom,prenom,emplacement);
        if (ui->lineEdit_nom->text().isEmpty())
        {
           ui->tableView->setModel(e.afficher());
        }
        }
}

void MainWindow::on_export_pdf_clicked()
{


        {
            e.telechargerPDF();

             QMessageBox::information(nullptr,QObject::tr("OK"),
                        QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

        }
    }



void MainWindow::on_comboBox_activated(const QString &arg1)
{
    language = ui->comboBox->currentText();

      if(language == "FR"){
          ui->label_2->setText("Nom");
          ui->label_3->setText("Prenom");
          ui->label_4->setText("Emplacement");
          ui->pushButton_7->setText("supprimer");
          ui->pushButton_3->setText("supprimer");
          ui->pushButton_4->setText("Afficher");
          ui->pushButton_2->setText("Modifier");
          ui->pushButton->setText("Ajouter");
          ui->pushButton_5->setText("trier par nom");
          ui->pushButton_6->setText("trier par prenom");
          ui->pushButton_9->setText("trier par id");





      }
      else {
          ui->label_2->setText("Name");
          ui->label_3->setText("First-Name");
          ui->label_4->setText("Site");
          ui->pushButton_7->setText("Delete");
          ui->pushButton_3->setText("Delete");
          ui->pushButton_4->setText("Display");
          ui->pushButton_2->setText("Edit");
          ui->pushButton->setText("Add");
          ui->pushButton_5->setText("Sort by name");
          ui->pushButton_6->setText("Sort by first name");
          ui->pushButton_9->setText("Sort by id");





      }


}


void MainWindow::on_pushButton_5_clicked()
{
    employer e;
            ui->tableView->setModel(e.tri());
}

void MainWindow::on_pushButton_6_clicked()
{
    employer e;
            ui->tableView->setModel(e.tri1());
}

void MainWindow::on_pushButton_9_clicked()
{
    employer e;
            ui->tableView->setModel(e.tri2());
}
