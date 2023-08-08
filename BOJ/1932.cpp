#include<iostream>
#include<algorithm>
using namespace std;

int n;
int tri[501][501];
int dp[501][501];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
}

void solution() {
	dp[1][1] = tri[1][1];
	dp[2][1] = (tri[2][1] + dp[1][1]);
	dp[2][2] = (tri[2][2] + dp[1][1]);
	
	for (int i = 3; i <= n; i++) {
		dp[i][1] = (tri[i][1] + dp[i - 1][1]);
		for (int j = 2; j < i; j++) {
			dp[i][j] += tri[i][j];
			dp[i][j] += max(dp[i-1][j - 1], dp[i-1][j]);
		}
		dp[i][i] = (tri[i][i] + dp[i - 1][i - 1]);
	}

	int answer = -1;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[n][i]);
	}
	cout << answer;
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
