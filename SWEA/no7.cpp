#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int n;
char arr[101];
string cmd;

void input() {
    getline(cin,cmd);
    n = stoi(cmd);
    for(int i=1; i<=n; i++) {
        getline(cin,cmd);
        string num = "";
        int cnt = 0;
        while(1) {
            if(cmd[cnt]==' ') {
                break;
            }
            num += cmd[cnt++];
        }
        arr[stoi(num)] = cmd[++cnt];
    }
}

void solution(int x) {
    if(x>n) {
        return;
    }
    solution(x*2);
    cout << arr[x];
    solution((x*2) + 1);
    return;
}

void solve() {
    int t = 10;
    for(int tc=1; tc<=t; tc++) {
        input();
        cout<<'#'<<tc<<' ';
        solution(1);
        cout<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
