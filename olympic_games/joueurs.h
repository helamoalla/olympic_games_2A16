#ifndef JOUEURS_H
#define JOUEURS_H
#include"joueurss.h"
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

private slots:
    //void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();

    void on_pb_importer_clicked();

private:
    Ui::joueurs *ui;
    Joueurss j;
};

#endif // JOUEURS_H
