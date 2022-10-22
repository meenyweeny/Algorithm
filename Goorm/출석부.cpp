#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,k;
vector<pair<string,double>> v;
string name;
double height;

bool comp(pair<string,double> a, pair<string,double> b) {
	if(a.first!=b.first) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>name>>height;
		v.push_back({name, height});
	}
	
	sort(v.begin(), v.end(), comp);
	
	setprecision(2);
	cout<<v[k-1].first<<" "<<fixed<<setprecision(2)<<v[k-1].second;
}
