#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Task{
public:
    int number;
    string subject;
    string content;
    string status;
    Task (int e,string a,string b,string c="unfinished"):number(e),subject(a),content(b),status(c){}
    void show() const
    {
        cout<<number<<","<<subject<<","<<content<<","<<status<<endl;
    }
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


int main()
{
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
        Task a(stoi(buffer.substr(0,pos1)),buffer.substr(pos1+1,pos2-pos1-1),buffer.substr(pos2+1,pos3-pos2-1),buffer.substr(pos3+1));
        p.push_back(a);
    }
    fin.close();
    cout<<"=====课程任务管理器====="<<endl;
    cout<<"1.添加任务"<<endl;
    cout<<"2.查看任务"<<endl;
    cout<<"3.完成任务"<<endl;
    cout<<"4.删除任务"<<endl;
    cout<<"0.退出"<<endl;
    
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
                cin>>e;
                string a,b;
                cin>>a;
                getline(cin>>ws,b);
                if (!if_existed(e,p))
                {
                    Task t(e,a,b);
                    p.push_back(t);
                    fout<<t.number<<"|"<<t.subject<<"|"<<t.content<<"|"<<t.status<<endl;
                }
                fout.close();
                break;
            }
            case 2:
            {
                for (int i=0;i<p.size();i++)
                {
                    cout<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<endl;
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
                out<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<endl;
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
                out<<p[i].number<<"|"<<p[i].subject<<"|"<<p[i].content<<"|"<<p[i].status<<endl;
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

// 查看任务建议读取 vector
// 不建议一直保持 fout 打开
// 文件里的完成状态没有恢复