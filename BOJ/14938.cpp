#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 101;
int n, m, r;
int item[sz];
int map[sz][sz];

void init() {
	fill(&map[0][0], &map[sz - 1][sz], 1e9);
}

void input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	int a, b, l;
	while (r--) {
		cin >> a >> b >> l;
		map[a][b] = min(map[a][b], l);
		map[b][a] = min(map[b][a], l);
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int sum = item[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			if (map[i][j] <= m) {
				sum+=item[j];
			}
		}
		answer = max(answer, sum);
	}
	cout << answer;
}

void solve() {
	init();
	input();
	floyd();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
