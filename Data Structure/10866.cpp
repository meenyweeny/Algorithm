//
// Created by 이경민 on 2022/08/26.
//
#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
int n,x;
string cmd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    while(n--) {
        cin>>cmd;
        if(cmd=="push_back") {
            cin>>x;
            dq.push_back(x);
            continue;
        }
        else if(cmd=="push_front") {
            cin>>x;
            dq.push_front(x);
            continue;
        }
        else if(cmd=="pop_front") {
            if(dq.empty()) cout<<-1;
            else {
                cout << dq.front();
                dq.pop_front();
            }
        }
        else if(cmd=="pop_back") {
            if(dq.empty()) cout<<-1;
            else {
                cout << dq.back();
                dq.pop_back();
            }
        }
        else if(cmd=="size") {
            cout<<dq.size();
        }
        else if(cmd=="empty") {
            cout<<dq.empty();
        }
        else if(cmd=="front") {
            dq.empty() ? cout<<-1 : cout<<dq.front();
        }
        else if(cmd=="back") {
            dq.empty() ? cout<<-1 : cout<<dq.back();
        }
        cout<<"\n";
    }
}
