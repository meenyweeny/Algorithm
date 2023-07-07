#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;

int n, word;
bool is_possible = true;
queue<string> bird[101];
queue<string> sentence;

void solve() {
	cin >> n;
	cin.ignore();
	string str, tmp;
	for (int i = 1; i <= n; i++) {
		getline(cin,str);
		stringstream ss(str);
		string tmp;
		while (ss>>tmp) {
			bird[i].push(tmp);
			++word;
		}
	}
	getline(cin, str);
	stringstream ss(str);
	while (ss >> tmp) {
		sentence.push(tmp);
	}
	if (sentence.size() != word) {
		is_possible = false;
	}
	if (is_possible) {
		bool flag = false;
		while (!sentence.empty()) {
			flag = false;
			for (int i = 1; i <= n; i++) {
				if (bird[i].empty()) {
					continue;
				}
				if (bird[i].front() == sentence.front()) {
					bird[i].pop();
					sentence.pop();
					flag = true;
					break;
				}
			}
			if (!flag) {
				is_possible = false;
				break;
			}
		}
	}
	cout << (is_possible ? "Possible" : "Impossible");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
