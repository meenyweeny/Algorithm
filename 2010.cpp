#include<iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int answer = 0;
	int k;
	for (int i = 1; i < n; i++) {
		cin >> k;
		--k;
		answer += k;
	}
	cin >> k;
	answer += k;
	cout << answer;
}
