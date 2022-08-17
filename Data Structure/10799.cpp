//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
using namespace std;

string cmd;
int sticks, answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>cmd;
    int length = cmd.length();
    for(int i=0; i<length; i++) {
        if(cmd[i]=='('){
            ++sticks;
        }
        else { // ')'
            if(cmd[i-1]=='(') { // "()" 레이저로 자를 때를 뜻함
                --sticks;
                answer+=sticks;
            }
            else {
                --sticks;
                ++answer;
            }
        }
    }
    cout<<answer;
}
