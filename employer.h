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
    int id;
    QString nom,prenom,emplacement;
public:
    employer();
    employer(int,QString,QString,QString);
    int getid();

     QString getnom();
    QString getprenom();
    QString getemplacement();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(QString nom, QString prenom, QString emplacement,  int id);
    void recherche(QTableView * tabl, QString,QString,QString);
    void telechargerPDF();
    QSqlQueryModel * tri();
             QSqlQueryModel * tri1();
                 QSqlQueryModel * tri2();




};

#endif // EVALUATION_H
