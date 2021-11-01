#ifndef SPECTACLE_H
#define SPECTACLE_H

#include <QDialog>

namespace Ui {
class spectacle;
}

class spectacle : public QDialog
{
    Q_OBJECT

public:
    explicit spectacle(QWidget *parent = nullptr);
    ~spectacle();

private slots:
    void on_qb_ajouter_clicked();



private:
    Ui::spectacle *ui;
};

#endif // SPECTACLE_H
