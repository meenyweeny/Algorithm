#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
int k;

int main() {
	for(int i=0; i<4; i++) {
		cin>>k;
		v.push_back(k);
	}
	
	sort(v.begin(), v.end());
	cout<< abs(v[0]-v[3]) + abs(v[1]-v[2]);
}
