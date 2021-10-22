#include "joueurs.h"
#include "ui_joueurs.h"

joueurs::joueurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueurs)
{
    ui->setupUi(this);
}

joueurs::~joueurs()
{
    delete ui;
}
