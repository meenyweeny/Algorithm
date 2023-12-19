#include<iostream>
using namespace std;

string a,b,c;
int dp[101][101][101];

void make_dp() {
    for(int i=1; i<a.length(); i++) {
        char now = a[i];
        for(int j=1; j<b.length(); j++) {
            char comp = b[j];
            for(int k=1; k<c.length(); k++) {
                char com = c[k];
                if(now==comp && comp==com) {
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
                }
            }
        }
    }
}

void solve() {
    cin>>a;
    cin>>b;
    cin>>c;
    a = '1'+a;
    b = '2'+b;
    c = '3'+c;
    make_dp();
    cout<<dp[a.length()-1][b.length()-1][c.length()-1];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
