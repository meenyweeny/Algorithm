#include<iostream>
#include<map>
#include<string>
using namespace std;

int n, m;
map<string, int> alp;
string poket[100001];

void solve() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		alp[s] = i;
		poket[i] = s;
	}
	while (m--) {
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') {
			cout << alp[s] << '\n';
		} else {
			cout << poket[stoi(s)] << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
