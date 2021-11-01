#ifndef SPECTACLEE_H
#define SPECTACLEE_H
#include<QString>

#include<QSqlQueryModel>
class Spectaclee
{
public:
    Spectaclee();
    Spectaclee(int,int,QString,QString);
       int getNum();
       int getduree();
       QString gethoraire();
       QString gettype();
       void setNum(int);
       void setduree(int);
       void sethoraire(QString);
       void settype(QString);
       bool ajouter();
       QSqlQueryModel* afficher();
         bool supprimer(int);
private :
    int Num , duree ;
    QString horaire,type ;




};

#endif // SPECTACLEE_H
