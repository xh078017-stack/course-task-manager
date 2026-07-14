#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task{
public:
    int number;
    string subject;
    string content;
    string status;
    Task (int e,string a,string b,string c):number(e),subject(a),content(b),status(c){}
    void show() const
    {
        cout<<number<<","<<subject<<","<<content<<","<<status<<endl;
    }
    void complete() 
    {
        status="complete";
    }
};
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
                string a,b,c;
                cin>>e>>a>>b>>c;
                Task t(e,a,b,c);
                p.push_back(t);
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
                for (int i=0;i<p.size();i++)
                {
                    if (d==p[i].number)
                    {
                        p[i].complete();
                    }
                }

                break;
            }
            case 4:
            {
                int f;
                cout<<"number:";
                cin>>f;
                for (int i=0;i<p.size();i++)
                {
                    if (f==p[i].number)
                    {
                        p.erase(p.begin()+i);
                        break;
                    }
                }
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
    return 0;
}
//有那个样子了，但是还有一些可以优化，明天继续吧。像完成任务只能一个一个来，可以优化