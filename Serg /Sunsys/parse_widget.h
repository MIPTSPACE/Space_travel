#ifndef PARSE_WIDGET_H
#define PARSE_WIDGET_H

#include <QtWidgets>

class ParseWidget : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *pEdit;
public:
    ParseWidget(QWidget *parent = 0);
    ~ParseWidget();

private slots:
    void on_lineEdit_returnPressed();
    void line_Edit_downPressed();
    void line_Edit_upPressed();
    void on_lineEdit_selectionChanged();
};

#endif // PARSE_WIDGET_H
