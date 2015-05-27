#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Q = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QFile file("file.txt");
    QByteArray data;
    if (!file.open(QIODevice::ReadOnly))
           return;
    data = file.readAll();
    qDebug() << QString(data);
}

void MainWindow::on_Next_clicked()
{
    Q = Q + 1;
    if (Q > 8) {
        Q = Q - 8;
    }
    if (Q % 8 == 0) {
        ui->label->setPixmap(QPixmap(":/1.bmp"));
    }
    if (Q % 8 == 1) {
        ui->label->setPixmap(QPixmap(":/2.bmp"));
    }
    if (Q % 8 == 2) {
        ui->label->setPixmap(QPixmap(":/3.bmp"));
    }
    if (Q % 8 == 3) {
        ui->label->setPixmap(QPixmap(":/4.bmp"));
    }
    if (Q % 8 == 4) {
        ui->label->setPixmap(QPixmap(":/5.bmp"));
    }
    if (Q % 8 == 5) {
        ui->label->setPixmap(QPixmap(":/6.bmp"));
    }
    if (Q % 8 == 6) {
        ui->label->setPixmap(QPixmap(":/7.bmp"));
    }
    if (Q % 8 == 7) {
        ui->label->setPixmap(QPixmap(":/8.bmp"));
    }
}

void MainWindow::on_Previous_clicked()
{
    Q = Q - 1;
    if (Q < 0){
        Q = Q + 8;
    }
    if (Q % 8 == 0) {
        ui->label->setPixmap(QPixmap(":/1.bmp"));
    }
    if (Q % 8 == 1) {
        ui->label->setPixmap(QPixmap(":/2.bmp"));
    }
    if (Q % 8 == 2) {
        ui->label->setPixmap(QPixmap(":/3.bmp"));
    }
    if (Q % 8 == 3) {
        ui->label->setPixmap(QPixmap(":/4.bmp"));
    }
    if (Q % 8 == 4) {
        ui->label->setPixmap(QPixmap(":/5.bmp"));
    }
    if (Q % 8 == 5) {
        ui->label->setPixmap(QPixmap(":/6.bmp"));
    }
    if (Q % 8 == 6) {
        ui->label->setPixmap(QPixmap(":/7.bmp"));
    }
    if (Q % 8 == 7) {
        ui->label->setPixmap(QPixmap(":/8.bmp"));
    }
}

void MainWindow::on_Character_textEdited(const QString &arg1)
{
    ui->Character->setText(arg1);
}
