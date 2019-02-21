#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QNetworkAccessManager>
#include <QUrl>

class QFile;
class QNetworkReply;

class Downloader : public QObject
{
    Q_OBJECT
    using BaseClass = QObject;

public:
    explicit Downloader(QObject *parent = nullptr);

    bool startRequest();

private slots:
    void readyRead();

    void onReply(QNetworkReply* reply);

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
};

#endif // DOWNLOADER_H
