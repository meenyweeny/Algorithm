#include<iostream>
#include<algorithm>
using namespace std;

const int sz = 1e6;
int n, m;
int arr[sz];

bool isValid(int height) {
	unsigned long long answer = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - height < 0) {
			continue;
		}
		answer += (arr[i] - height);
	}
	return answer >= m;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int max_idx, min_idx;
	min_idx = 0;
	max_idx = arr[n - 1];
	int answer = -1;
	
	while (min_idx <= max_idx) {
		int mid_idx = (max_idx + min_idx) / 2;
		if (!isValid(mid_idx)) {
			max_idx = mid_idx-1;
		} else {
			min_idx = mid_idx+1;
			answer = max(answer, mid_idx);
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
