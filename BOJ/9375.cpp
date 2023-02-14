//
// Created by 이경민 on 2023/02/14.
//
#include<iostream>
#include<map>
using namespace std;

int n, answer;
map<string,int> m;
map<string,int>::iterator iter;

void init() {
    m.clear();
}

void input() {
    cin>>n;
    string a,b;
    for(int i=0; i<n; i++) {
        cin>>a;
        cin>>b;
        iter = m.find(b);
        if(iter!=m.end()) {
            ++iter->second;
        } else {
            m.insert({b,1});
        }
    }
}

void solution() {
    answer = 1;
    for(auto i:m) {
        answer *= (i.second + 1);
    }
    --answer;
    cout<<answer<<'\n';
}

void solve() {
    int t;
    cin>>t;
    while(t--) {
        init();
        input();
        solution();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
