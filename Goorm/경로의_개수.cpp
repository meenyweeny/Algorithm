#include <iostream>
using namespace std;

int n, k;

int main() {
	cin>>n;
	unsigned long long answer = 1;
	while(n--) {
		cin>>k;
		answer *= k;
	}
	cout<<answer;
}
