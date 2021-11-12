#ifndef COMPETITION_H
#define COMPETITION_H
#include <Competitions.h>
#include <QDialog>

namespace Ui {
class competition;
}

class competition : public QDialog
{
    Q_OBJECT

public:
    explicit competition(QWidget *parent = nullptr);
    ~competition();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();


    void on_comboBox_activated(const QString &arg1);

private:
    Ui::competition *ui;
    Competitions c;
};

#endif // COMPETITION_H
