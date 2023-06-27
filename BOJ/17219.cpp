#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,string> um;

void solve() {
    int n,m;
    string a,b;
    cin>>n>>m;
    while(n--) {
        cin>>a>>b;
        um[a] = b;
    }
    while(m--) {
        cin>>a;
        cout<<um[a]<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
