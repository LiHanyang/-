#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QStyle>
#include <QStyleFactory>
#include <QStandardItem>
#include <vector>
#include <QDebug>
#include <QInputDialog>
#include <QClipboard>
#include <QDateTime>
#include <QColor>
#include <QPoint>
#include <QMouseEvent>
#include <QTimer>
#include <QToolTip>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include "orcode.h"
#include "dialog.h"
#include "msg.h"
#include "checkdialog.h"

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QPoint move_point;
    bool mouse_press;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void getAccount(QString account);
    void getPassword(QString password);
    void firstShow();

private slots:
    void on_exitButton_clicked();
    void on_rootAddButton_clicked();
    void on_rootDeleteButton_clicked();
    void on_accountAddButton_clicked();
    void on_accountDeleteButton_clicked();
    void on_rootTable_clicked(const QModelIndex &index);
    void on_accountEdit_textChanged(const QString &arg1);
    void on_passwordEdit_textChanged(const QString &arg1);
    void on_urlEdit_textChanged(const QString &arg1);
    void on_accountTable_clicked(const QModelIndex &index);
    void on_saveButton_clicked();
    void on_setRandomAccount_clicked();
    void on_setRandomPassword_clicked();
    void on_searchCata_1_textChanged(const QString &arg1);
    void on_searchCata_2_textChanged(const QString &arg1);
    void on_min1Button_clicked();
    void on_close1Button_clicked();
    void on_showPassword_clicked();
    void showCheckDialog();
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

    void on_searchUrl_textChanged(const QString &arg1);

private:
    void setWindow();
    void setUi();
    void setRootTable();
    void setAccountTable();
    int checkPassword(const QString& password);
    void checkTime(QSqlQuery &query, int row);
    void isRepeated(QStandardItemModel *itemModel, int nCount, QString &catalogue, QString &cata);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void setTimer();

private:
    Ui::Widget *ui;
    QString userAccount;
    QString userPassword;
    QStandardItemModel *accountItemModel;
    QStandardItemModel *rootItemModel;
    int rootCount;
    int accountCount;
    QString catalogue_1;
    QString catalogue_2;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    OrCode orcWidget;
    QTimer *timer;
    int i;
    QSystemTrayIcon* systemTray;
    QAction* restore;
    QAction* quit;
    QMenu* menu;

    friend class Dialog;
    friend class Msg;
    friend class CheckDialog;
};

#endif // WIDGET_H
