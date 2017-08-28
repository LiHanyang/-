#include "checkdialog.h"
#include "ui_checkdialog.h"

CheckDialog::CheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

CheckDialog::~CheckDialog()
{
    delete ui;
}

void CheckDialog::on_pushButton_2_clicked()
{
    exit(0);
}

void CheckDialog::on_pushButton_clicked()
{

    if(password != ui->lineEdit->text())
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("密码输入错误    "));
        msgBox.exec();
        timer->setInterval(1);
        close();
    }
    else
    {
        timer->setInterval(30000);
        close();
    }
}
