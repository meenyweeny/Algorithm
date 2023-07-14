#include<iostream>
#include<cmath>
using namespace std;

const int sz = 123456 + 1;
int n, answer;
bool prime[sz << 1];

void init() {
	int range = sqrt(sz<<1);
	prime[1] = true;
	for (int i = 2; i <= range; i++) {
		for (int j = 2; j*i <= (sz * 2); j++) {
			prime[i*j] = true;
		}
	}
}

void solution() {
	answer = 0;
	for (int i = n+1; i <= 2 * n; i++) {
		answer += (!prime[i]);
	}
	cout << answer << '\n';
}

void solve() {
	init();
	cin >> n;
	while (n != 0) {
		solution();
		cin >> n;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
