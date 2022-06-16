//
// Created by 이경민 on 2022/06/16.
//
#include<iostream>
#include<deque>
using namespace std;

string cmd;
bool flag = false;
deque<char> dq;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    getline(cin,cmd);
    for(auto i:cmd) {
        if (i == ' ') {
            if (flag) dq.push_back(i);
            else {
                for(auto k:dq) cout<<k;
                dq.clear();
                cout<<" ";
            }
            continue;
        } else if (i == '<') {
            flag = true;
        } else if (i == '>') {
            dq.push_back(i);
            for(auto k:dq) cout<<k;
            dq.clear();
            flag = false;
            continue;
        }
        if (flag) dq.push_back(i);
        else dq.push_front(i);
    }
    for(auto i:dq) cout<<i;
    dq.clear();
}
