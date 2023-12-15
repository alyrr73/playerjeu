#include "widget.h"
#include "ui_widget.h"

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include<QTableWidget>
#include<QTableView>
#include<QSqlTableModel>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QPushButton>
#include <QMessageBox>
#include <QtGui>
#include <qwidget.h>







Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("basedd");
    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open()){

    }
    else
    {
        qDebug()<<"La connexion a échouée, désolé"<<db.lastError().text();
    }


    QPushButton *BQuit;
    BQuit = new QPushButton(QString::fromUtf8("show"),this);

    connect(BQuit, SIGNAL(clicked()),this, SLOT(ShowStats()));
    // connect(ui ->Affichejoueur, &QPushButton::clicked, this, &Widget::affichejoueur);
    // connect(ui ->Affichenote, &QPushButton::clicked, this, &Widget::affichenote);

}
    void Widget::ShowStats(){
        db.setDatabaseName("basedd");
        db.setUserName("student");
        db.setPassword("crif2024sn");
        if(db.open()){
             qDebug()<<"La connexion a été, établie"<<db.lastError().text();
    QSqlQuery query;
             query.exec("SELECT * FROM jeu");
        while(query.next());{
        Model = new QSqlTableModel();
            Model->setTable("item");
            Model->select();
            ui->tableView->setModel(Model);
        }
        }
    }





// void Widget::Affichejoueur(){
//     QSqlQueryModel *Model = new QSqlQueryModel();
//     Model ->setQuery ("SELECT * FROM `item`");
//     ui->tableView->setModel(Model);
// }

// void Widget::Affichenote(){
//     QModelIndex selectIndex = ui->tableView->selectionModel()->selectedIndexes();

//     if(!selectIndex.isEmpty()){
//         int row = selectIndex.first().row();
//         int idPlayer = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toint();

//         QSqlQuery query;



Widget::~Widget()
{
    delete ui;
}
