#include "ticket.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include"mainwindow.h"
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
//using namespace QtCharts;
ticket::ticket()
{
    reference = 0;
    num = 0;
    datee="";
    nomt="";
    prenomt="";

    }


    ticket::ticket(int reference,int num,QString datee, QString nomt, QString prenomt)
    {
        this->reference = reference;
        this->num = num;
        this->datee = datee;
        this->nomt = nomt;
        this->prenomt = prenomt;

    }

    int ticket::getreference(){return reference;}
    int ticket::getnum(){return num;}
    QString ticket::getdatee(){return datee;}
    QString ticket::getnomt(){return nomt;}
    QString ticket::getprenomt(){return prenomt;}

    void ticket::setreference(int reference){this->reference = reference;}
    void ticket::setnum(int num){this->num = num;}
    void ticket::setdatee(QString datee){this->datee = datee;}
    void ticket::setnomt(QString nomt){this->nomt = nomt;}
    void ticket::setprenomt(QString prenomt){this->prenomt = prenomt;}


    bool ticket::ajouter()
    {

        QSqlQuery query;
        QString reference_string = QString::number(reference);
        QString num_string = QString::number(num);
        query.prepare("INSERT INTO TICKET (REFERENCE, NUM, DATEE, NOMT, PRENOMT) "
                      "VALUES (:reference, :num, :datee, :nomt, :prenomt)");
        query.bindValue(0, reference_string);
        query.bindValue(1, num_string);
        query.bindValue(2,datee);
        query.bindValue(3, nomt);
        query.bindValue(4, prenomt);

        qDebug() << query.lastQuery();

        return query.exec();
    }

    QSqlQueryModel* ticket::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT* FROM ticket");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("referance"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nomt"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenomt"));


        return model;
    }


    bool ticket::supprimer(int reference)
    {
        QSqlQuery query;
        //QString res = QString::number(reference);


        query.prepare("DELETE FROM ticket where reference=:reference");
        query.bindValue(":reference", reference);

        return query.exec();
}
    bool ticket::modifier(int reference ,int num,QString datee,QString nomt ,QString prenomt )
    {
          QSqlQuery query;
          //QString reference_string=QString::number(reference);
         // QString num_string=QString::number(num);
              query.prepare("UPDATE TICKET set REFERENCE=(?) ,NUM=(?), DATEE=(?) ,NOMT=(?), PRENOMT=(?) where REFERENCE=(?) ");
              query.addBindValue(reference);
              query.addBindValue(num);
              query.addBindValue(datee);
              query.addBindValue(nomt);
              query.addBindValue(prenomt);
             return query.exec();
    }

    QSqlQueryModel * ticket::triernom()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM TICKET ORDER BY NOMT");



        return model;
    }
    QSqlQueryModel * ticket::trierdate()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM ticket ORDER BY datee");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("datee"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));

        return model;
    }

    QSqlQueryModel * ticket::trinum()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM ticket ORDER BY num");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("datee"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));

        return model;
    }

    void ticket::recherche(QTableView * table, QString rech)
   {
        QSqlQueryModel *model= new QSqlQueryModel();
            QString reference_string=QString::number(reference);
            QString NUM_string=QString::number(num);
            QSqlQuery *query=new QSqlQuery;
            query->prepare("select * from TICKET where DATEE like '%"+rech+"%' or NUM like '%"+rech+"%' or REFERENCE like '%"+rech+"%' ;");
            query->exec();
            model->setQuery(*query);
            table->setModel(model);
            table->show();
    }
    void  ticket::telechargerPDF(){


                        // QPdfWriter pdf("C:\\Users\\HP\\Desktop\\azizcpp\\export.pdf");
                         QPdfWriter pdf("C:\\Users\\helam\\OneDrive\\Bureau\\export_pdf\\export_pdf.pdf");
                         QPainter painter(&pdf);
                        int i = 4000;
                             painter.setPen(Qt::blue);
                             painter.setFont(QFont("Arial", 30));
                             painter.drawText(1100,1200,"LISTES DES TICKET");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial",14));
                             painter.drawRect(100,100,7300,2600);
                             painter.drawRect(0,3000,9600,500);
                             painter.setFont(QFont("Arial",11));
                             painter.drawText(200,3300,"REFERENCE");
                             painter.drawText(1300,3300,"NUM");
                             painter.drawText(2200,3300,"DATEE");
                             painter.drawText(3200,3300,"NOM");
                             painter.drawText(5300,3300,"PRENOM");


                             QSqlQuery query;
                             query.prepare("select * from ticket");
                             query.exec();
                             while (query.next())
                             {
                                 painter.drawText(200,i,query.value(0).toString());
                                 painter.drawText(1300,i,query.value(2).toString());
                                 painter.drawText(2200,i,query.value(3).toString());
                                 painter.drawText(3200,i,query.value(1).toString());
                                 painter.drawText(5300,i,query.value(4).toString());



                                i = i + 500;
                             }}

   /* void ticket::printQr(const QrCode &qr) {
        int border = 4;
        for (int y = -border; y < qr.getSize() + border; y++) {
            for (int x = -border; x < qr.getSize() + border; x++) {
                std::cout << (qr.getModule(x, y) ? "##" : "  ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }


   void Ticket::generateQr()
    {
        const char *text = "Soyez les bienvenus chez spotlab!";

        const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;  // Error correction level

        // Make and print the QR Code symbol
        const QrCode qr = QrCode::encodeText(text, errCorLvl);
        printQr(qr);
        std::cout << toSvgString(qr, 200);
    }

     std::string ticket::toSvgString(const QrCode &qr, int border) {
        if (border < 0)
            throw std::domain_error("Border must be non-negative");
        if (border > INT_MAX / 2 || border * 2 > INT_MAX - qr.getSize())
            throw std::overflow_error("Border too large");

        std::ostringstream sb;
        sb << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        sb << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
        sb << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 ";
        sb << (qr.getSize() + border * 2) << " " << (qr.getSize() + border * 2) << "\" stroke=\"none\">\n";
        sb << "\t<rect width=\"100%\" height=\"100%\" fill=\"#FFFFFF\"/>\n";
        sb << "\t<path d=\"";
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                if (qr.getModule(x, y)) {
                    if (x != 0 || y != 0)
                        sb << " ";
                    sb << "M" << (x + border) << "," << (y + border) << "h1v1h-1z";
                }
            }
        }
        sb << "\" fill=\"#000000\"/>\n";
        sb << "</svg>\n";
        return sb.str();
    }*/
