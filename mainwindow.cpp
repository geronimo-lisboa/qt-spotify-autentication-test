#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myrequesthandler.h"
#include "httplistener.h"
#include "httprequesthandler.h"

#include <QtCore/QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QWebEngineView>
#include <QTextCodec>

using namespace stefanfrings;

static QString clientId="";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Configuracao do servidor
    QSettings* listenerSettings = new QSettings("../spotify-authentication-test.ini",
                                                QSettings::IniFormat, parent);
    listenerSettings->beginGroup("listener");

    clientId = listenerSettings->value("clientId").toString();

    //Ativa o servidor
    httpRequestHandler = new MyRequestHandler(this);
    httpListener = new HttpListener(listenerSettings,
                                    httpRequestHandler,
                                    this);
    //slot de click no botão de authorize
    connect(ui->btnTestAuthentication, &QPushButton::pressed, this, &MainWindow::onTestAuthClick);

}

MainWindow::~MainWindow()
{
    httpListener->close();
    delete httpListener;
    delete ui;
}

void MainWindow::onTestAuthClick()
{
    QUrl url("https://accounts.spotify.com/authorize");
    QUrlQuery query;
    query.addQueryItem("client_id", clientId);
    query.addQueryItem("response_type", "code");
    query.addQueryItem("redirect_uri", "http%3A%2F%2Flocalhost:15000");
    query.addQueryItem("state", "IXIQUICACA!");
    query.addQueryItem("scope", "user-read-private");
    url.setQuery(query.query());

//    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

//    auto request = QNetworkRequest(url);

//    QNetworkReply *reply;
//    QEventLoop loop;
//    connect (manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()), Qt::DirectConnection);
//    reply = manager->get (request);
//    loop.exec();
//    auto content = reply->readAll ();
//    qDebug(content);

    QWebEngineView* view = new QWebEngineView();
//    QString DataAsString = QTextCodec::codecForUtfText(content)->toUnicode(content);
    view->setUrl(url);
    //view->setContent(content,"Text/html", QUrl("https://accounts.spotify.com/authorize")); //Html(DataAsString);
    view->resize(600,600);
    view->show();
}

void MainWindow::onRequestFinished()
{

}
