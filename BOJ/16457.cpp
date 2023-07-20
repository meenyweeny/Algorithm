#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k, limit, answer = -1;
int now;
int skill[100][10];
bool skills[21];

void process(int count,int start) {
	if (count == n) {
		bool flag;
		int comp = 0;
		for (int i = 0; i < m; i++) {
			flag = true;
			for (int j = 0; j < k; j++) {
				flag &= skills[skill[i][j]];
			}
			comp += flag;
		}
		answer = max(answer, comp);
		return;
	}
	for (int i = start; i <= limit; i++) {
		if (skills[i]) {
			continue;
		}
		skills[i] = true;
		process(count + 1, i + 1);
		skills[i] = false;
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> skill[i][j];
		}
	}
	limit = 2 * n;
	process(0, 1);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
