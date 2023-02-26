#include<iostream>
using namespace std;

const int mod = 9901;
int n;
int dp[100001];

void solve() {
    cin>>n;
    dp[0]=1;
    dp[1]=3;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]*2;
        dp[i] %= mod;
        dp[i] += dp[i-2];
        dp[i] %= mod;
    }
    cout<<dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
