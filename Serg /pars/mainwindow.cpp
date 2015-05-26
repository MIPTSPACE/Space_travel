#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <myparser.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString str=ui->lineEdit->text();
    //QStringList  s=splitintowords(str," ");

    //ui->lineEdit->setText(myanswer(s[0]));
    ui->lineEdit->setText(Parsecommand(str));
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

void MainWindow::on_lineEdit_selectionChanged()
{
   // if(ui->lineEdit->event( ) line_Edit_upPressed();
}
