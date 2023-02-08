//
// Created by 이경민 on 2023/02/07.
//
#include<iostream>
using namespace std;

int n;
int dp[31];

void solve() {
    cin>>n;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    int sum;
    for(int i=3; i<=n; i++) {
        sum = 0;
        if(i%2==1) {
            dp[i] = 0;
            continue;
        }
        sum+=(dp[i-2]*dp[2]);
        for(int j=2; j<=i-4; j++) {
            sum+=(dp[j]*2);
        }
        dp[i]=sum;
        dp[i]+=2;
    }

    cout<<dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
