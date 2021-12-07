#ifndef JOUEURSS_H
#define JOUEURSS_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>

class Joueurss
{
public:
    Joueurss();
    Joueurss(int,int,int,QString,QString,QString,QString,QString);
    int getid();
    int getannees_naiss();
    int getscore();
    QString getnom();
    QString getprenom();
    QString getnationalite();
    QString gettype_sport();
    QString getequipe();
    void setid(int);
    void setannees_naiss(int);
    void setscore(int);
    void setnom(QString);
    void setprenom(QString);
    void setnationalite(QString);
    void settype_sport(QString);
    void setequipe(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,int,int,QString,QString,QString,QString,QString);
    QSqlQueryModel * trierprenom();
    QSqlQueryModel * trierannees();
    QSqlQueryModel * trierscore();
    void recherche(QTableView * table, QString);
    void telechargerPDF();
    int calculscore(QString);
private:
    int id,annees_naissance,score;
    QString nom,prenom,nationalite,type_sport,equipe;
};



#endif // JOUEURSS_H
