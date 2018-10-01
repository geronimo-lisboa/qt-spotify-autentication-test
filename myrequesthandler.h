#ifndef MYREQUESTHANDLER_H
#define MYREQUESTHANDLER_H
#include "httprequesthandler.h"
using namespace stefanfrings;
class MyRequestHandler : public HttpRequestHandler
{
    Q_OBJECT
    Q_DISABLE_COPY(MyRequestHandler)
public:
    MyRequestHandler(QObject* parent=0);
    ~MyRequestHandler();
    void service(HttpRequest& req, HttpResponse& resp) override;
};

#endif // MYREQUESTHANDLER_H
