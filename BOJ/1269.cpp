#include<iostream>
#include<map>
using namespace std;

int a, b;
map<int, int> m;

void solve() {
	cin >> a >> b;
	int k;
	int afull, bfull;
	afull = bfull = 0;
	for (int i = 1; i <= a; i++) {
		cin >> k;
		m[k] = i;
	}
	afull = m.size();
	for (int i = 1; i <= b; i++) {
		cin >> k;
		if (m[k] != 0) {
			--afull;
			continue;
		}
		++bfull;
		m[k] = i;
	}
	cout << afull + bfull;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
