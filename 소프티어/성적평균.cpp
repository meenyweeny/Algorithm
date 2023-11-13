#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const int sz = 1e6 + 1;
int n, k;
int arr[sz];

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
}

void solve() {
	input();
	int s, e;
	while (k--) {
		cin >> s >> e;
		--s;
		int sum = arr[e] - arr[s];
		int num = e - s;
		double aver = double(sum) / (double)num;
		aver *= 100;
		aver = round(aver);
		aver /= 100;
		cout << aver << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}
