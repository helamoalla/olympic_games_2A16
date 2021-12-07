#ifndef SPECTACLEE_H
#define SPECTACLEE_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
#include <QPdfWriter>
#include <QPainter>

class Spectaclee
{
public:
    Spectaclee();
    Spectaclee(int,int,QString,QString);
       int getidE();
       int getduree();

       QString gethoraire();
       QString gettype();
       void setid(int);
       void setduree(int);
       void sethoraire(QString);
       void settype(QString);
       bool ajouter();
       QSqlQueryModel* afficher();
         bool supprimer(int);
         bool modifier(int,int,QString,QString);
         QSqlQueryModel * triehoraire();
         QSqlQueryModel * trieduree();
         QSqlQueryModel * trietype();
         void recherche(QTableView * tabl, QString,int,QString);
         void telechargerEXCEL();
private :
    int   duree,idE ;
    QString horaire,type ;





};

#endif // SPECTACLEE_H
