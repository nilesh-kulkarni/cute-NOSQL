#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(cutemongoui);

    QApplication app(argc, argv);
    MainWindow window;
    window.showMaximized();
    window.show();
    return app.exec();
}
