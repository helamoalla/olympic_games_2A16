#include "ticket.h"
#include "ui_ticket.h"

ticket::ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ticket)
{
    ui->setupUi(this);
}

ticket::~ticket()
{
    delete ui;
}
