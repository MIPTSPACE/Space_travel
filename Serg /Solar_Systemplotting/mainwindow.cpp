#include "widget.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

QTimer *timer;
int interval;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Solar System"));

    Widget *native = new Widget(&helper, this, ui->label);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    setLayout(layout);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), native, SLOT(animate()));
    interval = 20;
    timer->start();
    timer->setInterval(interval);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start();
    interval -= 2;
    timer->setInterval(interval);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->start();
    interval += 2;
    timer->setInterval(interval);
}

void MainWindow::on_pushButton_3_clicked()
{
    timer->stop();
}

void MainWindow::on_pushButton_4_clicked()
{
    timer->start();
}
