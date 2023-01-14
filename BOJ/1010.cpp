//
// Created by 이경민 on 2023/01/14.
//
#include<iostream>
using namespace std;

int t,n,m;
unsigned int dp[30][30];

void solve() {
    for(int i=1; i<30; i++) {
        dp[1][i] = i;
        dp[i][i] = 1;
    }

    int sum;
    for(int i=2; i<30; i++) {
        sum = 1;

        for(int j=i+1; j<30; j++) {
            sum = 1;
            for(int k=i; k<j; k++) {
                sum += dp[i-1][k];
            }
            dp[i][j] = sum;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;
    solve();
    while(t--) {
        cin>>n>>m;
        cout<<dp[n][m]<<'\n';
    }
}
