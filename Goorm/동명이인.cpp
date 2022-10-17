#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> students;
string name, tmp;

int main() {
	cin>>n;
	cin>>name;
	while(n--) {
		cin>>tmp;
		students.push_back(tmp);
	}
	
	int answer = 0;
	for(auto i:students) {
		if(i.find(name) != string::npos) {
			++answer;
		}
	}
	cout<<answer;
}
