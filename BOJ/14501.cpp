//
// Created by 이경민 on 2022/08/08.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,answer;
int t[15];
int p[15];

void solve(int next_index, int money) {
    for(int i=next_index; i<n; i++) {
        if(i+t[i] > n) {
            answer = max(answer,money);
            continue;
        }
        if(i+t[i]==n) {
            answer = max(answer,money+p[i]);
        }
        solve(i+t[i],money+p[i]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++) cin>>t[i]>>p[i];
    solve(0,0);
    cout<<answer;
}
