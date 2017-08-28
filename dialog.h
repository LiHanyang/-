#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QPoint>
#include <QMouseEvent>
#include "widget.h"
#include "orcode.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    QPoint move_point;
    bool mouse_press;

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString getAccount();
    QString getPassword();

private slots:
    void on_loginButton_clicked();
    void on_applyButton_clicked();
    void on_exitButton_clicked();
    void on_submitButton_clicked();
    void on_cancelButton_clicked();
    void on_min1Button_clicked();
    void on_min2Button_clicked();
    void on_close1Button_clicked();
    void on_close2Button_clicked();

private:
    void setUi();
    void setWindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Dialog *ui;
    int sign;
    QString account;
    QString password;
    QString newAccount;
    QString newPassword;
    QString checkAccount;
    QString checkPassword;
    OrCode orcWidget;
    bool isHide;
    friend class Widget;
};

#endif // DIALOG_H
