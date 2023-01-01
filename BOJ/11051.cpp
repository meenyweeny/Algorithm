//
// Created by 이경민 on 2023/01/01.
//
#include<iostream>
using namespace std;

#define mod 10007

int n,k;
int dp[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2; i<=n; i++) {
        dp[i][0]=1;
        dp[i][i]=1;
        for(int j=1; j<i; j++) {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }

    cout<<dp[n][k];
}
