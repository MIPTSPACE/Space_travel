#ifndef SUNSYSTEM_UI
#define SUNSYSTEM_UI

#include <QtWidgets>

#include "sunsystem_display.h"
#include "sunsystem_body.h"

#define TIMER_VAL 20

const uint SPEED_GRAD_N = 46;
const uint START_SPEED = 34;
const double SPEED_GRAD[SPEED_GRAD_N] =
    {-100000, -10000, -1000,
     -500, -250, -100, -75,
     -50, -25, -20, -15, -10,
     -9, -8, -7, -6, -5, -4,
     -3, -2, -1.5, -1, -0.5,
     0.5, 1, 1.5, 2, 3,
     4, 5, 6, 7, 8, 9,
     10, 15, 20, 25, 50,
     75, 100, 250, 500,
     1000, 10000, 100000};

class Sunsystem_UI : public QWidget{
    Q_OBJECT
private:
    uint current_speed_index;

    Sunsystem_display* pDisp;
    QLabel* pInfo;
    QDateTimeEdit* pDT;
    QPushButton *pPause;
    QPushButton *pSpeedminus;
    QPushButton *pSpeedplus;

    QTimer *pTimer;

    QDateTime DT;
    bool pause;

    Sunsystem_body* pSSB;

    void refreshInfo(){
        QString text;
        text += DT.date().toString("dd.MM.yyyy");
        text += "\n" + DT.toString("hh:mm:ss");
        text += "\nSpeed: " + QString::number(SPEED_GRAD[current_speed_index]);
        if (pause) text += "\nPAUSE";
        pInfo->setText(text);
    }

private slots:
    void speed_plus(){
        current_speed_index++;
        pSpeedminus->setEnabled(true);
        if (current_speed_index == SPEED_GRAD_N - 1)
            pSpeedplus->setEnabled(false);
        refreshInfo();
    }

    void speed_minus(){
        current_speed_index--;
        pSpeedplus->setEnabled(true);
        if (current_speed_index == 0)
            pSpeedminus->setEnabled(false);
        refreshInfo();
    }

    void paused(){
        pause = true;
        pTimer->stop();
        pPause->setText("Continue");

        disconnect(pPause, SIGNAL(clicked()),
                   this, SLOT(paused()));
        connect(pPause, SIGNAL(clicked()),
                this, SLOT(continued()));
        refreshInfo();
    }

    void continued(){
        pause = false;
        pTimer->start(TIMER_VAL);
        pPause->setText("Pause");

        disconnect(pPause, SIGNAL(clicked()),
                   this, SLOT(continued()));
        connect(pPause, SIGNAL(clicked()),
                this, SLOT(paused()));
        refreshInfo();
    }

    void setDT(){
        DT = pDT->dateTime();
        refreshInfo();
    }

    void setCurDT(){
        pDT->setDateTime(QDateTime::currentDateTime());
        DT = QDateTime::currentDateTime();
        refreshInfo();
    }

    void step(){
        ///////////////////////////////-><-///////////////////////////////
        pSSB->makeStep(SPEED_GRAD[current_speed_index]/10.0);
        DT = DT.addMSecs(TIMER_VAL*SPEED_GRAD[current_speed_index]);
        pDisp->draw();
        pDisp->repaint();
        refreshInfo();
    }

public:
    Sunsystem_UI(Sunsystem_body *system, QWidget *parent = NULL)
        : pSSB(system),
          QWidget(parent),
          DT(QDateTime::currentDateTime()),
          current_speed_index(START_SPEED),
          pause(false)
    {
        //в цей конструктор пропиши свої координати країв екрану
        //у моэму випадку відображатись буде все, що не лівіше -100, не вище 100 і т.д.
        pDisp = new Sunsystem_display(-100, 100, -100, 100, system);
        pDisp->setFixedWidth(500);
        pDisp->setFixedHeight(500);

        pSpeedplus = new QPushButton("Speed +");
        pSpeedplus->setFixedWidth(90);
        pSpeedminus = new QPushButton("Speed -");
        pSpeedminus->setFixedWidth(90);

        pPause = new QPushButton("Pause");
        pPause->setFixedWidth(200);

        //сюди в конструктор пропиши початкову дату і час
        //у моэму випадку стоїть поточний час
        pDT = new QDateTimeEdit(DT);
        pDT->setFixedWidth(200);

        QPushButton *pSetCurDT = new QPushButton("Set current");
        pSetCurDT->setFixedWidth(200);
        QPushButton *pSetDT = new QPushButton("Set date and time");
        pSetDT->setFixedWidth(200);

        pInfo = new QLabel("text\ntext\ntext\ntext\ntext\ntext");
        pInfo->setFont(QFont("Consolas", 14));
        pInfo->setPalette(QPalette(Qt::green));
        pInfo->setFrameStyle(QFrame::Panel|QFrame::Raised);
        pInfo->setLineWidth(2);
        pInfo->setAutoFillBackground(true);
        pInfo->setFixedWidth(200);
        pInfo->setFixedHeight(140);

        QGridLayout* pGrid =  new QGridLayout;
        pGrid->setSpacing(20);
        pGrid->setMargin(10);

        pGrid->addWidget(pDisp,           0, 0, 20, 1, Qt::AlignCenter);
        pGrid->addWidget(pInfo,           0, 1, 12, 2, Qt::AlignTop|Qt::AlignLeft);
        pGrid->addWidget(pSpeedplus,     11, 1,  1, 1, Qt::AlignCenter);
        pGrid->addWidget(pSpeedminus,    11, 2,  1, 1, Qt::AlignCenter);
        pGrid->addWidget(pPause,         13, 1,  1, 2, Qt::AlignCenter);
        pGrid->addWidget(pDT,            15, 1,  1, 2, Qt::AlignCenter);
        pGrid->addWidget(pSetCurDT,      16, 1,  1, 2, Qt::AlignCenter);
        pGrid->addWidget(pSetDT,         17, 1,  1, 2, Qt::AlignCenter);
        setLayout(pGrid);

        connect(pSpeedplus, SIGNAL(clicked()),
                this, SLOT(speed_plus()));
        connect(pSpeedminus, SIGNAL(clicked()),
                this, SLOT(speed_minus()));
        connect(pPause, SIGNAL(clicked()),
                this, SLOT(paused()));
        connect(pSetDT, SIGNAL(clicked()),
                this, SLOT(setDT()));
        connect(pSetCurDT, SIGNAL(clicked()),
                this, SLOT(setCurDT()));

        refreshInfo();

        pTimer = new QTimer();
        connect(pTimer, SIGNAL(timeout()),
                this, SLOT(step()));
        pTimer->start(TIMER_VAL);
    }
};

#endif // SUNSYSTEM_UI

