#include "modifydialog.h"
#include "ui_modifydialog.h"

modifyDialog::modifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->okButton->setDefault(true);
}

modifyDialog::~modifyDialog()
{
    delete ui;
}

void modifyDialog::on_okButton_clicked()
{
    QString checkPassword = ui->lineEdit_3->text();
    if(password != ui->lineEdit->text())
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("原密码不正确       "));
        msgBox.exec();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    if(NULL == ui->lineEdit_2->text())
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("新密码不能为空！       "));
        msgBox.exec();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    if(ui->lineEdit_2->text() != checkPassword)
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("新密码输入不一致！       "));
        msgBox.exec();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowFlags(Qt::FramelessWindowHint);
    msgBox.setStyleSheet("background-color:rgb(193,213,250)");
    msgBox.setText(tr("修改成功       "));
    msgBox.exec();
    newPassword = ui->lineEdit_2->text();
    close();
}

void modifyDialog::on_cancelButton_clicked()
{
    close();
}

void modifyDialog::on_close1Button_clicked()
{
    close();
}
