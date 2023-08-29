#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e3;
int n;
int color[sz][3]; //r g b
int dp[sz][3];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}
}

void solution() {
	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
		dp[i][0] += color[i][0];
		dp[i][1] += color[i][1];
		dp[i][2] += color[i][2];
	}

	int answer = dp[n - 1][0];
	answer = min(answer, dp[n - 1][1]);
	answer = min(answer, dp[n - 1][2]);

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
