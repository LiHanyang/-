#include "orcode.h"

OrCode::OrCode()
{
    key = 60;
}

QString OrCode::Code(QString str)
{
    QString result;
    QByteArray bs = qstringToByte(str);

    for(int i=0; i<bs.size(); i++){
      bs[i] = bs[i] ^ key;
    }

    result = byteToQString(bs);
    return result;

}

QString OrCode::byteToQString(const QByteArray &byte)
{
    QString result;
    if(byte.size() > 0){
      QTextCodec *codec = QTextCodec::codecForName("GBK");
      result = codec->toUnicode(byte);
    }

    return result;
}

QByteArray OrCode::qstringToByte(const QString &strInfo)
{
    QByteArray result;
    if(strInfo.length() > 0){
      QTextCodec *codec = QTextCodec::codecForName("GBK");
      result = codec->fromUnicode(strInfo);
    }

    return result;

}
