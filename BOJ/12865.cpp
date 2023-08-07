#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int w[101];
int v[101];
int knapsack[101][100001];

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] > j) {
				knapsack[i][j] = knapsack[i - 1][j];
			} else {
				knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i-1][j - w[i]] + v[i]);
			}
		}
	}
	cout << knapsack[n][k];
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
