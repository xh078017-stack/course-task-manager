#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>
#include <QDir>
#include <string>
#include <QPushButton>
#include <QDebug>
#include <QVector>
#include <fstream>
#include "Task.h"
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ofstream file("C:/Qt/Qt Project Location/Task/text.txt");
    string buffer;
    ifstream fin("text.txt",ios::in);
    if (fin.is_open()==false)
    {
        qDebug()<<"文件不存在，请先创建";
    }

    while(getline(fin,buffer))
    {
        size_t pos1=buffer.find("|");
        size_t pos2=buffer.find("|",pos1+1);
        size_t pos3=buffer.find("|",pos2+1);
        size_t pos4=buffer.find("-",pos3+1);
        size_t pos5=buffer.find("-",pos4+1);
        size_t pos6=buffer.find("|",pos5+1);
        Task T(stoi(buffer.substr(0,pos1)),buffer.substr(pos1+1,pos2-pos1-1),buffer.substr(pos2+1,pos3-pos2-1),stoi(buffer.substr(pos3+1,pos4-pos3-1)),stoi(buffer.substr(pos4+1,pos5-pos4-1)),stoi(buffer.substr(pos5+1,pos6-pos5-1)),buffer.substr(pos6+1));
        p.push_back(T);
    }
    fin.close();





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


int Widget::if_existed(int x)
{
    for (int i=0;i<p.size();i++)
    {
        if (x==p[i].get_number())
        {
            qDebug()<<x<<" has existed";
            return 0;
        }
    }
    return 1;
}

//按钮功能实现
void Widget::getTask()
{
    ofstream fout("text.txt",ios::app);
    if (fout.is_open()==false)
    {
        qDebug()<<"打开文件"<<"text.txt"<<"失败";
        return;
    }
    int ID;
    string subject;
    string content;
    string status;
    string data;
    bool ok;
    int i = QInputDialog::getInt(this, tr("添加任务"),
                                 tr("任务ID:"), 1, 1, 100000, 1, &ok);
    if (ok)
        ID=i;
    string s = QInputDialog::getText(this, tr("添加任务"),
                                     tr("任务学科:"), QLineEdit::Normal,QDir::home().dirName(), &ok).toStdString();
    if (ok)
        subject=s;
    string c = QInputDialog::getMultiLineText(this, tr("添加任务"),
                                     tr("任务内容:"),"null", &ok).toStdString();
    if (ok)
        content=c;
    string st = QInputDialog::getText(this, tr("添加任务"),
                                     tr("任务状态:"),QLineEdit::Normal,QDir::home().dirName(), &ok).toStdString();
    if (ok)
        status=st;
    string d = QInputDialog::getMultiLineText(this, tr("添加任务"),
                                     tr("任务截止:"),"2007-8-17", &ok).toStdString();
    if (ok)
        data=d;
    if(if_existed(i))
    {
        size_t pos1=data.find("-");
        size_t pos2=data.find("-");
        int year=stoi(data.substr(0,pos1));
        int month=stoi(data.substr(pos1+1,pos2-pos1-1));
        int day=stoi(data.substr(pos2+1));
        Task t(ID,subject,content,year,month,day,status);
        p.push_back(t);
        fout<<t.get_number()<<"|"<<t.get_subject()<<"|"<<t.get_content()<<"|"<<t.get_year()<<"-"<<t.get_month()<<"-"<<t.get_day()<<"|"<<t.get_status();
    }
    fout.close();

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
    ofstream out("text.txt");
    for (int i=0;i<p.size();i++)
    {
        out<<p[i].get_number()<<"|"<<p[i].get_subject()<<"|"<<p[i].get_content()<<"|"<<p[i].get_year()<<"-"<<p[i].get_month()<<"-"<<p[i].get_day()<<"|"<<p[i].get_status();
    }
    out.close();

}

void Widget::delete_()
{
    bool ok;
    int num=QInputDialog::getInt(this,tr("删除的任务"),
                                   tr("删除的任务ID："),1,1,100000,1,&ok);
    if (ok)
        p.removeAt(num-1);
    ofstream out("text.txt");
    for (int i=0;i<p.size();i++)
    {
        out<<p[i].get_number()<<"|"<<p[i].get_subject()<<"|"<<p[i].get_content()<<"|"<<p[i].get_year()<<"-"<<p[i].get_month()<<"-"<<p[i].get_day()<<"|"<<p[i].get_status();
    }
    out.close();

}

Widget::~Widget()
{
    delete ui;
}
