#include<iostream>
using namespace std;

string cmd;

void solution() {
    int length = cmd.length();
    bool flag = true;
    for(int i=0; i<length/2; i++) {
        if(cmd[i]!=cmd[length-1-i]) {
            flag = false;
            break;
        }
    }
    flag ? cout<<"yes" : cout<<"no";
    cout<<'\n';
}

void solve() {
    while(1) {
        cin >> cmd;
        if(cmd == "0") {
            break;
        }
        solution();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
