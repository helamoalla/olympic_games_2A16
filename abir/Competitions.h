#ifndef COMPETITIONS_H
#define COMPETITIONS_H
# include <QString>
#include <QSqlQueryModel>

class Competitions
{
public:

    Competitions();
    Competitions(int,QString,QString);

    int getnumero();
    QString getequipe1();
    QString getequipe2();


    void setnumero(int);
    void setequipe1(QString);
    void setequipe2(QString);


       bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer(int);
       bool modifier(int,QString,QString);
private:
    int numero;
    QString equipe1, equipe2;


};

#endif // COMPETITIONS_H
