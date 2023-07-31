#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[200001][26];

void solve() {
	string s;
	int q;
	cin >> s;
	arr[1][s[0] - 'a'] = 1;
	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			arr[i+1][j] += arr[i][j];
		}
		++arr[i+1][s[i] - 'a'];
	}
	cin >> q;
	int start, end;
	char ch;
	while (q--) {
		cin >> ch;
		cin >> start >> end;
		cout << arr[end+1][ch - 'a'] - arr[start][ch - 'a'] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
