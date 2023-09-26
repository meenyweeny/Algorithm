#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int sz = 1e6;
int n;
int arr[sz];
vector<int> lis;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > lis.back()) {
			lis.push_back(arr[i]);
		} else {
			int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[index] = arr[i];
		}
	}

	cout << lis.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
