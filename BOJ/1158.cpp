#include<iostream>
#include<deque>
using namespace std;

int n, k;
deque<int> dq;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	cout << '<';
	while (dq.size() > 1) {
		for (int i = 1; i < k; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front() << ", ";
		dq.pop_front();
	}
	cout << dq.front() << '>';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
