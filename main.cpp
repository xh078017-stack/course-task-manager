#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

struct Task{
public:
    int number;
    string subject;
    string content;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    string status;
    Task (int e,string a,string b,int x,int y,int m,int n,int o,string c="unfinished"):number(e),subject(a),content(b),year(x),month(y),day(m),hour(n),minute(o),status(c){}
    void complete() 
    {
        status="finished";
    }
};

int if_existed(int x,const vector<Task> &p)
{
    for (int i=0;i<p.size();i++)
            {
                if (x==p[i].number)
                {
                    cout<<x<<" has existed"<<endl;
                    return 1;
                }
            }
            return 0;
}

time_t convert(int year,int month,int day,int hour,int minute,int second=0)
{
    tm info{};
    info.tm_year=year-1900;
    info.tm_mon=month-1;
    info.tm_mday=day;
    info.tm_hour=hour;
    info.tm_min=minute;
    return mktime(&info);
}
int main()
{
    time_t now=time(nullptr);
    int n;
    vector<Task>p;
    string buffer;
    
    ifstream fin("text.txt",ios::in);
    if (fin.is_open()==false)
    {
        cout<<"文件不存在，请先创建"<<endl;
    }

    while(getline(fin,buffer))
    {
        size_t pos1=buffer.find("|");
        size_t pos2=buffer.find("|",pos1+1);
        size_t pos3=buffer.find("|",pos2+1);
        size_t pos4=buffer.find("|",pos3+1);
        size_t pos5=buffer.find("-",pos4+1);
        size_t pos6=buffer.find("-",pos5+1);
        size_t pos7=buffer.find("-",pos6+1);
        size_t pos8=buffer.find("-",pos7+1);
        Task a(stoi(buffer.substr(0,pos1)),buffer.substr(pos1+1,pos2-pos1-1),buffer.substr(pos2+1,pos3-pos2-1),stoi(buffer.substr(pos4+1,pos5-pos4-1)),stoi(buffer.substr(pos5+1,pos6-pos5-1)),stoi(buffer.substr(pos6+1,pos7-pos6-1)),stoi(buffer.substr(pos7+1,pos8-pos7-1)),stoi(buffer.substr(pos8+1)),buffer.substr(pos3+1,pos4-pos3-1));
        p.push_back(a);
    }
    fin.close();
    cout<<"=====课程任务管理器====="<<endl;
    cout<<"1.添加任务"<<endl;
    cout<<"2.查看任务"<<endl;
    cout<<"3.完成任务"<<endl;
    cout<<"4.删除任务"<<endl;
    cout<<"0.退出"<<endl;
    
    for (int i=0;i<p.size();i++)
    {
        if (p[i].status=="unfinished")
        {
            time_t t;
            t=convert(p[i].year,p[i].month,p[i].day,p[i].hour,p[i].minute);
            if (t-now<=0)
            {
                cout<<"任务"<<p[i].number<<"已逾期"<<endl;
            }
            else if(t-now<=86400)
            {
                cout<<"任务"<<p[i].number<<"还剩不到1天"<<endl;
            }
            else if (t-now<=259200)
            {
                cout<<"任务"<<p[i].number<<"还剩不到3天"<<endl;
            }

        }
        else
        {
            continue;
        }
    }
    while(1)
    {
        cout<<"请输出选项: ";
        cin>>n;
        switch (n)
        {
            case 1:
            {
                ofstream fout("text.txt",ios::app);
                if (fout.is_open()==false)
                {
                    cout<<"打开文件"<<"text.txt"<<"失败"<<endl;
                    return 0;
                }
                int e;
                cout<<"ID:";
                cin>>e;
                string a,b;
                cout<<"subject:";
                cin>>a;
                cout<<"content:";
                getline(cin>>ws,b);
                int x,y,m,n,o;
                cout<<"Date(year month(1~12) day hour(0~23) minute(0~59)):";
                cin>>x>>y>>m>>n>>o;

                if (!if_existed(e,p))
                {
                    Task t(e,a,b,x,y,m,n,o);
                    p.push_back(t);
                    fout<<t.number<<"|"<<t.subject<<"|"<<t.content<<"|"<<t.status<<"|"<<t.year<<"-"<<t.month<<"-"<<t.day<<"-"<<t.hour<<"-"<<t.minute<<endl;
                }
                fout.close();
                break;
            }
            case 2:
            {
                for (int i=0;i<p.size();i++)
                {
                    cout<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<"|"<<p[i].year<<"-"<<p[i].month<<"-"<<p[i].day<<"-"<<p[i].hour<<"-"<<p[i].minute<<endl;
                }
                break;
            }
            case 3:
            {
                ofstream out("text.txt");
                int d;
                cout<<"number:";
                cin>>d;
                bool found = false;

                for (int i = 0; i < p.size(); i++)
                {
                    if (d == p[i].number)
                    {
                        p[i].complete();
                        found = true;
                        break;
                    }
                    
                }

                if (!found)
                {
                    cout << d << " does not exist" << endl;
                }
                for (int i=0;i<p.size();i++)
                {
                out<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<"|"<<p[i].year<<"-"<<p[i].month<<"-"<<p[i].day<<"-"<<p[i].hour<<"-"<<p[i].minute<<endl;
                }
                out.close();
                break;
            }
            case 4:
            {
                ofstream out("text.txt");
                int f;
                cout << "number:";
                cin >> f;

                bool found = false;

                for (int i = 0; i < p.size(); i++)
                {
                    if (f == p[i].number)
                    {
                        p.erase(p.begin() + i);
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << f << " does not exist" << endl;
                }
                for (int i=0;i<p.size();i++)
                {
                out<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<"|"<<p[i].year<<"-"<<p[i].month<<"-"<<p[i].day<<"-"<<p[i].hour<<"-"<<p[i].minute<<endl;
                }
                out.close();
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
}
// 完成、删除时过早打开文件：ofstream out("text.txt") 会立即清空文件，程序中途退出可能丢数据。
// 文件格式异常会导致 stoi 崩溃：例如空行、旧版数据或手动修改文件。
// 日期没有合法性检查：可能输入 15月40日。
// 保存文件的代码重复：完成和删除中都有同样的写入循环。
// 变量和函数命名可以更清楚：例如 p、a、b、if_existed。
// 无效菜单选项没有提示。
// 所有代码都在一个文件中：做图形应用后需要逐渐拆分。

// 有时候代码太长，上下翻动看的很麻烦
