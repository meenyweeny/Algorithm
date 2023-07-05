#include<iostream>
#include<deque>
using namespace std;

int n, answer;
deque<pair<int, int>> dq;

void solve() {
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a) {
			cin >> b >> c;
			dq.push_front({ b,c-1 });
		} else {
			if (dq.empty()) {
				continue;
			}
			--dq.front().second;
 		}
		if (dq.front().second==0) {
			answer += dq.front().first;
			dq.pop_front();
		}
	}

	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
