#ifndef JOUEURSS_H
#define JOUEURSS_H
#include <QString>
#include <QSqlQueryModel>


class Joueurss
{
public:
    Joueurss();
    Joueurss(int,int,QString,QString,QString,QString);
    int getid();
    int getannees_naiss();
    QString getnom();
    QString getprenom();
    QString getnationalite();
    QString gettype_sport();
    void setid(int);
    void setannees_naiss(int);
    void setnom(QString);
    void setprenom(QString);
    void setnationalite(QString);
    void settype_sport(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
private:
    int id,annees_naissance;
    QString nom,prenom,nationalite,type_sport;
};



#endif // JOUEURSS_H
