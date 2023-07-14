#include<iostream>
using namespace std;

int n;
bool prime[10001];

void init() {
	prime[1] = true;
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; i*j <= 10000; j++) {
			prime[i*j] = true;
		}
	}
}

pair<int, int> get_partition() {
	for (int i = n / 2; i >= 2; i--) {
		if (!(prime[i] || prime[n - i])) {
			return { i,n - i };
		}
	}
}

void solve() {
	int t;
	cin >> t;
	init();
	pair<int, int> answer;
	while (t--) {
		cin >> n;
		answer = get_partition();
		cout << answer.first << ' ' << answer.second << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
