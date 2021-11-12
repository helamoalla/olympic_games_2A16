#include "mainwindow.h"
#include<QMessageBox>
#include "connection.h"
#include <QApplication>
#include "competition.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.creatconnection();
    competition w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                         QObject::tr("Connection successful.\n"
                                                     "Click cancel to exit."),
                                         QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                         QObject::tr("Connection failed.\n"
                                                     "Click cancel to exit."),
                                         QMessageBox::Cancel);
}
    return a.exec();

}
