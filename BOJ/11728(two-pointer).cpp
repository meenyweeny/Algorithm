//
// Created by 이경민 on 2023/01/28.
//
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
vector<int> vv;
int n,m,s,e;

void input() {
    cin>>n>>m;
    int k;
    while(n--) {
        cin>>k;
        v.push_back(k);
    }
    while(m--) {
        cin>>k;
        vv.push_back(k);
    }
}

void solution() {
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    n = v.size();
    m = vv.size();

    s = e = 0;

    while(s<n || e<m) {
        if(s<n && e<m) {
            if(v[s] == vv[e]) {
                cout<<v[s]<<' '<<vv[e]<<' ';
                ++s;
                ++e;
            } else if(v[s] < vv[e]) {
                cout<<v[s]<<' ';
                ++s;
            } else {
                cout<<vv[e]<<' ';
                ++e;
            }
        } else if(s>=n) {
            cout<<vv[e]<<' ';
            ++e;
        } else {
            cout<<v[s]<<' ';
            ++s;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
