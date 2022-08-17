//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<stack>
using namespace std;

string cmd;
stack<char> st;
char ch;

void print() {
    while(!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    getline(cin,cmd);
    int length = cmd.length();
    for(int i=0; i<length; i++) {
        ch = cmd[i];
        if(cmd[i]=='<') {
            print();
            while(1) {
                cout<<cmd[i];
                if(cmd[i]=='>') { break; }
                ++i;
            }
        }
        else if(ch==' ') {
            print();
            cout<<" ";
        }
        else {
            st.push(ch);
        }
    }
    print();
}
