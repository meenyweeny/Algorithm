#include<iostream>
using namespace std;

const int sz = 1e6 + 1;
int n, m, k;
long long tree[sz << 2];
int height;

void get_height() {
	height = 2;
	while (height <= n) {
		height *= 2;
	}
}

void build() {
	for (int i = height - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

void update(int index, long long value) {
	index += height;
	--index;
	long long gap = tree[index] - value;
	while (index > 0) {
		tree[index] -= gap;
		index /= 2;
	}
}

long long query(int start, int end) {
	start += height;
	end += height;
	--start;
	--end;
	long long sum = 0;
	while(start <= end) {
		if (start % 2) {
			sum += tree[start];
			++start;
		}
		if (!(end % 2)) {
			sum += tree[end];
			--end;
		}
		start /= 2;
		end /= 2;
	}
	return sum;
}

void input() {
	cin >> n >> m >> k;
	get_height();
	for (int i = 0; i < n; i++) {
		cin >> tree[i + height];
	}
}

void solve() {
	input();
	build();
	long long a, b, c;
	m += k;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		} else {
			cout << query(b, c) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
