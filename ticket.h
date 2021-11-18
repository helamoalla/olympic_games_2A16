#ifndef TICKET_H
#define TICKET_H

#include <QDialog>

namespace Ui {
class ticket;
}

class ticket : public QDialog
{
    Q_OBJECT

public:
    explicit ticket(QWidget *parent = nullptr);
    ~ticket();

private:
    Ui::ticket *ui;
};

#endif // TICKET_H
