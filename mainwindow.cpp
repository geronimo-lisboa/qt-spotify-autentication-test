#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myrequesthandler.h"
#include "httplistener.h"
#include "httprequesthandler.h"

using namespace stefanfrings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Configuracao do servidor
    QSettings* listenerSettings = new QSettings("../teste-qt-webapp/etc/webapp.ini",
                                                QSettings::IniFormat, parent);
    listenerSettings->beginGroup("listener");
    //Ativa o servidor
    httpRequestHandler = new MyRequestHandler(this);
    httpListener = new HttpListener(listenerSettings,
                                    httpRequestHandler,
                                    this);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    httpListener->close();
    delete httpListener;
    delete ui;
}
