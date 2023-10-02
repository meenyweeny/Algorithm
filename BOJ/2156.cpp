#include<iostream>
using namespace std;

const int sz = 1e4;
int n;
int arr[sz],dp[sz];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    for(int i=2; i<n; i++) {
        dp[i] = max(dp[i-3]+arr[i-1],dp[i-2]);
        dp[i] += arr[i];
        dp[i] = max(dp[i],dp[i-1]);
    }
    cout<<dp[n-1];
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
