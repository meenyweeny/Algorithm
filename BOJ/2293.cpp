#include<iostream>
using namespace std;

int n,k;
int arr[100];
int dp[10001];

void input() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void solution() {
    sort(arr,arr+n);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=arr[i]; j<=k; j++) {
            dp[j] += dp[j-arr[i]];
        }
    }
    cout<<dp[k];
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
