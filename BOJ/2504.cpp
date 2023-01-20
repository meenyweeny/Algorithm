#include<iostream>
#include<stack>
using namespace std;

string cmd;
stack<char> st;
int answer;


void input() {
    cin>>cmd;
}

void solution() {
    int sum = 1;

    int length = cmd.length();
    for(int i=0; i<length; i++) {
        char now = cmd[i];
        if(now == '(') {
            st.push(now);
            sum *= 2;
        } else if(now == '[') {
            st.push(now);
            sum *= 3;
        } else if(now == ']') {
            if(st.empty() || st.top() != '[') {
                cout<<0;
                return;
            } else {
                if(cmd[i-1] == '[') {
                    answer += sum;
                }
                sum /= 3;
                st.pop();
            }
        } else {
            if(st.empty() || st.top() != '(') {
                cout<<0;
                return;
            } else {
                if(cmd[i-1] == '(') {
                    answer += sum;
                }
                sum /= 2;
                st.pop();
            }
        }
    }
    if(st.empty()) {
        cout<<answer;
    } else {
        cout<<0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
