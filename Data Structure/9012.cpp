//
// Created by 이경민 on 2022-06-14.
//
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int t;
string cmd;

bool isVPS() {
    stack<char> st;
    for(auto i:cmd){
        if (i=='(') st.push(i);
        else {
            if (!st.empty()) st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--){
        cin>>cmd;
        isVPS() ? cout << "YES\n" : cout << "NO\n";
    }
}
