#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e5 + 1;
const int inf = 1e9;
int n;
int min_dp[3], max_dp[3], tmp_min[3], tmp_max[3];

void solve() {
	cin >> n;
	int a, b, c;

	cin >> a >> b >> c;

	min_dp[0] = max_dp[0] = a;
	min_dp[1] = max_dp[1] = b;
	min_dp[2] = max_dp[2] = c;

	for (int i = 2; i <= n; i++) {
			cin >> a >> b >> c;

			for (int j = 0; j < 3; j++) {
				tmp_min[j] = min_dp[j];
				tmp_max[j] = max_dp[j];
			}

			min_dp[0] = a + min(tmp_min[1], tmp_min[0]);
			min_dp[1] = min(tmp_min[1], tmp_min[0]);
			min_dp[1] = b + min(min_dp[1], tmp_min[2]);
			min_dp[2] = c + min(tmp_min[1], tmp_min[2]);

			max_dp[0] = a + max(tmp_max[1], tmp_max[0]);
			max_dp[1] = max(tmp_max[1], tmp_max[0]);
			max_dp[1] = b + max(max_dp[1], tmp_max[2]);
			max_dp[2] = c + max(tmp_max[1], tmp_max[2]);
	}

	int min_ans = 1e9;
	int max_ans = -1;
	for (int i = 0; i < 3; i++) {
		min_ans = min(min_ans, min_dp[i]);
		max_ans = max(max_ans, max_dp[i]);
	}
	cout << max_ans << ' ' << min_ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
