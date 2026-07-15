#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task{
public:
    int number;
    string subject;
    string content;
    string status="unfinished";
    Task (int e,string a,string b):number(e),subject(a),content(b){}
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
                    return 0;
                }
            }
            return 1;
}
int main()
{
    cout<<"=====课程任务管理器====="<<endl;
    cout<<"1.添加任务"<<endl;
    cout<<"2.查看任务"<<endl;
    cout<<"3.完成任务"<<endl;
    cout<<"4.删除任务"<<endl;
    cout<<"0.退出"<<endl;
    int n;
    vector<Task>p;
    while(1)
    {
        cout<<"请输出选项: ";
        cin>>n;
        switch (n)
        {
            case 1:
            {
                int e;
                cin>>e;
                string a,b;
                cin>>a;
                getline(cin>>ws,b);
                if (if_existed(e,p))
                {
                    Task t(e,a,b);
                    p.push_back(t);
                }
                break;
            }
            case 2:
            {
                for (int i=0;i<p.size();i++)
                {
                    p[i].show();
                }
                break;
            }
            case 3:
            {
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

                break;
            }
            case 4:
            {
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

                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
}

