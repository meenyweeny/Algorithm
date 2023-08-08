#include<iostream>
using namespace std;

const int mod = 1e9;
int n;
unsigned long long dp[101][10];

void solve() {
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 9; j++) {
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= mod;
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
		dp[i][9] += dp[i - 1][8];
		dp[i][9] %= mod;
		dp[i][0] += dp[i - 1][1];
		dp[i][0] %= mod;
	}
	unsigned long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
		answer %= mod;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
