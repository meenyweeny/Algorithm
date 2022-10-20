#include <iostream>
using namespace std;

int answer;
int n;
bool is_prime[100001];

void fill_map() {
	is_prime[1] = true;
	is_prime[2] = false;
	for(int i=2; i<=1000; i++) {
		int k=i*2;
		while(k<=100000) {
			is_prime[k] = true;
			k+=i;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	fill_map();
	cin>>n;
	int k;
	for(int i=1; i<=n; i++) {
		cin>>k;
		if(!is_prime[i]) {
			answer += k;
		}
	}
	cout<<answer;
}
