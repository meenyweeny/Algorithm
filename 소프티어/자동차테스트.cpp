#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,q;
vector<int> car;

void solve() {
  cin>>n>>q;
  int a;
  for(int i=0; i<n; i++) {
    cin>>a;
    car.push_back(a);
  }
  sort(car.begin(), car.end());
  while(q--) {
    cin>>a;
    int index = lower_bound(car.begin(), car.end(), a) - car.begin();
    if(index==0 || index>=car.size() || car[index]!=a) {
      cout<<0<<'\n';
    } else {
      cout<<(car.size()-1-index) * index<<'\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
