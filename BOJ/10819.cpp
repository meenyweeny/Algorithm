#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n, gap = -2e9;
int arr[8];
bool visited[8];

void process(int count, int now[8]) {
	if (count == n) {
		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			sum += abs(now[i] - now[i + 1]);
		}
		gap = max(gap, sum);
        return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		now[count] = arr[i];
		process(count + 1, now);
		visited[i] = false;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tmp[8] = { 0, };
	process(0, tmp);
	cout << gap;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
