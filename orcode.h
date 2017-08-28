#ifndef ORCODE_H
#define ORCODE_H

#include <QString>
#include <QTextCodec>

class OrCode
{
public:
    OrCode();
    QString Code(QString str);

private:
    QString byteToQString(const QByteArray &byte);
    QByteArray qstringToByte(const QString &strInfo);

    char key;

};

#endif // ORCODE_H
