#include<iostream>
#include<vector>
using namespace std;

int n,k;
vector<int> v;

void solve() {
    cin>>n>>k;
    string s;
    cin>>s;
    for(auto ch:s) {
        int num = ch - '0';
        while(!v.empty() && v.back()<num && k) {
            v.pop_back();
            --k;
        }
        v.push_back(num);
    }
    while(k) {
        v.pop_back();
        --k;
    }
    for(auto a:v) {
        cout<<a;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
