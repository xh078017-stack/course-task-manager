#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>
#include <QDir>
#include <QString>
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(900,700);
    //按钮connect
    ui->setupUi(this);
    QPushButton * btn1=new QPushButton("添加任务",this);
    connect(btn1,&QPushButton::clicked,this,&Widget::getTask);









    QPushButton * btn5=new QPushButton("退出",this);
    connect(btn5,&QPushButton::clicked,this,&Widget::close);

    //按钮位置
    btn1->resize(450,250);
    btn5->resize(450,200);
    btn5->move(225,500);
}

void Widget::getTask()
{
    int ID;
    QString subject;
    QString content;
    QString status;
    QString data;
    bool ok;
    int i = QInputDialog::getInt(this, tr("添加任务"),
                                 tr("任务ID:"), 1, 1, 100000, 1, &ok);
    if (ok)
        ID=i;
    QString s = QInputDialog::getText(this, tr("添加任务"),
                                 tr("任务学科:"), QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok)
        subject=s;
    QString c = QInputDialog::getMultiLineText(this, tr("添加任务"),
                                 tr("任务内容:"),"null", &ok);
    if (ok)
        content=c;
    QString st = QInputDialog::getText(this, tr("添加任务"),
                                 tr("任务状态:"),QLineEdit::Normal,QDir::home().dirName(), &ok);
    if (ok)
        status=st;
    QString d = QInputDialog::getMultiLineText(this, tr("添加任务"),
                                 tr("任务截止:"),"null", &ok);
     if (ok)
         data=d;
}

// void showcaseTask()
// {

// }

Widget::~Widget()
{
    delete ui;
}
