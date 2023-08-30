#include<iostream>
using namespace std;

int dp[11];

void solution() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

void solve() {
	int t;
	cin >> t;
	solution();
	int n;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
