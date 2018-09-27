#include "httpclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>

extern QString base_url;
extern QString url_port;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

QString _make_url(const QString& api_url)
{
    QString url = base_url;
    if (!url.contains("http://", Qt::CaseInsensitive)
       && !url.contains("https://", Qt::CaseInsensitive)) {
        url = "http://" + base_url;
    }

    return url + (url_port.isEmpty() ? "" : QString(":" +url_port)) + api_url;
}

HttpClient::HttpClient(QObject *parent) : QObject(parent), qnam(new QNetworkAccessManager), reply(nullptr)
{
    Q_ASSERT(qnam);
}

HttpClient::~HttpClient()
{
    if (qnam) {
        delete qnam;
    }
}

void HttpClient::request(FunctionID id, const QByteArray &content)
{
    for (size_t i = 0; i < ARRAY_SIZE(FunctionURLMap); ++i) {
        if (id == FunctionURLMap[i].fid) {
            _make_request(_make_url(FunctionURLMap[i].func_url), content_type_application_json, content);
            break;
        }
    }
}

void HttpClient::_make_request(const QString &url, const QString &contentType, const QByteArray &param)
{
    QNetworkRequest request;
    request.setAttribute(QNetworkRequest::HttpStatusCodeAttribute, 200);
    request.setHeader(QNetworkRequest::ContentLengthHeader, param.length());
    request.setUrl(QUrl(url));
    if (!contentType.isEmpty()) {
        request.setHeader(QNetworkRequest::ContentTypeHeader, contentType);
    }

    if (qnam) {
        reply = qnam->post(request, param);
        Q_ASSERT(reply);

        connect(reply, &QNetworkReply::finished, this, &HttpClient::slotReadAll);
    }
}

void HttpClient::slotReadAll()
{
    if (reply) {
        QByteArray data = reply->readAll();
        emit responseData(data);
    }
}
