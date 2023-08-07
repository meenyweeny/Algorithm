#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e3 + 1;
int n;
int p[sz];
int dp[sz];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
}

void solution() {
	dp[1] = p[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j <= i/2; j++) {
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}
	}
	cout << dp[n];
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
