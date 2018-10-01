#include "myrequesthandler.h"
#include <QTextCodec>
#include <QDebug>
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
    qDebug(requestBody);
    QByteArray reqBodyData = req.getBody();
    resp.setStatus(200);
    resp.flush();
}
