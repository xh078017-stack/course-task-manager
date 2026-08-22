#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <string>
using namespace std;

class Task
{
public:
    explicit Task(QObject *parent = nullptr);
    Task(int e,string a,string b,int x,int y,int m,string c="unfinished"):number(e),subject(a),content(b),year(x),month(y),day(m),status(c){}
    Task & operator=(const Task & o);
    void show();
    void complete();
    int get_number();
    string get_subject();
    string get_content();
    int get_year();
    int get_month();
    int get_day();
    string get_status();
private:
    int number;
    string subject;
    string content;
    int year;
    int month;
    int day;
    string status;


signals:
};

#endif // TASK_H
