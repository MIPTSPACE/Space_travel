#include "parse_widget.h"
#include <QString>
#include <myparser.h>


ParseWidget::ParseWidget(QWidget *parent) :
    QWidget(parent)
{
    pEdit = new QLineEdit();

    QPushButton *pEnter = new QPushButton("Enter");
    QPushButton *pUp = new QPushButton("Up");
    QPushButton *pDown = new QPushButton("Down");
    QPushButton *pSelChange = new QPushButton("Change selection");

    QGridLayout *pGrid = new QGridLayout();
    pGrid->setSpacing(20);
    pGrid->setMargin(10);
    pGrid->addWidget(pEdit, 0, 0, 1, 4);
    pGrid->addWidget(pEnter, 1, 0, 1, 1);
    pGrid->addWidget(pUp, 1, 1, 1, 1);
    pGrid->addWidget(pDown, 1, 2, 1, 1);
    pGrid->addWidget(pSelChange, 1,3,1,1);
    setLayout(pGrid);

    connect(pEnter, SIGNAL(clicked()),
            this, SLOT(on_lineEdit_returnPressed()));
    connect(pUp, SIGNAL(clicked()),
            this, SLOT(line_Edit_upPressed()));
    connect(pDown, SIGNAL(clicked()),
            this, SLOT(line_Edit_downPressed()));
    connect(pSelChange, SIGNAL(clicked()),
            this, SLOT(on_lineEdit_selectionChanged()));
}

ParseWidget::~ParseWidget()
{
}


void ParseWidget::on_lineEdit_returnPressed()
{
    QString str=pEdit->text();
    //QStringList  s=splitintowords(str," ");

    //ui->lineEdit->setText(myanswer(s[0]));
    pEdit->setText(Parsecommand(str));
   // ui->lineEdit->clear();

}
void ParseWidget::line_Edit_downPressed()
{
    pEdit->undo();
}
void ParseWidget::line_Edit_upPressed()
{
    pEdit->setText("RAAAA");
}

void ParseWidget::on_lineEdit_selectionChanged()
{
   // if(ui->lineEdit->event( ) line_Edit_upPressed();
}

