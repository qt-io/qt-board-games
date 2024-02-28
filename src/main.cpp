#include <QQmlContext>
#include <QSettings>
#include <QDir>
#include <QGuiApplication>
#include <QLibrary>
#include <QPluginLoader>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickWindow>
#include <QtPlugin>
#include <qglobal.h>
#include "settings.h"
#include "trackinghelper.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QCoreApplication::setOrganizationName("The Qt Company");
    QCoreApplication::setOrganizationDomain("qt.io");
    QCoreApplication::setApplicationName("Board Games");

    Settings* settings = new Settings();

    // Access C++ object "settings" from QML as "settings"
    engine.rootContext()->setContextProperty("settings", settings);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    TrackingHelper::requestConsent();

    return app.exec();
}
