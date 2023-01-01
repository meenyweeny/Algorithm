//
// Created by 이경민 on 2023/01/01.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int map[1001][1001];
int dp[1001][1001];

int dx[3]={1,0,1};
int dy[3]={0,1,1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>map[i][j];
        }
    }
    dp[1][1]=map[1][1];

    for(int i=2; i<=m; i++) {
        dp[1][i] = map[1][i] + dp[1][i-1];
    }

    for(int i=2; i<=n; i++) {
        dp[i][1] = dp[i-1][1] + map[i][1];
    }

    int maxi = -1;

    for(int i=2; i<=n; i++) {
        for(int j=2; j<=m; j++) {
            maxi = -1;
            dp[i][j] = map[i][j];
            maxi = max(dp[i-1][j-1], dp[i-1][j]);
            maxi = max(maxi,dp[i][j-1]);
            dp[i][j]+=maxi;
        }
    }
    cout<<dp[n][m];
}
