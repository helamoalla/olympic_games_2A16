#ifndef STAT_H
#define STAT_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

namespace Ui {
class stat;
}

class Stat : public QWidget
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = nullptr);
    void make();
    ~Stat();
private slots:



    void on_equipe2_textChanged(const QString &arg1);

    void on_equipe1_textChanged(const QString &arg1);
private:
    Ui::stat *ui;
    QString equipe1;
       QString equipe2;
};

#endif // STAT_H
