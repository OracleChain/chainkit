#include <QCoreApplication>

QString base_url;
QString url_port;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
