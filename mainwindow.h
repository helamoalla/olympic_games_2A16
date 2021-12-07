#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
#include"employer.h"
#include <QMainWindow>
#include<QTableView>

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
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();


    void on_lineEdit_nom_cursorPositionChanged(int arg1, int arg2);

    void on_export_pdf_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    employer e ;
    QSystemTrayIcon *mSystemTrayIcon;
};
#endif // MAINWINDOW_H
