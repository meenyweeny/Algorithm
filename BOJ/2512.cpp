#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e4;
int n, m, total, answer;
int budget[sz];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> budget[i];
		total += budget[i];
	}
	cin >> m;
}

void solution() {
	sort(budget, budget + n);
	if (m >= total) {
		answer =  budget[n - 1];
		return;
	}
	int start = 1;
	int end = budget[n - 1];
	int sum = 0;
	while (start <= end) {
		sum = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (mid >= budget[i]) {
				sum += budget[i];
			} else {
				sum += mid;
			}
		}
		if (sum == m) {
			answer = mid;
			break;
		} else if (sum < m) {
			start = mid + 1;
			answer = max(mid, answer);
		} else {
			end = mid - 1;
		}
	}
}

void solve() {
	input();
	solution();
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
