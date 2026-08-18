#ifndef TASK_H
#define TASK_H

#include <QObject>
class Task
{
public:
    explicit Task(QObject *parent = nullptr);
    Task(int e,QString a,QString b,int x,int y,int m,QString c="unfinished"):number(e),subject(a),content(b),year(x),month(y),day(m),status(c){}
    Task & operator=(const Task & o);
    void show();
    void complete();
private:
    int number;
    QString subject;
    QString content;
    int year;
    int month;
    int day;
    QString status;


signals:
};

#endif // TASK_H
