#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include<QTableWidget>
#include<QTableView>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void Affichejoueur();
    void Affichenote();
    void ShowStats();


private:
    Ui::Widget *ui;
       QSqlTableModel *Model;
    QSqlDatabase db ;
};
#endif // WIDGET_H


