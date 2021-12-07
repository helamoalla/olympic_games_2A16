#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"joueurss.h"
#include"ticket.h"
#include"historique.h"
#include"spectaclee.h"
#include "competitions.h"
#include "employer.h"
#include "arduinohhs.h"
#include <QDialog>
#include <QFileDialog>
#include <QSystemTrayIcon>
#include<QTableView>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_label();

    void on_connecter_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();

    void on_pb_importer_clicked();

    void on_ajout_imag_clicked();

    void on_calcul_score_clicked();

    void on_export_pdf_clicked();

    void on_pushButton_7_clicked();

    void on_trier_score_clicked();

    void on_trier_annees_clicked();

    void on_trier_prenom_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_tab_joueur_activated(const QModelIndex &index);

    void on_QR_code_clicked();

    void on_comboBox_modifier_ref_activated(const QString &arg1);

    void on_lineEdit_7_clicked();

    void on_pb_upload_clicked();

    void on_trier_datee_clicked();

    void on_trier_nom_clicked();

    void on_trier_num_clicked();

    void on_pushButton_stat_clicked();

    void on_comboBox_modifier_ref_currentIndexChanged(const QString &arg1);

    void on_trie_horaire_clicked();

    void on_trie_duree_clicked();

    void on_trie_type_clicked();

    void on_qb_ajouter_clicked();

    void on_exporter_clicked();

    void on_pb_supp_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_afficher_3_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_rechav_textChanged(const QString &arg1);

    void on_trierTemps_clicked();

    void on_trier_score_2_clicked();

    void on_trier_equipe_clicked();

    void on_pushButton_16_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_recherche_textEdited(const QString &arg1);

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_modifierE_clicked();

    void on_afficherE_clicked();

    void on_ajouterE_clicked();

    void on_supprimerE_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2);

    void on_ajouterT_clicked();

    void on_afficherT_clicked();

    void on_modifierT_clicked();

    void on_supprimerT_clicked();

    void on_exporter_pdfT_clicked();

    void on_export_pdfE_clicked();

    void on_deconnexion_clicked();

    void on_deconnexion_1_clicked();

    void on_deconnexion_3_clicked();

    void on_deconnexion_4_clicked();

    void on_deconnexion_5_clicked();

    void on_quitter_clicked();

private:
    Ui::MainWindow *ui;
     Joueurss j;
     ticket T;
     Spectaclee s;
     Historique h;
     Competitions tmpcopitition;
     employer e;
     QSystemTrayIcon *mSystemTrayIcon;
     QByteArray data; // variable contenant les données reçues
       arduinoHHS A;
};
#endif // MAINWINDOW_H
