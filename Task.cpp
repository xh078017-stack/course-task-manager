#include "Task.h"
#include "QString"
#include <QDebug>

Task & Task::operator=(const Task & o)
{
    number=o.number;
    subject=o.subject;
    content=o.content;
    year=o.year;
    month=o.month;
    day=o.day;
    status=o.status;
}
void Task::complete()
{
     status="finished";
}

void Task::show()
{
    qDebug()<<number<<" "<<subject<<" "<<content<<" "<<year<<"-"<<month<<"-"<<day<<" "<<status;
}