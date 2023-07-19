#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e5;
int n, s, answer = 1e9;
int arr[sz];

void solve() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int now, length, front, end;
	length = front = end = 1;
	while (front <= n && end <= n) {
		now = arr[end] - arr[front - 1];
		if (now < s) {
			++end;
		} else {
			answer = min(answer, end - front + 1);
			++front;
		}
	}
	if (answer > sz) {
		answer = 0;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
