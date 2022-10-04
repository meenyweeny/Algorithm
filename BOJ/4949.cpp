//
// Created by 이경민 on 2022/06/06.
//
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

string cmd;
stack<char> st;

bool solve() {
    for(auto i:cmd){
        if(i=='('||i=='[') {st.push(i);}
        else if(i==')'){
            if(st.empty() || st.top()!='(') return false;
            else st.pop();
        }
        else if(i==']'){
            if(st.empty() || st.top()!='[') return false;
            else st.pop();
        }
        else continue;
    }
    return st.empty();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        getline(cin,cmd);
        if(cmd==".") break;
        solve() ? cout<<"yes\n" : cout<<"no\n";
        while(!st.empty()) st.pop();
    }
}
