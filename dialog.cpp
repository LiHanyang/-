#include "dialog.h"
#include "widget.h"
#include "ui_dialog.h"

extern int id;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    setUi();
    setWindow();
    this->setWindowFlags(Qt::FramelessWindowHint);
    QMovie *movie = new QMovie(":/Resources/images/background.gif");
    ui->label_6->setMovie(movie);
    movie->start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
    }
    move_point = event->globalPos() - this->pos();
}

void Dialog::mouseReleaseEvent(QMouseEvent *)
{
    mouse_press = false;
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
        QPoint move_pos = event->globalPos();
        move(move_pos - move_point);
    }
}

QString Dialog::getAccount()
{
    return account;
}

QString Dialog::getPassword()
{
    return password;
}

void Dialog::setUi()
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->newPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->checkPasswordEdit->setEchoMode(QLineEdit::Password);
}

void Dialog::on_loginButton_clicked()
{
    QString uname = ui->accountEdit->text();
    QString upasswd = ui->passwordEdit->text();
    QString s = QString("select * from user where name=='%1' and passwd=='%2' ").arg(orcWidget.Code(uname)).
            arg(orcWidget.Code(upasswd));
    QSqlQuery query;
    query.exec(s);
    if(query.first())
    {
        accept();
        account = uname;
        password = upasswd;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("请检查帐户名或密码是否正确！       "));
        msgBox.exec();
        ui->passwordEdit->clear();
        ui->accountEdit->setFocus();
    }

}

void Dialog::on_applyButton_clicked()
{
    ui->newAccountEdit->clear();
    ui->newPasswordEdit->clear();
    ui->checkPasswordEdit->clear();
    int width = this->width();
    qDebug()<<width;
    if(width == 480)
    {
        this->resize(QSize(960, 400));
        ui->close1Button->hide();
        ui->min1Button->hide();
    }
    else
    {
        this->resize(QSize(480, 400));
        ui->close1Button->show();
        ui->min1Button->show();
    }
}

void Dialog::setWindow()
{
    resize(QSize(480, 400));
    setWindowTitle(" ");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
}

void Dialog::on_exitButton_clicked()
{
    exit(0);
}

void Dialog::on_submitButton_clicked()
{
    QString uname = ui->newAccountEdit->text();
    QString upasswd = ui->newPasswordEdit->text();
    QString check = ui->checkPasswordEdit->text();

    if(NULL == uname)
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("账号不能为空     "));
        msgBox.exec();
        ui->newAccountEdit->clear();
        ui->newPasswordEdit->clear();
        ui->checkPasswordEdit->clear();
        return;
    }

    QString s = QString("select * from user where name=='%1' ").arg(orcWidget.Code(uname));
    QSqlQuery query;
    query.exec(s);
    if(query.first())
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("用户已存在！     "));
        msgBox.exec();
        ui->newAccountEdit->clear();
        ui->newPasswordEdit->clear();
        ui->checkPasswordEdit->clear();
        return;
    }

    if(NULL == upasswd)
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("密码不能为空     "));
        msgBox.exec();
        ui->newPasswordEdit->clear();
        ui->checkPasswordEdit->clear();
        return;
    }

    if(upasswd != check)
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("两次密码不一致！     "));
        msgBox.exec();
        ui->newPasswordEdit->clear();
        ui->checkPasswordEdit->clear();
        return;
    }

    s = QString("insert into user values(%1, '%2', '%3', NULL, NULL, NULL, NULL, NULL) ").
            arg(++id).arg(orcWidget.Code(uname)).arg(orcWidget.Code(upasswd));
    bool ok = query.exec(s);
    if(ok)
    {
        QMessageBox msgBox;
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setStyleSheet("background-color:rgb(193,213,250)");
        msgBox.setText(tr("注册成功     "));
        msgBox.exec();
        ui->newAccountEdit->clear();
        ui->newPasswordEdit->clear();
        ui->checkPasswordEdit->clear();
        ui->newAccountEdit->setFocus();
        resize(QSize(480, 400));
        ui->close1Button->show();
        ui->min1Button->show();
    }

}

void Dialog::on_cancelButton_clicked()
{
    resize(QSize(480, 400));
    ui->close1Button->show();
    ui->min1Button->show();
}

void Dialog::on_min1Button_clicked()
{
    this->showMinimized();
}

void Dialog::on_min2Button_clicked()
{
    this->showMinimized();
}

void Dialog::on_close1Button_clicked()
{
    exit(0);
}

void Dialog::on_close2Button_clicked()
{
    exit(0);
}
