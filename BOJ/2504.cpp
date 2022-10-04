//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<stack>
using namespace std;

string cmd;
stack<bool> st;
int answer;
int tmp = 1;
char ch;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>cmd;

    int length = cmd.length();

    for(int i=0; i<length; i++) {
        ch = cmd[i];
        if(ch=='('){
            st.push(0);
            tmp *= 2;
        }
        else if (ch==')') {
            if(st.empty() || st.top()!=0) {
                cout<<0;
                return 0;
            }
            if (cmd[i-1] == '(') answer += tmp;
            st.pop();
            tmp/=2;
        }
        else if(ch=='['){
            st.push(1);
            tmp *= 3;
        }
        else {
            if(st.empty() || st.top()!= 1) {
                cout<<0;
                return 0;
            }
            if(cmd[i-1] == '[') answer+=tmp;
            st.pop();
            tmp/=3;
        }
    }

    if(st.empty()) cout<<answer;
    else cout<<0;
}
