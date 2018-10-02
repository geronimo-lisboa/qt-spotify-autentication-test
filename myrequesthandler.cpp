#include "myrequesthandler.h"
#include <QTextCodec>
#include <QDebug>
#include <string>
MyRequestHandler::MyRequestHandler(QObject *parent)
    :HttpRequestHandler (parent)
{
    qDebug("criando o request mapper");
}

MyRequestHandler::~MyRequestHandler()
{
    qDebug("matando o request mapper");
}

void MyRequestHandler::service(HttpRequest &req, HttpResponse &resp)
{
    auto requestBody = req.getBody();
    std::string whatMethod = req.getMethod().toStdString();
    if(whatMethod!="GET"){
        qDebug("SÓ PODE GETs!");
        return;
    }
    auto params = req.getParameterMap();
    qDebug(requestBody);
    QByteArray reqBodyData = req.getBody();
}
