#include<iostream>
using namespace std;

string a,b;
int dp[1001][1001];

void solve() {
    cin>>a;
    cin>>b;

    int alen = a.length();
    int blen = b.length();
    for(int i=1; i<=alen; i++) {
        char now = a[i-1];
        char comp;
        for(int j=1; j<=blen; j++) {
            comp = b[j-1];
            if(now!=comp) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            } else {
                dp[i][j] = dp[i-1][j-1];
                ++dp[i][j];
            }
        }
    }

    cout<<dp[alen][blen];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
