#include<iostream>
#include<iomanip>
using namespace std;

const int bucketsize = 5e2+1;
int dp[bucketsize][bucketsize];
int n;
string a,b;

void input() {
    cin>>n;
    cin>>a;
    cin>>b;
}

void solution() {
    a = " " + a;
    b = " " + b;
    for(int i=1; i<=n; i++) {
        char now = a[i];
        for(int j=1; j<=n; j++) {
            char comp = b[j];
            if(now==comp) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
}

double get_answer() {
    double count = dp[n][n];
    count /= n;
    return count * 100;
}

void solve() {
    int testcase;
    cin>>testcase;
    for(int tc=1; tc<=testcase; tc++) {
        input();
        fill(&dp[0][0],&dp[bucketsize-1][bucketsize],0);
        solution();
        cout<<fixed;
        cout<<'#'<<tc<<' '<<setprecision(2)<<get_answer()<<'\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
