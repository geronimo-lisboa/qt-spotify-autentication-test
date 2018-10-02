#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "httplistener.h"
using namespace stefanfrings;
class MyRequestHandler;


class  QWebEngineView;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    HttpListener* httpListener;
    MyRequestHandler* httpRequestHandler;
    QWebEngineView* webView;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onTestAuthClick();
    void onRequestFinished();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
