#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void readFile();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_Next_clicked();

    void on_Previous_clicked();

    void on_Character_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int Q;
};

#endif // MAINWINDOW_H
