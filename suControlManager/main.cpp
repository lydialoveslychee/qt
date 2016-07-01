#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton pushButton(QObject::tr("Hello Qt! "));//
    pushButton.show();
    QObject::connect(&pushButton, SIGNAL(clicked()),&app,SLOT(quit()));
    return app.exec();
}
