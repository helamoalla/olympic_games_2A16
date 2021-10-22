#ifndef JOUEURS_H
#define JOUEURS_H

#include <QDialog>

namespace Ui {
class joueurs;
}

class joueurs : public QDialog
{
    Q_OBJECT

public:
    explicit joueurs(QWidget *parent = nullptr);
    ~joueurs();

private:
    Ui::joueurs *ui;
};

#endif // JOUEURS_H
