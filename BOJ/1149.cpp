//
// Created by 이경민 on 2022/09/09.
//
#include<iostream>
#include<algorithm>
using namespace std;

#define R 0
#define G 1
#define B 2

int n,answer;
int price[1001][3];
int dp[1001][3];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>price[i][R]>>price[i][G]>>price[i][B];
    dp[1][R]=price[1][R];
    dp[1][G]=price[1][G];
    dp[1][B]=price[1][B];
    for(int i=2; i<=n; i++) {
        dp[i][R] = min(dp[i-1][G],dp[i-1][B])+price[i][R];
        dp[i][G] = min(dp[i-1][R],dp[i-1][B])+price[i][G];
        dp[i][B] = min(dp[i-1][R],dp[i-1][G])+price[i][B];
    }
    answer = min(dp[n][R],dp[n][G]);
    answer = min(answer,dp[n][B]);
    cout<<answer;
}