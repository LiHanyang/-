#include "widget.h"
#include "dialog.h"
#include <QApplication>
#include <iostream>

int id;

int main(int argc, char *argv[])
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dbname");
    db.open();
    QString s = QString("create table user(id int primary key, name varchar(50), passwd varchar(50),"
                        "catalogue_1 varchar(50), catalogue_2 varchar(50), data varchar(50),"
                        "url varchar(50), time varchar(100))");
    QSqlQuery query;
    query.exec(s);

    s = QString("insert into user values(0, NULL, NULL, NUll, NUll, NULL, NULL, NULL) ");
    query.exec(s);

    s = QString("select * from user");
    query.exec(s);
    query.last();
    id = query.value(0).toInt();

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));

    Dialog d;


    if(d.exec() == Dialog::Accepted)
    {
        Widget w;
        w.getAccount(d.getAccount());
        w.getPassword(d.getPassword());
        w.firstShow();
        w.show();
        return a.exec();
    }
}
