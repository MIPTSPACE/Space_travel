#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:

    void on_lineEdit_returnPressed();
    void line_Edit_downPressed();
    void line_Edit_upPressed();
    void on_lineEdit_selectionChanged();
};

#endif // MAINWINDOW_H
