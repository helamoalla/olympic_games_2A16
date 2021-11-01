#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spectaclee.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_spec->setModel(s.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_qb_ajouter_clicked()
{
    int Num=ui->le_Num->text().toInt();
        int duree=ui->le_duree->text().toInt();
        QString horaire=ui->le_horaire->text();
        QString type=ui->le_type->text();

       Spectaclee S(Num,duree,horaire,type);
       bool test=s.ajouter();
       QMessageBox msgBox;
       if(test)
           msgBox.setText("ajout avec succes");

       else
           msgBox.setText("echec");
       msgBox.exec();
       ui->tab_spec->setModel(S.afficher());

    }




void MainWindow::on_pb_supp_clicked()
{
    int num =ui->num_supp->text().toInt();
        bool test=s.supprimer(num);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tab_spec->setModel(s.afficher());


}
