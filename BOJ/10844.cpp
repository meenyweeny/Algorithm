//
// Created by 이경민 on 2022/09/13.
//
#include<iostream>
using namespace std;

#define mod 1000000000

int n,answer;
unsigned long long dp[101][10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<10; i++) dp[1][i]=1;
    for(int i=2; i<=n; i++) {
        dp[i][0]=dp[i-1][1]%mod;
        for(int k=1; k<9; k++){
            dp[i][k] = (dp[i-1][k-1] + dp[i-1][k+1])%mod;
        }
        dp[i][9] = (dp[i-1][8]);
    }
    for(int i=0; i<10; i++) {
        answer += (dp[n][i]);
        answer %= mod;
    }
    cout<<answer;
}
