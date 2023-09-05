#include<iostream>
#include<string>
using namespace std;

unsigned long long k;
int n, f;

void solve() {
	cin >> n;
	cin >> f;

	n -= n % 100;
	while (1) {
		if (n%f == 0) {
			break;
		}
		n += 1;
	}
	string answer = to_string(n);
	if (answer.length() < 2) {
		answer += "0";
		reverse(answer.begin(), answer.end());
	}
	cout << answer[answer.length() - 2] << answer[answer.length() - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
