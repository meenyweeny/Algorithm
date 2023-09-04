#include<iostream>
#include<string>
using namespace std;

int n;
string str;

void solve() {
	cin >> n;
	cin >> str;
	string s;
	--n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != s[i]) {
				str[i] = '?';
			}
		}
	}
	cout << str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
