#ifndef COMPETITIONS_H
#define COMPETITIONS_H
# include <QString>
#include <QSqlQueryModel> //adapter pour enregistrer  le resultat d'une enquete select dans un tableau
#include <QTableView>
#include<QSystemTrayIcon>
class Competitions
{
public:

    Competitions();
    Competitions(int,QString,QString,QString,QString,int,int);

    int getnumero();
    QString getequipe1();
    QString getequipe2();
    QString getref();
    int getscore();
    QString getmail();
    int gettemps();
    void setnumero(int);
    void setequipe1(QString);
    void setequipe2(QString);
    void setref(QString);
    void setscore(int);
    void setmail(QString);
    void settemps(int);
       bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer(int);
       QSqlQueryModel * trierTemps();
       QSqlQueryModel * trier_score();
       QSqlQueryModel * trier_equipe();
       QSqlQueryModel * rechercheavancee(const QString &id);

       void recherche(QTableView * table,int);
private:
    int numero,temps,score;
    QString equipe1, equipe2,ref,mail;
    QSystemTrayIcon *mSystemTrayIcon;


};

#endif // COMPETITIONS_H
