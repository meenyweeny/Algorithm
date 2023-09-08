#include<iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char ch;
	int answer = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ch;
			if (!((i + j)%2)) {
				answer += ch == 'F';
			}
		}
	}
	cout << answer;
}
