#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>
#include "widget.h"

namespace Ui {
class modifyDialog;
}

class modifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit modifyDialog(QWidget *parent = 0);
    ~modifyDialog();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_close1Button_clicked();

private:
    Ui::modifyDialog *ui;
    QString password;
    QString newPassword;

    friend class Widget;
};

#endif // MODIFYDIALOG_H
