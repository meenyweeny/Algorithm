//
// Created by 이경민 on 2023/01/28.
//
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int n,m;

void input() {
    cin>>n>>m;
    int k;
    while(n--) {
        cin>>k;
        v.push_back(k);
    }
    while(m--) {
        cin>>k;
        v.push_back(k);
    }
}

void solution() {
    sort(v.begin(), v.end());

    int sz = v.size();
    for(int i=0; i<sz; i++) {
        cout<<v[i]<<' ';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}