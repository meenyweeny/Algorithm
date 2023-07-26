#include<iostream>
using namespace std;

const int sz = 1e5 + 1;
int n, m, unit;
int tree[sz << 2];

void get_unit() {
	unit = 2;
	while (unit <= n) {
		unit *= 2;
	}
}

void build() {
	for (int i = unit - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

void update(int index, int value) {
	index += unit; --index;
	bool odd = value % 2;
	bool origin = tree[index];
	if (origin != odd) {
		return;
	}
	while (index > 0) {
		tree[index] += origin ? -1 : 1;
		index /= 2;
	}
}

int get_num(bool odd, int start, int end) {
	int range = end - start + 1;
	start += unit; end += unit; --start; --end;
	int ret = 0;
	while (start <= end) {
		if (start % 2) {
			ret += tree[start];
			++start;
		}
		if (!(end % 2)) {
			ret += tree[end];
			--end;
		}
		start /= 2; end /= 2;
	}
	return odd ? (range - ret) : ret;
}

void input() {
	cin >> n;
	get_unit();
	for (int i = 0; i < n; i++) {
		cin >> tree[i + unit];
		tree[i + unit] = !(tree[i + unit] % 2);
	}
}

void solution() {
	build();
	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		} else {
			cout << get_num(a == 3, b, c) << '\n';
		}
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
