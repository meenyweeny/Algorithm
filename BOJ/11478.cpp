#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

unordered_set<string> s;

void solve() {
	string str;
	cin >> str;
	string sub;
	int length = str.length();
	for (int i = 1; i <= length; i++) {
		int start = 0;
		int end = start + i-1;
		while (end < length) {
			sub = str.substr(start, end - start + 1);
			s.insert(sub);
			++start;
			++end;
		}
	}
	cout << s.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
