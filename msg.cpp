#include "msg.h"
#include "ui_msg.h"

Msg::Msg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Msg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->okButton->setEnabled(false);
}

Msg::~Msg()
{
    delete ui;
}

void Msg::on_input_textChanged(const QString &arg1)
{
    ui->okButton->setEnabled(true);
}

void Msg::on_okButton_clicked()
{
    trans = ui->input->text();
    qDebug() << trans;
    close();

}

void Msg::on_cancelButton_clicked()
{
    close();
}


void Msg::on_close1Button_clicked()
{
    close();
}
