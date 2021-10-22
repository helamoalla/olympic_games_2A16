#ifndef COMPETITION_H
#define COMPETITION_H

#include <QDialog>

namespace Ui {
class competition;
}

class competition : public QDialog
{
    Q_OBJECT

public:
    explicit competition(QWidget *parent = nullptr);
    ~competition();

private:
    Ui::competition *ui;
};

#endif // COMPETITION_H
