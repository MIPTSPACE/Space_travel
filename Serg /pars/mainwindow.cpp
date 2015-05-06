#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <myparser.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     connect(ui->lineEdit,SIGNAL(ui->lineEdit->keyPressEvent(0x01000001)),this,SLOT(line_Edit_upPressed()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString str=ui->lineEdit->text();
    QStringList  s=splitintowords(str," ");
    ui->lineEdit->setText(s);

   // ui->lineEdit->clear();

}
void MainWindow::line_Edit_downPressed()
{
    ui->lineEdit->undo();
}
void MainWindow::line_Edit_upPressed()
{
    ui->lineEdit->setText("RAAAA");
}
