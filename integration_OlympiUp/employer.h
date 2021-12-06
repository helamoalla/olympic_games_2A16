#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>


class employer
{
public:
    int id_E;
    QString nomE,prenomE,emplacement;
public:
    employer();
    employer(int,QString,QString,QString);
    int getid_E();

     QString getnomE();
    QString getprenomE();
    QString getemplacement();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString nomE, QString prenomE, QString emplacement,  int idE);
    void recherche(QTableView * tabl, QString,QString,QString);
    void telechargerPDF();
    QSqlQueryModel * tri();
             QSqlQueryModel * tri1();
                 QSqlQueryModel * tri2();




};

#endif // EVALUATION_H
