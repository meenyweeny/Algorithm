#include<iostream>
using namespace std;

int n,m,answer;
bool seat[41];
int dp[41];

void input() {
    cin>>n>>m;
    int idx;
    for(int i=1; i<=m; i++) {
        cin>>idx;
        seat[idx] = true;
    }
}

void solution() {
    dp[0] = 1;
    dp[1] = 1;
    answer = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int count = 0;
    for(int i=1; i<=n; i++) {
        if(seat[i]) {
            answer *= dp[count];
            count = 0;
        } else {
            ++count;
        }
    }
    answer *= dp[count];
    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
