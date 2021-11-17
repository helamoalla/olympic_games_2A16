#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stat.h"
#include "Competitions.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pb_ajouter_clicked()
//{
   // int numero = ui->le_numero->text().toInt();
       /* QString equipe1 = ui->le_equipe1->text();
        QString equipe2 = ui->le_equipe2->text();

        Competitions C(numero, equipe1, equipe2);

        bool test = C.ajouter();

        if( test )
            {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                                         QObject::tr("Ajout effectué.\n"
                                                     "Click cancel to exit."),
                                         QMessageBox::Cancel);
                ui->tab_Competitions->setModel(C.afficher());
            }
            else
            {
                QMessageBox::information(nullptr, QObject::tr("Not OK"),
                                         QObject::tr("Ajout non effectué.\n"
                                                     "Click cancel to exit."),
                                         QMessageBox::Cancel);
            }

       */





