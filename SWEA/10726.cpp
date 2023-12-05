#include<iostream>
using namespace std;

int n,m;

bool judge() {
    for(int i=0; i<n; i++) {
        int flag = m & (1<<i);
        if(!flag) {
            return flag;
        }
    }
    return true;
}

void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        cin>>n>>m;
        cout<<'#'<<tc<<' '<<(judge() ? "ON" : "OFF")<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
