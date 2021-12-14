#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQueryModel>
#include<QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QString>
//#include <QtCharts/QChartView>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QLegend>
//#include <QtCharts/QBarCategoryAxis>
//#include <QtCharts/QHorizontalStackedBarSeries>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QCategoryAxis>
//#include <QtCharts/QPieSeries>
//#include <QtCharts/QPieSlice>

//using namespace QtCharts;
class ticket
{
public:
    ticket();
    ticket(int,int, QString, QString,QString);

        int getreference();
        int getnum();
        QString getdatee();
        QString getnomt();
        QString getprenomt();


        void setreference(int);
        void setnum(int);
        void setdatee(QString);
        void setnomt(QString);
        void setprenomt(QString);

        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(int,int,QString,QString,QString);
        void recherche(QTableView * table, QString);
        QSqlQueryModel * triernom();
           QSqlQueryModel * trierdate();
           QSqlQueryModel * trinum();
           void telechargerPDF();
         /* void printQr(const QrCode &qr);
          void generateQr();
          std::string toSvgString(const QrCode &qr, int border);*/
    private:
        int reference,num;
        QString datee,nomt,prenomt;
    };


#endif // TICKET_H
