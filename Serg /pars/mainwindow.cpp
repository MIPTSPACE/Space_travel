#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mytext->physicalDpiX(12);
    ui->mytext->insertPlainText("Here is a command string");
}

MainWindow::~MainWindow()
{
    delete ui;
}
