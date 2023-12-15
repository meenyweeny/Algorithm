#include<iostream>
using namespace std;

const int bucketsize = 4e3 + 1;
string a,b;
int dp[bucketsize][bucketsize];

void solve() {
    cin>>a;
    cin>>b;
    swap(a,b);
    const int alen = a.length();
    const int blen = b.length();
    a = " " + a;
    b = " " + b;
    for(int i=1; i<=alen; i++) {
        char now = a[i];
        for(int j=1; j<=blen; j++) {
            char comp = b[j];
            if(now==comp) {
                if(a[i-1]==b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 1;
                }
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=alen; i++) {
        for(int j=1; j<=blen; j++) {
            answer = max(answer, dp[i][j]);
        }
    }
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
