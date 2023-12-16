#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w,n;
vector<pair<int,int>> mat;

void solve() {
  cin>>w>>n;
  int m,p;
  while(n--) {
    cin>>m>>p;
    mat.push_back({p,m});
  }
  sort(mat.begin(), mat.end());
  reverse(mat.begin(), mat.end());
  int index = 0;
  int answer = 0;
  while(1) {
    int weight = mat[index].second;
    int price = mat[index].first;
    if(w>=weight) {
      answer += (weight*price);
      w-=weight;
      ++index;
    } else {
      answer += (w*price);
      w = 0;
    }
    if(w==0) {
      break;
    }
    if(index==mat.size()) {
      break;
    }
  }
  cout<<answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}
