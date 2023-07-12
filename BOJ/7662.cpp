#include<iostream>
#include<queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxq;
int cnt = 0;
const int sz = 1e6 + 1;
bool deleted[sz];

void init() {
	while (!minq.empty()) {
		minq.pop();
	}
	while (!maxq.empty()) {
		maxq.pop();
	}
	cnt = 0;
}

void sync_min() {
	while (!minq.empty()) {
		if (!deleted[minq.top().second]) {
			break;
		}
		minq.pop();
	}
}

void sync_max() {
	while (!maxq.empty()) {
		if (!deleted[maxq.top().second]) {
			break;
		}
		maxq.pop();
	}
}

void pop_min() {;
	deleted[minq.top().second] = true;
	minq.pop();
	--cnt;
}

void pop_max() {
	deleted[maxq.top().second] = true;
	maxq.pop();
	--cnt;
}

void insert(int x,int index) {
	minq.push({ x,index });
	maxq.push({ x,index });
	++cnt;
}

void print() {
	if (!cnt) {
		cout << "EMPTY";
	} else {
		sync_max();
		sync_min();
		cout << maxq.top().first << ' ' << minq.top().first;
	}
	cout << '\n';
}

void solve() {
	int t, k, n;
	char c;
	cin >> t;
	while (t--) {
		fill(deleted, deleted + sz, false);
		init();
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> c >> n;
			if (c == 'I') {
				insert(n,i);
			} else {
				if (!cnt) {
					continue;
				}
				n > 0 ? sync_max() : sync_min();
				n>0 ? pop_max() : pop_min();
			}
			if (!cnt) {
				init();
			}
		}
		print();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
