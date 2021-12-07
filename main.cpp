#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        Connection c;
        bool test = c.createconnect();

        MainWindow w;




        w.show();

        if( test )
        {
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
