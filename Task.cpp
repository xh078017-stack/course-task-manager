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
    qDebug()<<number<<"|"<<subject<<"|"<<content<<"|"<<year<<"-"<<month<<"-"<<day<<"|"<<status;
}

int Task::get_number()
{
    return number;
}

string Task::get_subject()
{
    return subject;
}

string Task::get_content()
{
    return content;
}

int Task::get_year()
{
    return year;
}

int Task::get_month()
{
    return month;
}

int Task::get_day()
{
    return day;
}

string Task::get_status()
{
    return status;
}