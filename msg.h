#ifndef MSG_H
#define MSG_H

#include <QDialog>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include "msg.h"

namespace Ui {
class Msg;
}

class Msg : public QDialog
{
    Q_OBJECT

public:
    explicit Msg(QWidget *parent = 0);
    ~Msg();


public:
    QLineEdit* input;
    QLabel* label;
    QPushButton *okButton;
    QPushButton *cancelButton;

protected:

protected slots:
    void on_okButton_clicked();
    void on_input_textChanged(const QString &arg1);
    void on_cancelButton_clicked();
    void on_close1Button_clicked();

private:
    Ui::Msg *ui;
    QString trans;

    friend class Widget;


};

#endif // MSG_H
