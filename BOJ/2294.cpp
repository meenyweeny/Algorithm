#include<iostream>
using namespace std;

int n,k;
int coin[101];
const int inf = 1e9;
int dp[10001];

void input() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>coin[i];
    }
}

void solution() {
    fill(dp,dp+10001,inf);
    dp[0] = 0;
    int now;
    for(int i=0; i<n; i++) {
        now=coin[i];
        for(int j=now; j<=k; j++) {
            dp[j] = min(dp[j], dp[j-now]+1);
        }
    }
    if(dp[k]>=inf) {
        cout<<-1;
    } else {
        cout<<dp[k];
    }
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
