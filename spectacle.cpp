#include "spectacle.h"
#include "ui_spectacle.h"
#include "spectaclee.h"
#include"QString"
spectacle::spectacle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spectacle)
{
    ui->setupUi(this);
}

spectacle::~spectacle()
{
    delete ui;
}

void spectacle::on_qb_ajouter_clicked()
{
      int Num=ui->le_Num->text().toInt();
      int duree=ui->le_duree->text().toInt();
      QString horaire=ui->le_horaire->text();
      QString type=ui->le_type->text();

      Spectaclee S (Num,duree,horaire,type);
}
