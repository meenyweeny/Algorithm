#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n,m;
vector<string> v;
map<string,int> mp;

bool cmp(string a, string b) {
    auto af = mp.find(a);
    auto bf = mp.find(b);
    if(af->second == bf->second) {
        if(a.length() == b.length()) {
            return a < b;
        } else {
            return a.length() > b.length();
        }
    } else {
        return af->second > bf->second;
    }
}

void input() {
    cin>>n>>m;
    string cmd;
    while(n--) {
        cin>>cmd;
        if(cmd.length()<m) {
            continue;
        }
        auto f = mp.find(cmd);
        if(f == mp.end()) {
            mp.insert({cmd,1});
            v.push_back(cmd);
        } else {
            ++f->second;
        }
    }
}

void solve() {
    input();
    sort(v.begin(), v.end(), cmp);
    for(auto s:v) {
        cout<<s<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
