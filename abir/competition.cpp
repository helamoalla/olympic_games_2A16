#include "competition.h"
#include "ui_competition.h"

competition::competition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition)
{
    ui->setupUi(this);
}

competition::~competition()
{
    delete ui;
}
