//
// Created by 이경민 on 2023/01/01.
//
#include<iostream>
using namespace std;

#define mod 10007
int n;
int dp[1001][10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<10; i++) {
        dp[1][i]=1;
    }
    dp[2][0]=0;
    for(int i=0; i<10; i++) {
        dp[2][i]=i;
    }
    for(int i=3; i<=n; i++) {
        dp[i][1] = dp[i-1][1];
        for(int j=2; j<10; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
        }
    }
    int answer = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<10; j++) {
            answer += dp[i][j];
            answer %= mod;
        }
    }
    cout<<answer;
}
