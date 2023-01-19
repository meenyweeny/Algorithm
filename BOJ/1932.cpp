//
// Created by 이경민 on 2023/01/19.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[501][501];

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin>>dp[i][j];
        }
    }
}

void solution() {
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    int answer = -1;
    for(int i=1; i<=n; i++) {
        answer = max(dp[n][i], answer);
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
