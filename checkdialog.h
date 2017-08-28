#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H

#include <QDialog>
#include "widget.h"

namespace Ui {
class CheckDialog;
}

class CheckDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckDialog(QWidget *parent = 0);
    ~CheckDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CheckDialog *ui;
    QString password;
    QTimer *timer;

    friend class Widget;
};

#endif // CHECKDIALOG_H
