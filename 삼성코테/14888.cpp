#include<iostream>
#include<algorithm>
using namespace std;

int n, maxanswer = -2e9, minanswer = 2e9;
int arr[11];
int oper[4];

int mul(int a, int b) {
	return a * b;
}

int sub(int a, int b) {
	return a - b;
}

int add(int a, int b) {
	return a + b;
}

int divi(int a, int b) {
	return a / b;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
}

void solution(int* op, int sum, int index) {
	if (index == n) {
		maxanswer = max(maxanswer, sum);
		minanswer = min(minanswer, sum);
		return;
	}
	int num = arr[index];
	++index;
	for (int i = 0; i < 4; i++) {
		if (!op[i]) {
			continue;
		}
		--op[i];
		if (i == 0) {
			solution(op, add(sum, num), index);
		} else if (i == 1) {
			solution(op, sub(sum, num), index);
		} else if (i == 2) {
			solution(op, mul(sum, num), index);
		} else {
			solution(op, divi(sum, num), index);
		}
		++op[i];
	}
}

void solve() {
	input();
	solution(oper, arr[0],  1);
	cout << maxanswer << '\n' << minanswer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
