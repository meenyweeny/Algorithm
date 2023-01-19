//
// Created by 이경민 on 2023/01/19.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[301];
int stair[301];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>stair[i];
    }
}

void solution() {
    dp[1] = stair[1];
    dp[2] = dp[1] + stair[2];
    dp[3] = max(stair[1], stair[2]) + stair[3];

    for(int i=4; i<=n; i++) {
        dp[i] = (max(dp[i-2], dp[i-3]+stair[i-1]) + stair[i]);
    }

    cout<<dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
