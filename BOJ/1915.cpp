#include<iostream>
#include<algorithm>
using namespace std;

int n,m,answer;
int dp[1001][1001];

void input() {
    cin>>n>>m;
    char ch;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>ch;
            dp[i][j] = ch != '0';
            answer = max(answer, dp[i][j]);
        }
    }
}

void solution() {
    int left, top;

    for(int i=2; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(dp[i][j] == 0) {
                continue;
            }

            left = dp[i][j-1];
            top = dp[i-1][j];
            int mini = min(left, top);

            if(left != top) {
                dp[i][j] = mini + 1;
            } else if(left == 0 && top == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 1;
                for(int k=1; k<=mini; k++) {
                    if(dp[i-k][j-k] == 0) {
                        break;
                    } else {
                        dp[i][j] = k+1;
                    }
                }
            }

            answer = max(answer, dp[i][j]);
        }
    }

    cout<<answer * answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
