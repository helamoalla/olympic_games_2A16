#ifndef COMPETITION_H
#define COMPETITION_H
#include <Competitions.h>
#include <QDialog>
#include <QSqlTableModel>
#include <QSystemTrayIcon>
#include "smtp.h"
namespace Ui { //permet de regrouper nos venetres generé dans un espace de nom
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

    void on_trierTemps_clicked();


    void on_trier_score_clicked();

    void on_trier_equipe_clicked();


    //void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);



    void on_recherche_textEdited(const QString &arg1);

    void on_rechav_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::competition *ui;
    Competitions tmpcopitition;
        QSystemTrayIcon *mSystemTrayIcon;
};

#endif // COMPETITION_H
