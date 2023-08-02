#include <string>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<int, int> mx;
map<int, int> my;
int cnt[10];
using namespace std;

string solution(string x, string y) {
    string s = "";
	for (auto q : x) {
		++mx[q - '0'];
	}
	for (auto q : y) {
		++my[q - '0'];
	}
	for (int i = 9; i > 0; i--) {
		int count = min(mx[i], my[i]);
		for (int j = 0; j < count; j++) {
			s += to_string(i);
		}
	}
	int count = min(mx[0], my[0]);
	if (s == "" && count > 0) {
		s = "0";
	} else {
		for (int j = 0; j < count; j++) {
			s += "0";
		}
	}
	if (s == "") {
		s = "-1";
	}
    return s;
}
