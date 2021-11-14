#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Competitions.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //déclare ses propres signaux et slots

public:
    MainWindow(QWidget *parent = nullptr); //fonction qui sert a fixer l'interface ghraphique loul
    ~MainWindow();


private slots:
    //void on_pb_ajouter_clicked();

   // void on_pb_supprimer_clicked();

private :
    Ui::MainWindow *ui; //pointeur sur l'interface graphique
};
#endif // MAINWINDOW_H
