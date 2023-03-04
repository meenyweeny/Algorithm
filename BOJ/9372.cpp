#include<iostream>
using namespace std;

int n;

void solve() {
    int t;
    cin>>t;
    int m,a,b;
    while(t--) {
        cin>>n>>m;
        while(m--) {
            cin>>a>>b;
        }
        cout<<n-1<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
