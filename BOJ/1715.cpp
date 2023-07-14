#include<iostream>
#include<queue>
using namespace std;

const int sz = 1e5 + 1;
int n, answer;
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		pq.push(k);
	}
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += a;
		answer += b;
		if (pq.empty()) {
			break;
		}
		else {

			pq.push(a + b);
		}
	}
	cout << answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
