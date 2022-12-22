#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
int weight[101];
int value[101];
int dp[101][100001];

void input() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>weight[i]>>value[i];
    }
}

void run() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j>=weight[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    run();
    cout<<dp[n][k];
}
