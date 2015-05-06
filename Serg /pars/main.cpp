#include "mainwindow.h"
#include <QApplication>
#include <QLineEdit>
#include <QtGui>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();

    return a.exec();
}
