#include <iostream>
using namespace std;

int n;
string s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	cin>>s;
	char before = s[0];
	int count = 1;
	for(int i=1; i<s.length(); i++) {
		if(before!=s[i]) {
			before = s[i];
			++count;
		}
	}
	cout<<count;
}
