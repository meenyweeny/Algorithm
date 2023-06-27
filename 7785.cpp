#include<iostream>
#include<map>
using namespace std;

map<string,int,greater<string>> m;

void solve() {
    int n;
    cin>>n;
    string a,b;
    while(n--) {
        cin>>a>>b;
        ++m[a];
    }
    for(auto p:m) {
        if(p.second%2!=0) {
            cout<<p.first<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
