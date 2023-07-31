#include<iostream>
#include<set>
using namespace std;

int n, m, k;

void solve() {
	cin >> n;
	set<int> s;
	while (n--) {
		cin >> k;
		s.insert(k);
	}
	cin >> m;
	while (m--) {
		cin >> k;
		cout << ((s.insert(k).second) ? 0 : 1) << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
