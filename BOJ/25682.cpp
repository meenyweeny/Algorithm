#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
int x, y, xx, yy;
int answer = 2e9;
int odd[2002][2002]; //W가 되어야 함
int pos[2002][2002];

int get_odd_sum() {
	return odd[y][yy] + odd[x - 1][xx - 1] - odd[y][xx - 1] - odd[x - 1][yy];
}

int get_pos_sum() {
	return pos[y][yy] + pos[x - 1][xx - 1] - pos[y][xx - 1] - pos[x - 1][yy];
}

void solve() {
	cin >> n >> m >> k;
	char ch;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			odd[i][j] = ((i + j) % 2 ? ch == 'B' : ch == 'W');
			odd[i][j] += (odd[i - 1][j] + odd[i][j - 1] - odd[i - 1][j - 1]);
			pos[i][j] = ((i + j) % 2 ? ch == 'W' : ch == 'B');
			pos[i][j] += (pos[i - 1][j] + pos[i][j - 1] - pos[i - 1][j - 1]);
		}
	}

	x = xx = 1;
	y = yy = k;

	while (y <= n) {
		xx = 1; yy = k;
		while (yy <= m) {
			answer = min(answer, get_odd_sum());
			answer = min(answer, get_pos_sum());
			++xx; ++yy;
		}
		++x; ++y;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
