#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e3 + 1;
int n;
int arr[sz];
int dp[sz];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], ((arr[j]<arr[i] ? dp[j] : 0)));
		}
		++dp[i];
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout<<answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
