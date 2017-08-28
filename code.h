#ifndef CODE_H
#define CODE_H

#include <QString>

class Code
{
public:
    Code();
    QString code(const QString &, const char &);

private:
    QString key;
    QString byteToQString(const QByteArray &byte);
    QByteArray qStringToByte(const QString &strInfo);

};

#endif // CODE_H
