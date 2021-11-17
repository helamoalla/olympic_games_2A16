#include "stat.h"
#include "ui_stat.h"
#include <QString>
#include<qsqlquery.h>
#include "Competitions.h"
Stat::Stat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stat)
{
    ui->setupUi(this);
}
Stat::~Stat()
{
    delete ui;
}



void Stat::on_equipe2_textChanged(const QString &arg1)
{
     equipe2=ui->equipe2->text();

}

void Stat::on_equipe1_textChanged(const QString &arg1)
{
    equipe1=ui->equipe1->text();

}


void Stat::make()
{
        int e;
        int c;
        int total;

        QSqlQuery q;


        QString equipe1="CA";
           QString equipe2="EST";


        q.prepare("SELECT COUNT(score) FROM Competitions where equipe1='"+equipe1+"' ");
        q.exec();
        q.first() ;
        e=(q.value(0).toInt());

        q.prepare("SELECT COUNT(score) FROM Competitions where equipe2='"+equipe2+"' ");
        q.exec();
        q.first() ;
        c=(q.value(0).toInt());
        q.prepare("SELECT COUNT(score) FROM Competitions  ");
        q.exec();
        q.first() ;
        total=(q.value(0).toInt());

        e=((double)e/(double)total)*100;
        c=100-e;

        equipe1= QString::number(e);
        equipe2=QString::number(c);
        QPieSeries *series;
         series= new  QPieSeries();
         series->append("equipe1"+equipe1+"%",e);
         series->append("equipe2"+equipe2+"%",c);
         QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
             slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::darkRed, 2));
             slice1->setBrush(Qt::black);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistiques sur les equipes ");
              chart->legend()->show();
              QChartView *chartView = new QChartView(chart);
              chartView->setRenderHint(QPainter::Antialiasing);
              ui->verticalLayout->addWidget(chartView);

}











