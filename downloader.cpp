#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>
#include <QDir>

#include "downloader.h"

const char defaultUrl[] = "https://developer.android.com/";

Downloader::Downloader(QObject *parent) : QObject(parent)
    ,reply(nullptr)
    ,file(nullptr)
{
    connect(&qnam, &QNetworkAccessManager::finished, this, &Downloader::onReply);
}

bool Downloader::startRequest()
{
    QString fileName = "/home/evgenii/mrm/page.html";
    file = new QFile(fileName);

    if(!file->open(QIODevice::WriteOnly))
    {
        delete file;
        file = nullptr;
        return false;
    }

    QUrl url = QUrl(defaultUrl);
    QNetworkRequest request(url);

    reply = qnam.get(request);

    connect(reply, &QNetworkReply::readyRead, this, &Downloader::readyRead);

    return true;
}


void Downloader::readyRead()
{
    if(file)
        file->write(reply->readAll());
}


void Downloader::onReply(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        file->flush();
        file->close();
    }

    delete file;
    file = nullptr;
    reply->deleteLater();
}
