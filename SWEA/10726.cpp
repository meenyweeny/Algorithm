#include<iostream>
using namespace std;

int n,m;
int check, idx, full;
string answer;

void init() {
    check = idx = 0;
    full = 0;
}

void solution() {
    full = (1<<n) - 1;
    while(m>0) {
        check |= (m%2)<<(idx++);
        m/=2;
    }
    check &= full;
    answer = (check == full) ? "ON" : "OFF";
}

void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        init();
        cin>>n>>m;
        solution();
        cout<<'#'<<tc<<' '<<answer<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
