//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<stack>
using namespace std;

string cmd;
int m;
char ch,x;
string answer;

stack<char> front;
stack<char> back;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>cmd;
    cin>>m;
    for(auto i:cmd) front.push(i);
    while(m--){
        cin>>ch;
        if(ch=='L') {
            if(front.empty()) continue;
            back.push(front.top());
            front.pop();
        }
        else if(ch=='D') {
            if(back.empty()) continue;
            front.push(back.top());
            back.pop();
        }
        else if(ch=='B') {
            if(front.empty()) continue;
            front.pop();
        }
        else if(ch=='P') {
            cin>>x;
            front.push(x);
        }
    }
    while(!front.empty()) {
        answer+=front.top();
        front.pop();
    }
    reverse(answer.begin(), answer.end());
    cout<<answer;
    while(!back.empty()) {
        cout<<back.top();
        back.pop();
    }
}
