//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<deque>
#include<stack>
using namespace std;

string cmd;
int m;
char ch,x;

deque<char> front;
stack<char> back;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>cmd;
    cin>>m;
    for(auto i:cmd) front.push_back(i);
    while(m--){
        cin>>ch;
        if(ch=='L') {
            if(front.empty()) continue;
            back.push(front.back());
            front.pop_back();
        }
        else if(ch=='D') {
            if(back.empty()) continue;
            front.push_back(back.top());
            back.pop();
        }
        else if(ch=='B') {
            if(front.empty()) continue;
            front.pop_back();
        }
        else if(ch=='P') {
            cin>>x;
            front.push_back(x);
        }
    }
    while(!front.empty()) {
        cout<<front.front();
        front.pop_front();
    }
    while(!back.empty()) {
        cout<<back.top();
        back.pop();
    }
}
