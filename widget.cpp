#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>
#include <QDir>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QVector>
#include "Task.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(900,700);
    //按钮connect
    ui->setupUi(this);
    QPushButton * btn1=new QPushButton("添加任务",this);
    connect(btn1,&QPushButton::clicked,this,&Widget::getTask);
    QPushButton * btn2=new QPushButton("查看任务",this);
    connect(btn2,&QPushButton::clicked,this,&Widget::showcaseTask);
    QPushButton * btn3=new QPushButton("完成任务",this);
    connect(btn3,&QPushButton::clicked,this,&Widget::finish);
    QPushButton * btn4=new QPushButton("删除任务",this);
    connect(btn4,&QPushButton::clicked,this,&Widget::delete_);








    QPushButton * btn5=new QPushButton("退出",this);
    connect(btn5,&QPushButton::clicked,this,&Widget::close);

    //按钮大小，位置
    btn1->resize(450,250);
    btn2->resize(450,250);
    btn2->move(450,0);
    btn3->resize(450,250);
    btn3->move(0,250);
    btn4->resize(450,250);
    btn4->move(450,250);
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
                                 tr("任务截止:"),"2007-8-17", &ok);
     if (ok)
         data=d;
     QStringList list=data.split(u'-');
     int year=list[0].toInt();
     int month=list[1].toInt();
     int day=list[2].toInt();
     Task t(ID,subject,content,year,month,day,status);
     p.push_back(t);

}

void Widget::showcaseTask()
{
    for(int i=0;i<p.size();i++)
    {
       p[i].show();
    }
}

void Widget::finish()
{
    bool ok;
    int num=QInputDialog::getInt(this,tr("完成的任务"),
                                   tr("完成的任务ID："),1,1,100000,1,&ok);
    if (ok)
        p[num-1].complete();

}

void Widget::delete_()
{
    bool ok;
    int num=QInputDialog::getInt(this,tr("删除的任务"),
                                   tr("删除的任务ID："),1,1,100000,1,&ok);
    if (ok)
        p.removeAt(num-1);

}

Widget::~Widget()
{
    delete ui;
}
