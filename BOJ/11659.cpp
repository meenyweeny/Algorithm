//
// Created by 이경민 on 2023/01/19.
//
#include<iostream>
using namespace std;

int n,m;
int dp[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>dp[i];
    }
    for(int i=2; i<=n; i++) {
        dp[i] += dp[i-1];
    }
    int i,j;
    while(m--) {
        cin>>i>>j;
        cout<<dp[j]-dp[i-1]<<'\n';
    }
}
