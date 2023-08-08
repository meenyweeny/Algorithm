#include<iostream>
#include<iomanip>
using namespace std;

int n, result;
unsigned long long dp[101][21];
int arr[101];

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
	}
	cin >> result;

	dp[1][arr[1]] = 1;

	for (int i = 2; i < n; i++) {
		int now = arr[i];
		for (int j = 0; j <= 20; j++) {
			unsigned long long before = dp[i - 1][j];
			if (j + now >= 0 && j + now <= 20) {
				dp[i][j + now] += before;
			}
			if (j - now >= 0 && j - now <= 20) {
				dp[i][j - now] += before;
			}
		}
	}

	cout << dp[n - 1][result];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
